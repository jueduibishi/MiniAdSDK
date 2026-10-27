#!/usr/bin/env bash
REPO="jueduibishi/MiniAdSDK"

echo "📦 最近发布的版本："
gh release list --repo "$REPO" --limit 5

echo ""
echo "🏷️  所有 tag（前 10）："
gh api repos/$REPO/tags --jq '.[].name' | head -10

echo ""
echo "🔍 最新版资产检查："
LATEST=$(gh release list --repo "$REPO" --json tagName,isLatest --jq '.[] | select(.isLatest) | .tagName')
gh release view "$LATEST" --repo "$REPO" \
  --json tagName,assets --jq '{tag: .tagName, files: [.assets[].name]}'