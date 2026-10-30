# 当前0.7.805版本，适配穿山甲7.8.0.5版本。
## iOS最低版本支持说明
0.2.7～0.3.1（包括）版本：最低支持iOS12.0——功能异常，仅可正常编译。iOS13以上功能正常，仅支持真机。<br>0.7.7.0.8~最新版本：最低支持iOS13.0，仅支持真机。
## pod trunk即将停止维护，发布方式转为SPM。
### 过渡版本为0.7.8.0.5和0.7.805，这两个版本一模一样，都是适配穿山甲7.8.0.5。
## 历史更新日志在底部，当前更新日志如下
| 版本历史 | 支持平台 |  功能 | 更新时间 | 
|:--------:|:------------:|:------------:|:------------:|  
| 待更 | 待更 | -- |-- |
| 0.7.805 | 默认支持穿山甲:7.8.0.5 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.90'`<br> 百度:`pod 'BaiduMobAdSDK', '10.050'`<br>  快手:`pod 'KSAdSDK', '5.5.10.1'` | 此版本为过渡版本<br>与0.7.8.0.5功能上一模一样<br>转为SPM方式引入|2026年10月30日 |


# 接入指引
## 通过SPM引入，0.7.805（包含）以后的版本执行
目前支持Xcode27.0以下的开发工具，以Xcode26.6为例，若系统为macOS27.0以上版本，则通过以下代码执行启动
```
#!/bin/zsh
"/Applications/Xcode 26.6.app/Contents/MacOS/Xcode" &

将代码保存为start.sh
终端执行
brew install gh
bash start.sh
```
打开项目工程,菜单栏选择 File → Add Package Dependencies… 搜索框里粘贴 Git 仓库地址，选择版本规则。
```
https://github.com/jueduibishi/MiniAdSDK.git
```
还需要通过pod引入支持库
```
source 'https://github.com/CocoaPods/Specs.git'
pod 'BUTTSDKFramework', '~> 1.48.2.3-premium'
# 以下为支持平台可选配置
pod 'BaiduMobAdSDK', '10.050'
pod 'GDTMobSDK', '4.15.90'
pod 'KSAdSDK', '5.5.10.1'
```
### spm过慢解决方案
若报错，可以清理下缓存，cd到项目文件夹
 ```
 killall Xcode 2>/dev/null
rm -rf ~/Library/Developer/Xcode/DerivedData
rm -rf ~/Library/Caches/org.swift.swiftpm
rm -rf ~/Library/org.swift.swiftpm
find . -name "Package.resolved" -delete
xcodebuild -resolvePackageDependencies -scmProvider system -project xxxx.xcodeproj
open xxxx.xcworkspace

将脚本保存为clean.sh   ——注意,xxxx替换为真实的项目名称

执行 bash clean.sh
 ```
通过设置代理加速网络连接 ，打开系统设置，查看网络-代理-端口号
 
 ```
 #!/bin/bash
set -e
PROXY=socks5h://127.0.0.1:7897  #————7897替换为本机的真实代理端口号
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

将脚本保存为spm.sh

执行 bash spm.sh
 ```
 sdk拉取结束后，还原网络设置
 ```
 # 取消git全局代理
git config --global --unset http.proxy
git config --global --unset https.proxy

# 清空当前终端代理环境变量
unset http_proxy https_proxy ALL_PROXY NO_PROXY

# 恢复Xcode内置SCM
defaults write com.apple.dt.Xcode IDEPackageSupportUseBuiltinSCM -bool YES

将脚本保存为spm_un.sh

执行 bash spm_un.sh
 ```
 
## 通过pod引入，0.7.8.0.5（包含）以前的版本执行
```
#请添加source，否则可能走cdn的配置。
source 'https://github.com/CocoaPods/Specs.git'
pod 'MiniAdSDK'
pod 'BUTTSDKFramework', '~> 1.48.2.3-premium'
# 以下为支持平台可选配置
pod 'BaiduMobAdSDK', '10.050'
pod 'GDTMobSDK', '4.15.90'
pod 'KSAdSDK', '5.5.10.1'
```


# 版本功能特别说明
## 0.3.0版本之后新增初始化时用户信息设定，示例如下
```
    UserConfigModel *userConfig = [[UserConfigModel alloc]init];
    userConfig.uid = @"123456";//此处传入用户的uid
    [SdkManager setUserConfig:userConfig];
```
# 配置

## 1、在项目的Info.plist文件中添加以下字段
```
<dict>
<key>NSAppTransportSecurity</key>
<dict>
<key>NSAllowsArbitraryLoads</key>
<true/>
</dict>
<key>NSPrivacyAccessedAPITypes</key>
<array>
<dict>
<key>NSPrivacyAccessedAPIType</key>
<string>NSPrivacyAccessedAPICategoryFileTimestamp</string>
<key>NSPrivacyAccessedAPITypeReasons</key>
<array>
<string>C617.1</string>
</array>
</dict>
<dict>
<key>NSPrivacyAccessedAPIType</key>
<string>NSPrivacyAccessedAPICategorySystemBootTime</string>
<key>NSPrivacyAccessedAPITypeReasons</key>
<array>
<string>35F9.1</string>
</array>
</dict>
<dict>
<key>NSPrivacyAccessedAPIType</key>
<string>NSPrivacyAccessedAPICategoryDiskSpace</string>
<key>NSPrivacyAccessedAPITypeReasons</key>
<array>
<string>7D9E.1</string>
<string>E174.1</string>
</array>
</dict>
<dict>
<key>NSPrivacyAccessedAPIType</key>
<string>NSPrivacyAccessedAPICategoryUserDefaults</string>
<key>NSPrivacyAccessedAPITypeReasons</key>
<array>
<string>CA92.1</string>
</array>
</dict>
</array>
<key>SKAdNetworkItems</key>
<array>
<dict>
<key>SKAdNetworkIdentifier</key>
<string>238da6jt44.skadnetwork</string>
</dict>
<dict>
<key>SKAdNetworkIdentifier</key>
<string>22mmun2rn5.skadnetwork</string>
</dict>
<dict>
<key>SKAdNetworkIdentifier</key>
<string>cstr6suwn9.skadnetwork</string>
</dict>
</array>
<key>NSUserTrackingUsageDescription</key>
<string>为了提供个性化的广告体验，我们需要您的同意来跟踪您的活动。</string>
</dict>
```
## 2、模拟器支持

由于穿山甲和可选sdk的支持比较混乱，仅部分版本支持模拟器，以实际测试为准，默认仅支持真机。


## 3、其他配置
Targets-build settings - user script sandboxing 设置为NO


# 类型和错误码说明

详情见

[AdErrorCode.h](https://raw.githubusercontent.com/jueduibishi/MiniAdSDK/refs/heads/main/sdk/MiniSDKFramework.framework/Headers/AdErrorCode.h)

# 集成错误若干解决方案
## 报错：真机运行报Unable to install 

方案：选项Demo —— Targets —— Build Phases —— Embed Framworks —— 导入的Pods_Demo.framework,后面的Code Sign On Co...打勾。
## 报错：Sandbox: rsync(18801) deny(1) file-read-data...MiniSDKFramework.framework/_CodeSignature等

方案：Targets-build settings - user script sandboxing 设置为No



# SDK使用说明

## iOS14适配说明
从iOS 14开始，只有在获得用户明确许可的前提下，应用才可以访问用户的IDFA数据并向用户投放定向广告。在应用程序调用 App Tracking Transparency 框架向最终用户提出应用程序跟踪授权请求之前，IDFA将不可用。如果某个应用未提出此请求，则读取到的IDFA将返回全为0的字符串，这个可能会导致广告收入降低。

ATT(App Tracking Transparency), 适用于请求用户权限，访问与应用相关的数据已跟踪用户或设备。在iOS14.5以后(之前不做配置也能正常获取IDFA)想要依旧能使用IDFA，建议开发者在初始化聚合SDK之前获取ATT授权，以便允许用户授权跟踪权限。  

关于隐私权限弹窗的说明文案，已在上方接入方式步骤2的Info.plist中有提及，文案可根据需求自行修改。  

在代码层面请求授权，建议最好在SDK初始化之前请求授权。  

```
- (void)requestIDFA {
if (@available(iOS 14, *)) {
[ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
if (status == ATTrackingManagerAuthorizationStatusDenied) {
NSLog(@"StatusDenied");
}else if (status == ATTrackingManagerAuthorizationStatusAuthorized) {
NSLog(@"Authorized");
}else if (status == ATTrackingManagerAuthorizationStatusRestricted) {
NSLog(@"Restricted");
}else if (status == ATTrackingManagerAuthorizationStatusNotDetermined) {
NSLog(@"NotDetermined");
}
}];
}
}
```

## 设置测试地址

请根据需要来设置接口服务器，默认为线上接口。

设置接口为内网
```
[SdkManager setServerType:serverTestType];
```

设置接口为OT
```
[SdkManager setServerType:serverOtType];
```

设置接口为线上服务器
```
[SdkManager setServerType:serverOnlineType];
```
获取当前服务器类型，具体类型详见上方。
```
serverType type = [SdkManager serverType];
```
# 请添加相关host（有新增）
```
192.168.62.200 t.media.5054399.net
192.168.62.200 t.sdk.3839app.com
192.168.62.200 t.union.4399.cn
152.136.23.204 ot-union.4399.cn
```
# 注意，真机测试连电脑分享的网络时需要开启代理。

# 广告SDK初始化

## 三种初始化方法任选一种执行即可。也可根据业务需求在多处执行，SDK会自己处理重复初始化的逻辑问题。

### 小程序初始化示例

```
    UserConfigModel *userConfig = [[UserConfigModel alloc]init];
    userConfig.uid = @"123456";//此处传入用户的uid
    [SdkManager setUserConfig:userConfig];
[SdkManager initType:client_youxihe gameID:gameid platformID:platformid personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
if (success) {
NSLog(@"初始化成功");
}else{
}
}];    
```
### 手游初始化示例

```
    UserConfigModel *userConfig = [[UserConfigModel alloc]init];
    userConfig.uid = @"123456";//此处传入用户的uid
    [SdkManager setUserConfig:userConfig];
[SdkManager initMobileID:@"4868" bundleID:@"cn.4399.gamehotspot" personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
NSString *title;
if (success) {
title = @"广告初始化成功";
}else{
title = [NSString stringWithFormat:@"来自手游初始化：%@",errorString];
}
}];
```
### H5初始化示例
```
[SdkManager initH5ID:TestH5AppID personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
NSString *title;
if (success) {
title = @"广告初始化成功";
}else{
title = [NSString stringWithFormat:@"来自h5初始化：：%@",errorString];
}
}];
```
# 小程序广告集成
## 激励视频广告

### 接口方法、属性
回调详见上方的类型和错误码说明，都在block中。
```
/// 加载激励视频
/// - Parameter isDirection: 是否横屏
-(void)loadRewardAD:(BOOL)isHorizontal;

/// 当前的vc
/// - Parameter rootVC: vc
-(void)showAd:(UIViewController*)rootVC;

属性 
BOOL isReadToPlay;//广告加载完成
```

### 代码示例
```
MiniSlotManager *manager = [MiniSlotManager shareInstance];
manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
};
[manager loadRewardAD:YES];
if (manager.isReadToPlay) {
[manager showAd:self];
}
else{
NSLog(@"激励广告加载未完成");
}  
```

## banner广告

### 接口方法、属性
回调详见上方的类型和错误码说明，都在block中。
```
/// 加载banner广告
/// - Parameters:
///   - curVC: 初始化返回rootVC
///   - onView: 显示的view
///   - adSize: 320*50*
-(void)loadBannerAD:(UIViewController*)curVC
showView:(UIView*)onView
size:(CGSize)adSize;

///显示广告
-(void)showAd;

属性 
BOOL isReadToPlay;//广告加载完成
```

### 代码示例
```
MiniBannerManager *manager = [MiniBannerManager shareInstance];
manager.bannerBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
};
UILabel *label = [self.view viewWithTag:bannerAdViewtag];
[manager loadBannerAD:self showView:label size:CGSizeMake(320, 50)];

if (manager.isReadToPlay) {
[manager showAd];
}
else{
NSLog(@"banner广告加载未完成");
}     
```
## 插屏广告

### 接口方法、属性
回调详见上方的类型和错误码说明，都在block中。
```
/// 加载插屏广告
-(void)loadScreenAD;

/// 当前的vc
/// - Parameter rootVC: vc
-(void)showAd:(UIViewController*)rootVC;

属性 
BOOL isReadToPlay;//广告加载完成
```

### 代码示例
```
MiniScreenManager *manager = [MiniScreenManager shareInstance];
manager.screenBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
};
[manager loadScreenAD];

if (manager.isReadToPlay) {
[manager showAd:self];
}
else{
NSLog(@"插屏广告加载未完成");
}
```
## 手游广告集成
### 激励视频
广告加载
```
MobileSlotManager *manager = [MobileSlotManager shareInstance];
manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
self->blockLabel1.text=result;
};
[manager loadRewardADWithUserID:TestMobileSlotUserID horizontal:YES];
```

广告展示
```
MobileSlotManager *manager = [MobileSlotManager shareInstance];
manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
self->blockLabel1.text=result;
};
if (manager.isReadToPlay) {
[manager showAd:self];
}
else{
self->blockLabel1.text=@"激励广告加载未完成";
}
```
### banner广告
广告加载
```
MobileBannerManager *manager = [MobileBannerManager shareInstance];
manager.bannerBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
self->blockLabel2.text=result;
};
UILabel *label = [self.view viewWithTag:bannerAdViewtag];
[manager loadBannerAD:self userID:TestMobileBannerUserID showView:label size:CGSizeMake(320, 50)];
```
广告展示
```
MobileBannerManager *manager = [MobileBannerManager shareInstance];
if (manager.isReadToPlay) {
[manager showAd];
}else{
self->blockLabel2.text=@"banner广告加载未完成";
}
```
### 原生(信息流)广告

## 注意，信息流广告一次最多加载并返回3个广告素材，根据showAdArrayBlock返回的数据插入到UITableViewController的数据源中进行展示。加载和展示是按顺序直接进行的，一般不分开。
广告加载和展示
```
MobileNativManager *manager = [MobileNativManager shareInstance];
manager.nativeBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
self->blockLabel3.text=result;
};
[manager loadNativAD:self userID:TestMobileNativeUserID size:CGSizeMake(320, 50) loadMax:2];
manager.showAdBlock = ^(NSArray<MobileNativeModel *> * _Nullable adNativeArray) {
if (adNativeArray) {
[self->nativView1 addSubview:adNativeArray.firstObject.adView];
NSLog(@"%f,%f",adNativeArray.firstObject.adSize.width,adNativeArray.firstObject.adSize.height);
//...
//...
//代码示例，循环和其他逻辑略
//[self.dataSource insertObject:adNativeArray.firstObject atIndex:index];
//[self.tableView reloadData];
}
};
```


## H5广告集成

### 激励视频广告

广告加载
```
H5SlotManager *manager = [H5SlotManager shareInstance];
manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
self->blockLabel1.text=result;
};
[manager loadRewardADWithPost:TestH5PostID horizontal:YES];
```
广告展示
```
H5SlotManager *manager = [H5SlotManager shareInstance];
manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
NSLog(@"%d,%@",code, result);
self->blockLabel1.text=result;
};
if (manager.isReadToPlay) {
[manager showAd:self];
}
else{
self->blockLabel1.text=@"激励广告加载未完成";
}
```
# 更新日历
## 以下版本通过SPM引入
| 版本历史 | 支持平台 |  功能 | 更新时间 | 
|:--------:|:------------:|:------------:|:------------:|
| 0.7.805 | 默认支持穿山甲:7.8.0.5 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.90'`<br> 百度:`pod 'BaiduMobAdSDK', '10.050'`<br>  快手:`pod 'KSAdSDK', '5.5.10.1'` | 此版本为过渡版本<br>与0.7.8.0.5功能上一模一样<br>转为SPM方式引入|2026年10月30日 |
## 以下版本通过pod引入，
| 版本历史 | 支持平台 |  功能 | 更新时间 | 
|:--------:|:------------:|:------------:|:------------:|
| 0.7.8.0.5 | 默认支持穿山甲:7.8.0.5 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.90'`<br> 百度:`pod 'BaiduMobAdSDK', '10.050'`<br>  快手:`pod 'KSAdSDK', '5.5.10.1'` | 适配穿山甲最新版本|2026年10月12日 |
| 0.7.7.0.8 | 默认支持穿山甲:7.7.0.8 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.90'`<br> 百度:`pod 'BaiduMobAdSDK', '10.050'`<br>  快手:`pod 'KSAdSDK', '5.5.10.1'`  |  适配穿山甲最新版本 <br> SDK版本命名规则更改，与穿山甲保持一致|  2026年9月1日|
| 0.3.1 | 默认支持穿山甲:7.7.0.5 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.80'`<br> 百度:`pod 'BaiduMobAdSDK', '10.050'`<br>  快手:`pod 'KSAdSDK', '5.3.20.1'` | 适配穿山甲最新版本 |2026年8月20日 |
| 0.3.0 | 默认支持穿山甲:7.5.0.7 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.75'`<br> 百度:`pod 'BaiduMobAdSDK', '10.032'`<br>  快手:`pod 'KSAdSDK', '4.12.20.1'` | 升级主sdk，设定用户uid，优化统计 |2026年5月9日 |
| 0.2.9 | 默认支持穿山甲:7.3.0.7 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.60'`<br> 百度:`pod 'BaiduMobAdSDK', '10.02'`<br>  快手:`pod 'KSAdSDK', '4.9.20.1'` | 升级主sdk，优化内存.仅支持真机 |2026年1月12日 |
| 0.2.8 | 默认支持穿山甲:7.1.1.5 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.60'`<br> 百度:`pod 'BaiduMobAdSDK', '10.02'`<br>  快手:`pod 'KSAdSDK', '4.9.20.1'` | 升级主sdk，优化初始化相关数据缓存.仅支持真机 |2025年10月24日 |
| 0.2.7 | 默认支持穿山甲:7.1.0.9 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.41'`<br> 百度:`pod 'BaiduMobAdSDK', '5.394'`<br>  快手:`pod 'KSAdSDK', '4.6.30.1'` | 升级主sdk.仅支持真机 |2025年9月29日 |
| 0.2.5 | 默认支持穿山甲:7.0.1.3 <br> 自行引入优量汇、百度、快手<br> 优量汇:`pod 'GDTMobSDK', '4.15.40.0'`<br> 百度:`pod 'BaiduMobAdSDK', '5.39'`<br>  快手:`pod 'KSAdSDK', '3.3.76'` | 优化数据解析，升级主sdk.仅支持真机 |2025年9月17日 |
| 0.2.4 | 默认支持穿山甲:6.8.0.7 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.30.0'`<br> 百度:`pod 'BaiduMobAdSDK', '5.38'`<br>  快手:`pod 'KSAdSDK', '3.3.75'`| 升级主sdk |2025年4月30日 |
| 0.2.3 | 默认支持穿山甲:6.6.1.5 <br> 自行引入优量汇、百度、快手 <br> 优量汇:`pod 'GDTMobSDK', '4.15.10.0'`<br> 百度:`pod 'BaiduMobAdSDK', '5.370.1'`<br>  快手:`pod 'KSAdSDK', '3.3.71.0'`| 优化初始化 |2025年4月21日 |
| 0.2.2 | 默认支持穿山甲:6.6.1.5，自行引入<br> 优量汇:`pod 'GDTMobSDK', '4.15.10.0'`<br> 百度:`pod 'BaiduMobAdSDK', '5.370.1'`<br>  快手:`pod 'KSAdSDK', '3.3.71.0'` | 优化获取信息流广告高度 |2025年3月25日 |
| 0.2.0 | 默认支持穿山甲:6.6.1.5，自行引入<br> 优量汇:`pod 'GDTMobSDK', '4.15.10.0'`<br> 百度:`pod 'BaiduMobAdSDK', '5.370.1'`<br>  快手:`pod 'KSAdSDK', '3.3.71.0'` | 支持数据统计 |2025年3月7日 |
| 0.1.9 | 默认支持穿山甲:6.6.1.5，自行引入<br> 优量汇:`pod 'GDTMobSDK', '4.15.10.0'`<br> 百度:`pod 'BaiduMobAdSDK', '5.370.1'`<br>  快手:`pod 'KSAdSDK', '3.3.71.0'` | 支持手游和H5 |2025年2月28日 |
| 0.1.7 | 默认支持穿山甲:6.4.1.0，自行引入<br> 优量汇:`pod 'GDTMobSDK', '4.15.0'`<br> 百度:`pod 'BaiduMobAdSDK', '5.370'`<br>  快手:`pod 'KSAdSDK', '3.3.67.0'` | 拆分支持的平台，按需引入 | 2024年11月18日 |  
| 0.1.6 | 默认支持穿山甲:6.4.1.0，<br>优量汇:'4.15.0'<br> 百度:'5.370'<br>  快手:'3.3.67.0' | 小程序广告sdk，支持百度、快手和优量汇 |2024年9月12日 | 
