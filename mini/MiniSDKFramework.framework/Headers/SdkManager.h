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

/// 设置测试环境
/// - Parameter value: yes = test server ，ot不测试，默认no=线上
+(void)setTest:(BOOL)value;
@end

NS_ASSUME_NONNULL_END
