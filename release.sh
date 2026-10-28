#!/bin/bash
set -e

# 基础变量
SDK_NAME="MiniSDKFramework"  #

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

# ---------- 3. 生成正式的 Package.swift（不再临时，永久保留） ----------
echo -e "\033[33m📝 生成 Package.swift...\033[0m"
cat > Package.swift <<PROBEEOF
// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "$SDK_NAME",
    platforms: [.iOS(.v12)],
    products: [
        .library(name: "$SDK_NAME", targets: ["$SDK_NAME"])
    ],
    targets: [
        .binaryTarget(
            name: "$SDK_NAME",
            path: "$ZIP_PATH"
        )
    ]
)
PROBEEOF
info "已生成 Package.swift（包名: $SDK_NAME）"

# ---------- 4. SwiftPM 解析测试（带超时） ----------
echo "----- swift package resolve 输出 -----"
if ! perl -e 'alarm shift; exec @ARGV' 120 swift package resolve; then
    error "SPM 解析失败！上面是 SwiftPM 的真实报错"
fi
info "SPM 解析测试通过 ✅"

# ---------- 5. Git 提交与打 Tag ----------
echo -e "\033[33m📋 提交代码...\033[0m"
git add Package.swift "$ZIP_PATH"

if git diff --cached --quiet; then
    warn "无变更，跳过 commit（Package.swift 和 zip 内容可能未改变）"
else
    git commit -m "Release $VERSION (SPM)" && info "已提交"
fi

if git rev-parse "refs/tags/$VERSION" >/dev/null 2>&1; then
    warn "Tag $VERSION 已存在，跳过"
else
    git tag "$VERSION" && info "已打 Tag: $VERSION"
fi

# ---------- 6. 推送（带重试 & 失败退出） ----------
echo "🚀 推送代码和 Tag..."
MAX_ATTEMPTS=5
PUSH_SUCCESS=false

for (( attempt=1; attempt<=MAX_ATTEMPTS; attempt++ )); do
    echo "  [尝试 $attempt/$MAX_ATTEMPTS]"
    # 超时增加到 120 秒，适配大文件上传
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

# ---------- 7. 清理 SPM 生成的 .build 目录 ----------
echo -e "\033[33m🧹 清理 .build 目录...\033[0m"
rm -rf .build
info "已清理 .build 目录"

echo ""
echo "✅ 发版全部完成！版本: $VERSION"
echo "📦 Package.swift 已保留在仓库中，SPM 可正常解析。"