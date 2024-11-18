//
//  SdkManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/28.
//

#import <Foundation/Foundation.h>
#import <MiniSDKFramework/AdErrorCode.h>

typedef void(^resultHandel)(BOOL success,NSString * _Nullable errorString);

NS_ASSUME_NONNULL_BEGIN

@interface SdkManager : NSObject


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



/// 设置服务器接口
/// - Parameter type: online/test/ot
+(void)setServerType:(serverType)type;

/// 服务器接口
+(serverType)serverType;
@end

NS_ASSUME_NONNULL_END
