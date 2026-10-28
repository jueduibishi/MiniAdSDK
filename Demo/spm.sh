#!/bin/bash
set -e
PROXY=socks5h://127.0.0.1:7897
PROJ="$1"

export http_proxy=$PROXY https_proxy=$PROXY ALL_PROXY=$PROXY
export NO_PROXY=localhost,127.0.0.1,::1
git config --global http.proxy $PROXY
git config --global https.proxy $PROXY
defaults write com.apple.dt.Xcode IDEPackageSupportUseBuiltinSCM -bool NO

echo "== 测试 git 连通 =="
git ls-remote https://github.com/apple/swift-nio.git HEAD >/dev/null && echo OK

echo "== 清理缓存 =="
rm -rf ~/Library/Caches/org.swift.swiftpm

echo "== 解析依赖 =="
cd "$PROJ"
xcodebuild -resolvePackageDependencies -disablePackageRepositoryCache
echo "== 完成，请 ⌘Q 退出 Xcode 后重开 =="
