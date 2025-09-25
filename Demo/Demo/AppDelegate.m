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

@interface AppDelegate ()
@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [[TestID shareInstance]startMonitoring];

    //测试接口
    if ([ViewController userDefaultsObjectByKey:@"serverType"] == nil) {
        [SdkManager setServerType:serverTestType];
    }
    //隐私相关
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self requestIDFA];
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
@end
