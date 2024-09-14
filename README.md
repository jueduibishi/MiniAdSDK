# MiniAdSDK
广告集成，最低支持iOS12,本项目依赖KSAdSDK用于真机联调。
#接入
```
pod 'MiniAdSDK'
```
#配置
##1、在项目的Info.plist文件中添加以下字段
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
##2、模拟器配置
英特尔芯片的Mac创建的demo项目可以直接运行。
穿山甲集成的BaiduMobAdSDK和GDTMobSDK不支持arm64的模拟器，所以必须做如下设置。
M1之后的arm架构的Mac创建的xcode项目必须修改下Target——Build Settings——Excluded Architectures——Any iOS Simulator SDK设置为arm64。

##3、其他配置
Targets-build settings - user script sandboxing 设置为No

# 类型和错误码说明

```
typedef NS_ENUM(NSInteger,clientType){
    client_youxihe=1,//游戏盒
    client_kuaibao,//快爆
};

typedef void(^adHandel)(int code,NSString *result);

typedef NS_ENUM(int,slotErrorCode){
    slotInitFailCode=0,//无广告位id，初始化失败
    slotLoadFailCode,//广告加载错误
    slotLoadSuccessCode,//广告加载成功
    slotPlayFailCode,//广告播放错误
    slotPlaySuccedCode,//广告播放完成
    slotClickCode,//广告点击
    slotCloseCode,//广告关闭
    slotReWardSucCode,//广告奖励到达
    slotReWardFailCode,//广告奖励发放失败
    slotSkipCode,//广告被跳过
};//激励广告错误

typedef NS_ENUM(int,bannerErrorCode){
    bannerInitFaildCode=0,//无广告位id，初始化失败
    bannerLoadFailCode,//广告加载错误
    bannerLoadSuccessCode,//广告加载成功
    bannerClickCode,//广告点击
    bannerCloseCode,//广告关闭
};//banner广告错误

typedef NS_ENUM(int,screenErrorCode){
    screenInitFaildCode=0,//无广告位id，初始化失败
    screenLoadFailCode,//广告加载错误
    screenLoadSuccessCode,//广告加载成功
    screenPlayFailCode,//广告播放错误
    screenPlaySuccedCode,//广告播放完成
    screenClickCode,//广告点击
    screenCloseCode,//广告关闭
    screenReWardSucCode,//广告奖励到达
    screenReWardFailCode,//广告奖励发放失败
    screenSkipCode,//广告被跳过
};//插屏广告错误
```
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

目前SDK处于测试阶段，接口请求的是内网测试服务器，SDK初始化之前务必执行以下代码来设置测试接口。

```
// YES:测试接口 NO:线上接口，若本方法不执行，则默认为线上服务器接口。
[SdkManager setTest:YES];
```
请添加相关host
```
192.168.62.200 t.media.5054399.net
192.168.62.200 t.sdk.3839app.com
```
注意，真机测试连电脑分享的网络时需要开启代理。

## 广告SDK初始化

### 接口方法
回调详见上方的类型和错误码说明，都在block中。

```
/// 初始化
/// - Parameters:
///   - client: yxh or kb
///   - gameID: gameid
///   - platformID: platformID
///   - personalAD: 个性化广告
///   - block: compliete
+(void)initType:(clientType)client
         gameID:(NSString*)gameID
     platformID:(NSString*)platformID
     personalAD:(BOOL)personalAD
       Complete:(resultHandel)block;
```
       
### 代码示例

```
[SdkManager initType:client_youxihe gameID:gameid platformID:platformid personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
        if (success) {
            NSLog(@"初始化成功");
        }else{
        }}];    
```

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
    UIViewController *vc=[UIApplication sharedApplication].delegate.window.rootViewController;
    //若有SceneDelegate，采用多窗口模式，请自行处理获取正确的rootvc
    [manager showAd:vc];
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

///显示广告
-(void)showAd;

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
    [manager showAd];
}
else{
     NSLog(@"插屏广告加载未完成");
}
```
