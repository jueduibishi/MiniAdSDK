#!/bin/bash
set -e

# ==========================================
# 基础配置（按需修改）
# ==========================================
SDK_NAME="MiniSDKFramework"  # 你的 SDK 名称，比如 MiniAdSDK

# ---------- 从命令行参数读取版本号 ----------
if [ -z "$1" ]; then
    echo -e "\033[31m❌ 错误：请指定版本号！\033[0m"
    echo -e "\033[33m用法: bash release.sh <版本号>\033[0m"
    echo -e "\033[33m示例: bash release.sh 0.7.805\033[0m"
    exit 1
fi
VERSION="$1"
# -------------------------------------------

ZIP_PATH="sdk/$SDK_NAME.xcframework.zip"

info() { echo -e "\033[32m✅ $1\033[0m"; }
warn() { echo -e "\033[33m⚠️ $1\033[0m"; }
error() { echo -e "\033[31m❌ $1\033[0m"; exit 1; }

# ---------- 1. 打包 xcframework ----------
echo -e "\033[33m📦 打包 xcframework...\033[0m"
mkdir -p sdk

if [ ! -d "sdk/$SDK_NAME.xcframework" ]; then
    error "sdk/$SDK_NAME.xcframework 不存在，请先编译出 xcframework"
fi

cd sdk
ditto -c -k --keepParent "$SDK_NAME.xcframework" "$SDK_NAME.xcframework.zip"
cd ..
info "使用 ditto 打包（保留符号链接）"
info "已打包: $ZIP_PATH"

# ---------- 2. 验证 zip 内部结构（防卡死版） ----------
echo -e "\033[33m🔍 验证 zip 内部结构...\033[0m"
echo "----- unzip -Z -1 真实结构（前 20 行） -----"

perl -e 'alarm shift; exec @ARGV' 10 unzip -Z -1 "$ZIP_PATH" | head -n 20

FIRST_ENTRY=$(perl -e 'alarm shift; exec @ARGV' 10 unzip -Z -1 "$ZIP_PATH" | head -n 1)
EXPECTED="$SDK_NAME.xcframework/"

if [ "$FIRST_ENTRY" == "$EXPECTED" ]; then
    info "校验通过！xcframework 在根目录"
else
    error "校验失败！期望根目录有 $EXPECTED，但实际是: $FIRST_ENTRY"
fi

# ---------- 3. 计算 Checksum ----------
echo -e "\033[33m🔐 计算 zip checksum...\033[0m"
CHECKSUM=$(swift package compute-checksum "$ZIP_PATH")
info "Checksum: $CHECKSUM"

# ---------- 4. 解析 Git Remote 并上传到 GitHub Releases ----------
echo -e "\033[33m📤 准备上传 zip 到 GitHub Releases...\033[0m"

# 获取当前 git origin 地址
ORIGIN_URL=$(git remote get-url origin 2>/dev/null)

# 优先使用环境变量，否则尝试从 origin 解析 (兼容 HTTPS 和 SSH)
if [ -z "$GITHUB_REPO" ] && [ -n "$ORIGIN_URL" ]; then
    if [[ "$ORIGIN_URL" == *"github.com"* ]]; then
        # 使用 sed 稳健提取 owner/repo，兼容 https:// 和 git@ 格式
        GITHUB_REPO=$(echo "$ORIGIN_URL" | sed -E 's#.*github\.com[:/]##; s#\.git$##')
    fi
fi

if [ -z "$GITHUB_REPO" ]; then
    error "无法从 remote URL ($ORIGIN_URL) 解析 owner/repo，请确保 origin 是 GitHub 地址，或手动执行: export GITHUB_REPO=\"owner/repo\""
fi

echo "🎯 目标仓库: $GITHUB_REPO"

# 检查 gh 命令行工具
if ! command -v gh &> /dev/null; then
    error "未找到 GitHub CLI (gh)，请先安装：brew install gh"
fi

# 检查 gh 登录状态
if ! gh auth status &> /dev/null; then
    error "gh 未登录，请先运行: gh auth login"
fi

RELEASE_URL="https://github.com/$GITHUB_REPO/releases/download/$VERSION/$SDK_NAME.xcframework.zip"
info "Release URL: $RELEASE_URL"

# 创建 Release 并上传（如果已存在则直接上传 asset）
if gh release view "$VERSION" --repo "$GITHUB_REPO" &> /dev/null; then
    warn "Release $VERSION 已存在，追加/更新 asset..."
    gh release upload "$VERSION" "$ZIP_PATH" --repo "$GITHUB_REPO" --clobber
else
    info "创建 Release $VERSION 并上传 asset..."
    gh release create "$VERSION" "$ZIP_PATH" \
        --repo "$GITHUB_REPO" \
        --title "Release $VERSION" \
        --notes "Automated release for $SDK_NAME version $VERSION"
fi
info "上传完成 ✅"

# ---------- 5. 生成 Package.swift（url + checksum 方式） ----------
echo -e "\033[33m📝 生成 Package.swift (url + checksum)...\033[0m"
cat > Package.swift <<PROBEEOF
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
PROBEEOF
info "已生成 Package.swift（包名: $SDK_NAME）"

# ---------- 6. SwiftPM 解析测试（真实下载并校验） ----------
echo -e "\033[33m🧪 SwiftPM 解析测试（会真实下载 zip 并校验 checksum）...\033[0m"
echo "----- swift package resolve 输出 -----"
# 清理之前的缓存以确保重新下载
rm -rf .build
if ! perl -e 'alarm shift; exec @ARGV' 120 swift package resolve; then
    error "SPM 解析失败！请检查 URL 是否可达或 checksum 是否正确"
fi
info "SPM 解析测试通过 ✅"

# ---------- 7. Git 提交与打 Tag（不再包含 zip） ----------
echo -e "\033[33m📋 提交 Package.swift...\033[0m"
git add Package.swift

if git diff --cached --quiet; then
    warn "无变更，跳过 commit（Package.swift 内容可能未改变）"
else
    git commit -m "Release $VERSION (SPM - url + checksum)" && info "已提交"
fi

if git rev-parse "refs/tags/$VERSION" >/dev/null 2>&1; then
    warn "Tag $VERSION 已存在，跳过"
else
    git tag "$VERSION" && info "已打 Tag: $VERSION"
fi

# ---------- 8. 推送（带重试 & 失败退出） ----------
echo "🚀 推送代码和 Tag..."
MAX_ATTEMPTS=5
PUSH_SUCCESS=false

for (( attempt=1; attempt<=MAX_ATTEMPTS; attempt++ )); do
    echo "  [尝试 $attempt/$MAX_ATTEMPTS]"
    if perl -e 'alarm shift; exec @ARGV' 120 git push origin HEAD --tags; then
        PUSH_SUCCESS=true
        info "推送成功"
        break
    else
        warn "推送失败，等待重试..."
        sleep 5
    fi
done

if [ "$PUSH_SUCCESS" = false ]; then
    error "推送失败！请手动检查 git 状态并重新推送。"
fi

# ---------- 9. 清理 ----------
echo -e "\033[33m🧹 清理 .build 目录...\033[0m"
rm -rf .build
info "已清理 .build 目录"

echo ""
echo "✅ 发版全部完成！版本: $VERSION"
echo "📦 Package.swift 已通过 Git 提交"
echo "☁️  zip 文件已上传至 GitHub Releases（未提交进 Git）"
echo "🔗 用户可通过 Git Tag 引入你的 SDK"