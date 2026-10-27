#!/bin/bash

# ==================== 配置区 ====================
REPO_URL="https://github.com/jueduibishi/MiniAdSDK"
SDK_NAME="MiniSDKFramework"
# ===============================================

set -euo pipefail

# ---------- 参数校验 ----------
if [ -z "$1" ]; then
    echo "❌ 错误: 请提供版本号，例如: ./release.sh 0.7.805"
    exit 1
fi
VERSION=$1
ZIP_NAME="${SDK_NAME}.xcframework.zip"
ZIP_PATH="sdk/$ZIP_NAME"

CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
echo "🚀 开始发版: $VERSION (分支: $CURRENT_BRANCH)"

# ---------- 0. 确保 .gitignore 忽略 zip ----------
if [ -f .gitignore ]; then
    if ! grep -q "sdk/\*.zip" .gitignore && ! grep -q "sdk/*.zip" .gitignore; then
        echo "sdk/*.zip" >> .gitignore
        echo "  ✅ 已追加 sdk/*.zip 到 .gitignore"
    fi
else
    echo "sdk/*.zip" > .gitignore
    echo "  ✅ 已创建 .gitignore 并忽略 sdk/*.zip"
fi

# ---------- 1. 查找 xcframework ----------
echo "🔍 查找 xcframework..."
XCFRAMEWORK_PATH=$(find sdk -name "*.xcframework" -maxdepth 1 | head -n 1)

if [ -z "$XCFRAMEWORK_PATH" ]; then
    echo "❌ 错误: 在 sdk/ 目录下未找到 xcframework!"
    exit 1
fi
echo "  ✅ 找到: $XCFRAMEWORK_PATH"

# ---------- 2. 生成 Zip ----------
echo "📦 打包 xcframework..."
if [ -f "$ZIP_PATH" ]; then rm -f "$ZIP_PATH"; fi

FRAMEWORK_NAME=$(basename "$XCFRAMEWORK_PATH")
(cd sdk && zip -rq "$ZIP_NAME" "$FRAMEWORK_NAME")
echo "  ✅ 已打包: $ZIP_PATH"

# ---------- 3. 计算 Checksum ----------
echo "🔑 计算 Checksum..."
CHECKSUM=$(shasum -a 256 "$ZIP_PATH" | awk '{print $1}')
echo "  ✅ Checksum: $CHECKSUM"

# ---------- 4. 重建 Package.swift ----------
echo "📝 重建 Package.swift..."
DOWNLOAD_URL="${REPO_URL}/releases/download/${VERSION}/${ZIP_NAME}"

rm -f Package.swift

cat > Package.swift <<EOF
// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "$SDK_NAME",
    platforms: [.iOS(.v12)],
    products: [
        .library(
            name: "$SDK_NAME",
            targets: ["$SDK_NAME"])
    ],
    targets: [
        .binaryTarget(
            name: "$SDK_NAME",
            url: "$DOWNLOAD_URL",
            checksum: "$CHECKSUM")
    ]
)
EOF
echo "  ✅ Package.swift 已更新 (URL: $DOWNLOAD_URL)"

# ---------- 5. 提交变更 ----------
echo "📤 准备提交..."
# ← 只提交 Package.swift，zip 不进 git
git add Package.swift

if git diff --cached --quiet; then
    echo "  ℹ️ 没有新文件变更，跳过提交"
else
    git commit -m "Release $VERSION (SPM)"
    echo "  ✅ 代码已提交"
fi

# ---------- 6. 打 Tag ----------
if git rev-parse "refs/tags/$VERSION" >/dev/null 2>&1; then
    echo "  ℹ️ Tag $VERSION 已存在，跳过"
else
    git tag "$VERSION"
    echo "  ✅ 已打 Tag: $VERSION"
fi

# ---------- 7. 带超时和重试的 Git 推送 ----------
echo "🚀 推送代码和 Tag 到 $CURRENT_BRANCH..."

MAX_ATTEMPTS=5
WAIT_TIMES=(2 4 8 16 30)
TIMEOUT_SEC=60

for (( attempt=1; attempt<=MAX_ATTEMPTS; attempt++ )); do
    echo "  [推送尝试 $attempt/$MAX_ATTEMPTS]..."

    set +e
    perl -e 'alarm shift; exec @ARGV' "$TIMEOUT_SEC" git push origin "$CURRENT_BRANCH" --tags
    PUSH_EXIT=$?
    set -e

    if [ $PUSH_EXIT -eq 124 ] || [ $PUSH_EXIT -eq 142 ]; then
        echo "  ⚠️ 推送超时 (${TIMEOUT_SEC}秒)，可能被网络阻塞"
    elif [ $PUSH_EXIT -eq 0 ]; then
        LOCAL_SHA=$(git rev-parse HEAD)
        REMOTE_SHA=$(git ls-remote origin refs/heads/"$CURRENT_BRANCH" 2>/dev/null | awk '{print $1}' || true)

        if [ -n "$REMOTE_SHA" ] && [ "$LOCAL_SHA" = "$REMOTE_SHA" ]; then
            echo "  ✅ 推送成功! (SHA 校验一致)"
            break
        else
            echo "  ⚠️ 推送返回成功但远程 SHA 不一致，可能静默失败"
        fi
    else
        echo "  ⚠️ 推送失败 (退出码: $PUSH_EXIT)"
        git push origin "$CURRENT_BRANCH" --tags 2>&1 | head -n 5 || true
    fi

    if [ "$attempt" -lt "$MAX_ATTEMPTS" ]; then
        SLEEP_TIME=${WAIT_TIMES[$((attempt-1))]}
        echo "  ⏳ ${SLEEP_TIME}秒后重试..."
        sleep "$SLEEP_TIME"
    else
        echo "  ❌ 推送失败次数过多。"
        echo "  💡 建议手动执行: git push origin $CURRENT_BRANCH --tags"
        exit 1
    fi
done

# ---------- 8. GitHub Release（zip 只上传到 Release）----------
echo ""
echo "========================================"
echo "🎉 代码已推送！最后一步：创建 GitHub Release"
echo "========================================"

if command -v gh &> /dev/null; then
    read -p "检测到 gh CLI，是否自动创建 Release 并上传 zip? (y/N): " AUTO_RELEASE </dev/tty
    if [ "$AUTO_RELEASE" = "y" ] || [ "$AUTO_RELEASE" = "Y" ]; then
        gh release create "$VERSION" \
            "$ZIP_PATH" \
            --title "$SDK_NAME $VERSION" \
            --notes "SPM release $VERSION"
        echo "  ✅ GitHub Release 已创建，zip 已上传"
    else
        echo "手动操作: $REPO_URL/releases/new → Tag: $VERSION → 上传 $ZIP_PATH"
    fi
else
    echo "手动创建 GitHub Release："
    echo "  1. 打开 $REPO_URL/releases/new"
    echo "  2. Tag: $VERSION"
    echo "  3. 上传: $ZIP_PATH"
    echo "  4. Publish release"
fi

echo ""
echo "✅ 发版流程全部完成！版本: $VERSION"
echo "   📦 zip 仅存在于本地 sdk/ 和 GitHub Release，未提交到 git 仓库"
