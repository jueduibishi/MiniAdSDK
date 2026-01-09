//
//  SdkManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/28.
//

#import <Foundation/Foundation.h>
#import <MiniSDKFramework/AdErrorCode.h>
#import <MiniSDKFramework/MiniSlotManager.h>
#import <MiniSDKFramework/MiniBannerManager.h>
#import <MiniSDKFramework/MiniScreenManager.h>
#import <MiniSDKFramework/H5SlotManager.h>
#import <MiniSDKFramework/MobileSlotManager.h>
#import <MiniSDKFramework/MobileBannerManager.h>
#import <MiniSDKFramework/MobileNativManager.h>
#import <MiniSDKFramework/MobileNativeModel.h>

typedef void(^resultHandel)(BOOL success,NSString * _Nullable errorString);

NS_ASSUME_NONNULL_BEGIN

@interface SdkManager : NSObject


/// 初始化-小程序
/// - Parameters:
///   - client: yxh or kb
///   - gameID: gameid
///   - platformID: platformID,如：1028
///   - personalAD: 个性化广告
///   - block: Complete
+(void)initType:(clientType)client
         gameID:(NSString*)gameID
     platformID:(NSString*)platformID
     personalAD:(BOOL)personalAD
       Complete:(resultHandel)block;

/// 初始化-手游
/// - Parameters:
///   - gameID: gameid
///   - bundleID: bundleID，如cn.m4399.operate1209.m4399
///   - personalAD: 个性化广告
///   - block: Complete
+(void)initMobileID:(NSString*)gameID
           bundleID:(NSString*)bundleID
         personalAD:(BOOL)personalAD
           Complete:(resultHandel)block;

/// 初始化-h5
/// - Parameters:
///   - gameID: gameid
///   - personalAD: 个性化广告
///   - block: Complete
+(void)initH5ID:(NSString*)gameID
         personalAD:(BOOL)personalAD
       Complete:(resultHandel)block;

/// 设置服务器接口
/// - Parameter type: online/test/ot
+(void)setServerType:(serverType)type;

/// 服务器接口
+(serverType)serverType;

+(BOOL)isNotNil:(id)obj;
@end

NS_ASSUME_NONNULL_END
