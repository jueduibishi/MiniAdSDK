#!/bin/bash
set -eo pipefail


SDK_NAME="MiniSDKFramework"

# ---------------- 参数 ----------------
if [ -z "${1:-}" ]; then
    echo -e "\033[31m❌ 错误：请指定版本号！\033[0m"
    echo -e "\033[33m用法: bash release.sh <版本号>\033[0m"
    echo -e "\033[33m示例: bash release.sh 0.7.807\033[0m"
    exit 1
fi
VERSION="$1"

ZIP_PATH="sdk/$SDK_NAME.xcframework.zip"
TIMEOUT() { perl -e 'alarm shift; exec @ARGV' "$@"; }

info()  { echo -e "\033[32m✅ $1\033[0m"; }
warn()  { echo -e "\033[33m⚠️  $1\033[0m"; }
error() { echo -e "\033[31m❌ $1\033[0m"; exit 1; }

# 兜底：脚本任一处失败时，提示不要盲目重跑
trap 'RC=$?; if [ $RC -ne 0 ]; then echo -e "\033[31m💥 脚本异常退出，请先 git status 确认状态再重跑\033[0m"; fi' EXIT

# ---------------- 1. 打包 xcframework ----------------
echo -e "\033[33m📦 1/9 打包 xcframework...\033[0m"
mkdir -p sdk
[ -d "sdk/$SDK_NAME.xcframework" ] || error "sdk/$SDK_NAME.xcframework 不存在，请先编译出 xcframework"

cd sdk
ditto -c -k --keepParent "$SDK_NAME.xcframework" "$SDK_NAME.xcframework.zip"
cd ..
info "已打包: $ZIP_PATH"

# ---------------- 2. 验证 zip 内部结构 ----------------
echo -e "\033[33m🔍 2/9 验证 zip 内部结构...\033[0m"
TIMEOUT 60 unzip -Z -1 "$ZIP_PATH" | head -n 20 || error "读取 zip 目录超时/失败"
FIRST_ENTRY=$(TIMEOUT 10 unzip -Z -1 "$ZIP_PATH" | head -n 1)
EXPECTED="$SDK_NAME.xcframework/"
[ "$FIRST_ENTRY" = "$EXPECTED" ] || error "校验失败！期望根目录 $EXPECTED，实际: $FIRST_ENTRY"
info "校验通过：xcframework 位于 zip 根目录"

# ---------------- 3. 计算 checksum ----------------
echo -e "\033[33m🔐 3/9 计算 checksum...\033[0m"
CHECKSUM=$(swift package compute-checksum "$ZIP_PATH")
[ -n "$CHECKSUM" ] || error "checksum 计算失败"
info "Checksum: $CHECKSUM"

# ---------------- 4. 解析仓库并上传 GitHub Release ----------------
echo -e "\033[33m📤 4/9 上传到 GitHub Releases...\033[0m"
ORIGIN_URL=$(git remote get-url origin 2>/dev/null || true)

if [ -z "${GITHUB_REPO:-}" ] && [ -n "$ORIGIN_URL" ] && [[ "$ORIGIN_URL" == *"github.com"* ]]; then
    GITHUB_REPO=$(echo "$ORIGIN_URL" | sed -E 's#.*github\.com[:/]##; s#\.git$##')
fi
[ -n "${GITHUB_REPO:-}" ] || error "无法解析 owner/repo，请 export GITHUB_REPO=owner/repo"

command -v gh >/dev/null 2>&1 || error "未找到 gh，请先: brew install gh"
gh auth status >/dev/null 2>&1 || error "gh 未登录，请先: gh auth login"

RELEASE_URL="https://github.com/$GITHUB_REPO/releases/download/$VERSION/$SDK_NAME.xcframework.zip"
info "目标仓库  : $GITHUB_REPO"
info "Release URL: $RELEASE_URL"

if gh release view "$VERSION" --repo "$GITHUB_REPO" >/dev/null 2>&1; then
    warn "Release $VERSION 已存在，覆盖 asset（幂等重跑）..."
    gh release upload "$VERSION" "$ZIP_PATH" --repo "$GITHUB_REPO" --clobber
else
    gh release create "$VERSION" "$ZIP_PATH" \
        --repo "$GITHUB_REPO" \
        --title "Release $VERSION" \
        --notes "Automated release for $SDK_NAME version $VERSION"
fi
info "Release 上传完成"

# ---------------- 5. 生成 Package.swift + 自检 ----------------
echo -e "\033[33m📝 5/9 生成 Package.swift...\033[0m"
cat > Package.swift <<EOF
// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "$SDK_NAME",
    platforms: [.iOS(.v13)],
    products: [
        .library(name: "$SDK_NAME", targets: ["$SDK_NAME"])
    ],
    targets: [
        .binaryTarget(
            name: "$SDK_NAME",
            url: "$RELEASE_URL",
            checksum: "$CHECKSUM"
        )
    ]
)
EOF

# ★ 关键自检：文件里必须含本次版本号，防止生成错/残留旧文件还继续跑
grep -qF "$VERSION" Package.swift || error "自检失败：Package.swift 中未找到版本号 $VERSION"
info "Package.swift 已生成并通过版本自检"

# ---------------- 6. SwiftPM 解析测试 ----------------
echo -e "\033[33m🧪 6/9 SwiftPM 解析测试（真实下载并校验 checksum）...\033[0m"
rm -rf .build
TIMEOUT 180 swift package resolve || error "SPM 解析失败！检查 URL 可达性与 checksum"
info "SPM 解析测试通过"

# ---------------- 7. 提交 Package.swift 并打 Tag（防漂移核心） ----------------
echo -e "\033[33m📋 7/9 提交 Package.swift 并打 Tag...\033[0m"
git add Package.swift

# 判断「暂存区里的 Package.swift」是否已经等价于「当前 HEAD 里的」
if git diff --cached --quiet 2>/dev/null; then
    # 内容没变：正确内容已经在 HEAD 里了（上次跑过且 commit 成功）
    warn "Package.swift 相对 HEAD 无变化，复用当前 HEAD：$(git rev-parse --short HEAD)"
    # 保险：万一 HEAD 里其实是旧版本（极端中断场景），兜底产一个空 commit 供 Tag 落脚
    if ! grep -qF "$VERSION" <(git show HEAD:Package.swift 2>/dev/null || true); then
        warn "HEAD 中的 Package.swift 不是 $VERSION，创建空提交以承载本次变更"
        git commit --allow-empty -m "Release $VERSION (carry Package.swift for SPM)"
    fi
else
    # 有差异，正常提交
    git commit -m "Release $VERSION (SPM - url + checksum)"
fi

# Tag 永远删掉重建，打在「现在这个一定含正确 Package.swift 的 HEAD」上
git tag -d "$VERSION" 2>/dev/null || true
git tag "$VERSION"
info "Tag $VERSION → $(git rev-parse --short HEAD)  $(git show -s --format=%s HEAD)"

# ★★ 二次硬自检：这个 Tag 指的那个文件，版本号必须对
grep -qF "$VERSION" <(git show "$VERSION":Package.swift) || error "致命：Tag $VERSION 指向的 Package.swift 版本自检失败，已终止，未推送"

# ---------------- 8. 推送分支 + Tag（串行重试，全成功才算数） ----------------
echo -e "\033[33m🚀 8/9 推送分支与 Tag...\033[0m"
CURRENT_BRANCH=$(git branch --show-current)
[ -n "$CURRENT_BRANCH" ] || error "当前不在任何分支上，无法推送"

MAX_ATTEMPTS=5
PUSH_OK=false
for ((try=1; try<=MAX_ATTEMPTS; try++)); do
    echo "  [尝试 $try/$MAX_ATTEMPTS] 推送分支 $CURRENT_BRANCH ..."
    TIMEOUT 120 git push origin "$CURRENT_BRANCH" || { warn "分支推送失败，5s 后重试"; sleep 5; continue; }

    echo "  [尝试 $try/$MAX_ATTEMPTS] 推送 Tag $VERSION ..."
    TIMEOUT 120 git push origin "$VERSION" --force || { warn "Tag 推送失败，5s 后重试"; sleep 5; continue; }

    PUSH_OK=true
    info "推送成功（分支 + Tag）"
    break
done
$PUSH_OK || error "推送失败！本地 Tag $VERSION 已就绪，请稍后手动：git push origin $CURRENT_BRANCH && git push origin $VERSION --force"

# ---------------- 9. 清理 ----------------
echo -e "\033[33m🧹 9/9 清理 .build...\033[0m"
rm -rf .build
info "已清理 .build"

echo ""
echo "🎉 发版完成！版本: $VERSION"
echo "   Tag : $VERSION → $(git rev-parse --short HEAD)"
echo "   URL : $RELEASE_URL"
echo "   用户可在自己项目里 swift package update 拉到新版本"
