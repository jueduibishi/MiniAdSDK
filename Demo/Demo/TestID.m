//
//  TestID.m
//  MainClasse
//
//  Created by 杨益凡 on 2025/2/25.
//  Copyright © 2025 YYF. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "TestID.h"
#define firstView ([[UIApplication sharedApplication] keyWindow]?[[UIApplication sharedApplication] keyWindow]:[[[UIApplication sharedApplication] windows] firstObject])
@interface TestID (){
    UILabel *label;
}
@end

@implementation TestID

+(instancetype)shareInstance
{
    static TestID* instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[TestID alloc]init];
    });
    return instance;
}


- (void)startMonitoring {
    [self registerDefaultSettings];
}
- (void)registerDefaultSettings {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSString *bundlePath = [[NSBundle mainBundle] pathForResource:@"Settings" ofType:@"bundle"];
    NSDictionary *settingsDict = [NSDictionary dictionaryWithContentsOfFile:
                                  [bundlePath stringByAppendingPathComponent:@"Root.plist"]];
    
    NSMutableDictionary *defaultsDict = [NSMutableDictionary new];
    for (NSDictionary *pref in settingsDict[@"PreferenceSpecifiers"]) {
        if (pref[@"Key"]) {
            defaultsDict[pref[@"Key"]] = pref[@"DefaultValue"] ?: [NSNull null];
        }
    }
    [defaults registerDefaults:defaultsDict];
    [[NSUserDefaults standardUserDefaults] synchronize];

}
-(void)setTishText:(NSString *)tishText{
    _tishText = tishText;
    if (!label) {
        label =[[UILabel alloc]initWithFrame:CGRectMake(20, [UIScreen mainScreen].bounds.size.height-20-[UIApplication sharedApplication].delegate.window.safeAreaInsets.bottom, 500, 20)];
        label.textColor=[UIColor redColor];
        [firstView addSubview:label];
    }
    label.text = tishText;
}
#pragma mark -
#pragma mark - 小程序
-(NSString* _Nullable)miniAppID{
    _miniAppID = [[NSUserDefaults standardUserDefaults] objectForKey:@"miniappid"];

    return _miniAppID;
}
-(NSString* _Nullable)miniPlatform{
    _miniPlatform = [[NSUserDefaults standardUserDefaults] objectForKey:@"miniplatform"];

    return _miniPlatform;
}

/// NO = 快爆 YES=游戏盒
-(BOOL)miniClient{
    _miniClient = [[NSUserDefaults standardUserDefaults] boolForKey:@"miniclient"];;
    return _miniClient;
}
#pragma mark -
#pragma mark - 手游
-(NSString* _Nullable)mobileAppID{
    _mobileAppID = [[NSUserDefaults standardUserDefaults] objectForKey:@"mobileappid"];
    return _mobileAppID;;
}
-(NSString* _Nullable)mobileBundleID{
    _mobileBundleID = [[NSUserDefaults standardUserDefaults] objectForKey:@"mobilebundleid"];
    return _mobileBundleID;
}
-(NSString* _Nullable)mobileSlotUserID{
    _mobileSlotUserID = [[NSUserDefaults standardUserDefaults] objectForKey:@"mobileslotuserid"];

    return _mobileSlotUserID;
}
-(NSString* _Nullable)mobileBannerUserID{
    _mobileBannerUserID = [[NSUserDefaults standardUserDefaults] objectForKey:@"mobilebanneruserid"];

    return _mobileBannerUserID;
}
-(NSString* _Nullable)mobileNativeUserID{
    _mobileNativeUserID = [[NSUserDefaults standardUserDefaults] objectForKey:@"mobilenativeuserid"];

    return _mobileNativeUserID;
}
#pragma mark -
#pragma mark - h5
-(NSString* _Nullable)h5AppID{
    _h5AppID = [[NSUserDefaults standardUserDefaults] objectForKey:@"h5appid"];

    return _h5AppID;
}
-(NSString* _Nullable)h5PostID{
    _h5PostID = [[NSUserDefaults standardUserDefaults] objectForKey:@"h5postid"];

    return _h5PostID;
}

@end
