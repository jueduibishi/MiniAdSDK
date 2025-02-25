//
//  AppDelegate.m
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/28.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <MiniSDKFramework/SdkManager.h>
#import "TableVC.h"

#define firstView ([[UIApplication sharedApplication] keyWindow]?[[UIApplication sharedApplication] keyWindow]:[[[UIApplication sharedApplication] windows] firstObject])


@interface AppDelegate (){
    UILabel *label;
}

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    self.window.rootViewController = [[UINavigationController alloc]initWithRootViewController:[[TableVC alloc]init]];
    label =[[UILabel alloc]initWithFrame:CGRectMake(20, [UIScreen mainScreen].bounds.size.height-20-[UIApplication sharedApplication].delegate.window.safeAreaInsets.bottom, 500, 20)];
    label.textColor=[UIColor redColor];
    [firstView addSubview:label];

    //测试接口
    if ([ViewController userDefaultsObjectByKey:@"serverType"] == nil) {
        [SdkManager setServerType:serverTestType];
    }    //隐私相关
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self requestIDFA];
    });
    //直接执行来测试同时初始化
    [self mobileRegister];
    [self miniRegister];
    [self h5Register];
//    [self h5Register];
    
    //延迟来测试不同页面重复注册
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [self h5Register];
    });
    
    
    return YES;
}

///适配iOS14，获取广告IDFA
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
#pragma mark -
#pragma mark -小程序

/// 小程序初始化
-(void)miniRegister{
    if (![ViewController userDefaultsObjectByKey:clientKey]) {
        [ViewController setUserDefaults:@"1028" forKey:clientKey];
    }
    NSString *gid = @"1000013";//外网
//    gid = @"1000133";//ot
    if (![ViewController userDefaultsObjectByKey:gameidKey]) {
        [ViewController setUserDefaults:gid forKey:gameidKey];
    }
    NSString *platformid = [ViewController userDefaultsObjectByKey:clientKey];
    NSString *gameid = [ViewController userDefaultsObjectByKey:gameidKey];
    NSString *gamePlatform = [ViewController userDefaultsObjectByKey:gameplatformKey];
    clientType type = client_kuaibao;
    if (gamePlatform.integerValue == 1) {
        type = client_kuaibao;
    }else{
        type = client_youxihe;
    }
    [SdkManager initType:type gameID:gameid platformID:platformid personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
        NSString *title;
        if (success) {
            title = @"广告初始化成功";
        }else{
            title = [NSString stringWithFormat:@"来自小程序初始化：%@",errorString];
        }
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            dispatch_async(dispatch_get_main_queue(), ^{
                self->label.text = title;
                NSLog(@"%@",title);
            });
        });
    }];
}

/// 手游初始化
-(void)mobileRegister{
    [SdkManager initMobileID:@"4868" bundleID:@"cn.4399.gamehotspot" personalAD:YES sdkVer:@"0.0.7" Complete:^(BOOL success, NSString * _Nullable errorString) {
        NSString *title;
        if (success) {
            title = @"广告初始化成功";
        }else{
            title = [NSString stringWithFormat:@"来自手游初始化：%@",errorString];
        }
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            dispatch_async(dispatch_get_main_queue(), ^{
                self->label.text = title;
                NSLog(@"%@",title);
            });
        });
    }];
}
/// 手游初始化
-(void)h5Register{
    [SdkManager initH5ID:TestH5AppID personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
        NSString *title;
        if (success) {
            title = @"广告初始化成功";
        }else{
            title = [NSString stringWithFormat:@"来自h5初始化：：%@",errorString];
        }
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            dispatch_async(dispatch_get_main_queue(), ^{
                self->label.text = title;
                NSLog(@"%@",title);
            });
        });
    }];
}

@end
