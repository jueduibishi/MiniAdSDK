#!/bin/bash

# 检查是否提供了版本号参数
if [ -z "$1" ]; then
  echo "❌ 错误：未提供版本号！"
  echo "用法: bash $0 <版本号> [提交信息]"
  echo "示例: bash $0 0.7.805 \"chore: revert version 0.7.805\""
  exit 1
fi

VERSION="$1"
COMMIT_MSG="${2:-}"  # 可选的第二个参数：提交信息

echo "🚀 开始清理版本: $VERSION"
echo "----------------------------------------"

# 检查依赖命令
command -v git >/dev/null 2>&1 || { echo "❌ 错误：未找到 git 命令，请先安装。"; exit 1; }
command -v gh >/dev/null 2>&1 || { echo "❌ 错误：未找到 gh 命令，请先安装并登录。"; exit 1; }

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

# 3. 尝试再次确保远程 Tag 被删除
echo "🔄 尝试同步清理远程 Tag（若 gh 未完全清理）..."
git push origin --delete "$VERSION" 2>/dev/null
if [ $? -eq 0 ]; then
  echo "✅ 远程 Tag 已通过 git 再次删除。"
else
  echo "ℹ️  远程 Tag 已不存在或无需额外处理。"
fi

echo "----------------------------------------"

# 4. 新增：Git 提交与推送功能
echo "📦 检查 Git 工作区状态..."

# 获取当前分支名
CURRENT_BRANCH=$(git symbolic-ref --short HEAD 2>/dev/null)
if [ -z "$CURRENT_BRANCH" ]; then
  echo "⚠️  警告：无法获取当前分支名（可能处于分离头指针状态），跳过 Git 提交与推送。"
else
  echo "📍 当前分支: $CURRENT_BRANCH"
  
  # 检查是否有未提交的更改（已修改、已暂存、未跟踪）
  if ! git diff --quiet || ! git diff --cached --quiet || [ -n "$(git ls-files --others --exclude-standard)" ]; then
    echo "📝 检测到未提交的更改。"
    
    if [ -n "$COMMIT_MSG" ]; then
      # 如果运行脚本时提供了提交信息，直接提交
      echo "💬 使用提供的提交信息: $COMMIT_MSG"
      git add -A
      if git commit -m "$COMMIT_MSG"; then
        echo "✅ 更改已提交。"
      else
        echo "❌ 提交失败，请手动检查。"
      fi
    else
      # 未提供提交信息，询问用户是否交互式提交
      echo "💡 提示：您可以重新运行脚本并提供提交信息参数，例如："
      echo "   bash $0 $VERSION \"chore: clean up after unrelease $VERSION\""
      read -p "是否立即提交所有更改并推送到 $CURRENT_BRANCH? (y/N) " -n 1 -r
      echo
      if [[ $REPLY =~ ^[Yy]$ ]]; then
        read -p "请输入提交信息: " USER_COMMIT_MSG
        if [ -z "$USER_COMMIT_MSG" ]; then
          USER_COMMIT_MSG="chore: clean up after unrelease $VERSION"
        fi
        git add -A
        git commit -m "$USER_COMMIT_MSG"
      else
        echo "ℹ️  已跳过提交，更改仍保留在工作区。"
      fi
    fi
    
    # 推送分支（无论是否刚刚提交，都尝试推送）
    echo "🚀 正在推送分支 $CURRENT_BRANCH 到远程..."
    if git push origin "$CURRENT_BRANCH"; then
      echo "✅ 分支已成功推送到远程。"
    else
      echo "❌ 推送失败，请手动检查（可能需要先 pull 或处理冲突）。"
    fi
  else
    echo "✨ 工作区干净，无需提交。"
    # 即使工作区干净，也尝试推送（以防有本地已提交但未推送的 commits）
    echo "🚀 尝试推送当前分支 $CURRENT_BRANCH..."
    if git push origin "$CURRENT_BRANCH" 2>/dev/null; then
      echo "✅ 推送成功（可能有未推送的 commits 已被推送）。"
    else
      echo "ℹ️  无需推送或推送失败（可能无远程分支或权限问题）。"
    fi
  fi
fi

echo "----------------------------------------"
echo "🎉 版本 $VERSION 的清理及 Git 同步操作执行完毕！"