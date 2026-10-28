#!/bin/bash

# 检查是否提供了版本号参数
if [ -z "$1" ]; then
  echo "❌ 错误：未提供版本号！"
  echo "用法: bash $0 <版本号>"
  echo "示例: bash $0 0.7.805"
  exit 1
fi

VERSION="$1"

echo "🚀 开始清理版本: $VERSION"
echo "----------------------------------------"

# 1. 删除 GitHub Release 并清理远程 Tag
echo "🗑️  正在删除 GitHub Release ($VERSION) 及其远程 Tag..."
if gh release delete "$VERSION" --cleanup-tag -y; then
  echo "✅ GitHub Release 及远程 Tag 删除成功。"
else
  echo "⚠️  警告：GitHub Release 删除失败（可能该版本不存在、无权限或 gh 未登录）。"
fi

echo "----------------------------------------"

# 2. 删除本地 Tag
echo "🗑️  正在删除本地 Git Tag ($VERSION)..."
if git tag -d "$VERSION"; then
  echo "✅ 本地 Tag 删除成功。"
else
  echo "⚠️  警告：本地 Tag 删除失败（可能本地不存在该 Tag）。"
fi

echo "----------------------------------------"

# 3. （可选）尝试再次确保远程 Tag 被删除，并忽略错误
echo "🔄 尝试同步清理远程 Tag（若 gh 未完全清理）..."
git push origin --delete "$VERSION" 2>/dev/null
if [ $? -eq 0 ]; then
  echo "✅ 远程 Tag 已通过 git 再次删除。"
else
  echo "ℹ️  远程 Tag 已不存在或无需额外处理。"
fi

echo "----------------------------------------"
echo "🎉 版本 $VERSION 的清理操作执行完毕！"