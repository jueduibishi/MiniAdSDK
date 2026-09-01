//
//  TTSDKManager+Debug.m
//  TTSDK
//

#import "TTSDKManager.h"

@implementation TTSDKManager (Debug)

static NSMutableDictionary *TTAppInfoDic = nil;
static BOOL TTSkipInitTTSDKValidation = NO;

+ (void)sdkInitValidation:(TTSDKConfiguration *)configuration
                  bizType:(TTSDKServiceBizType)bizType {
#ifdef DEBUG
    if (configuration.skipSDKInitValidation || TTSkipInitTTSDKValidation) {
        NSLog(@"TTSDK:: skip init validation");
        return;
    }
    NSLog(@"TTSDK:: init appId:%@, bizType:%@, appRegion:%@, bundleId:%@, licensePath:%@", configuration.appID, @(configuration.bizType), @(configuration.appRegion), configuration.bundleID, configuration.licenseFilePath);
    if (TTAppInfoDic == nil) {
        TTAppInfoDic = [NSMutableDictionary dictionary];
    }
    // 获取上一次初始化的App
    NSString *preInitAppid = [TTAppInfoDic objectForKey:@(bizType)];
    if (preInitAppid && ![preInitAppid isEqualToString:configuration.appID]) {
        NSAssert(NO, @"TTSDK:: Repeated initialization of TTSDK with different AppIDs passed in during the two initializations will cause loss of reported logs. Please check the initialization logic or contact technical support for assistance in resolving this issue; if you want to ignore this problem, you can set TTSDKConfiguration:skipSDKInitValidation = YES to skip the check.");
    }
    if (configuration.appID) {
        [TTAppInfoDic setObject:configuration.appID forKey:@(bizType)];
    }
#endif
}

/**
 * @locale zh
 * @type api
 * @brief 跳过 TTSDK 初始化检查
 */
+ (void)skipInitValidation {
    TTSkipInitTTSDKValidation = YES;
}

@end
