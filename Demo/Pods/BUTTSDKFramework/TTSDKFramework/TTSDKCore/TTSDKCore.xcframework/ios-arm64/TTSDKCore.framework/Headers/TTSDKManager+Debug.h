//
//  TTSDKManager+Debug.h
//  TTSDK
//

#import "TTSDKManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTSDKManager (Debug)

/**
 * @locale zh
 * @type api
 * @brief TTSDK 初始化检查
 * @notes 初始化检查只会在 Debug 模式下进行，如果验证失败会通过 NSAssert 阻断并给出错误提示。
 */
+ (void)sdkInitValidation:(TTSDKConfiguration *)configuration
                  bizType:(TTSDKServiceBizType)bizType;

/**
 * @locale zh
 * @type api
 * @brief 跳过 TTSDK 初始化检查
 */
+ (void)skipInitValidation;

@end

NS_ASSUME_NONNULL_END
