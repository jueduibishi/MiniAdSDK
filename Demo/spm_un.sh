# 取消git全局代理
git config --global --unset http.proxy
git config --global --unset https.proxy

# 清空当前终端代理环境变量
unset http_proxy https_proxy ALL_PROXY NO_PROXY

# 恢复Xcode内置SCM
defaults write com.apple.dt.Xcode IDEPackageSupportUseBuiltinSCM -bool YES
