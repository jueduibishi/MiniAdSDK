//
//  MobileSlotManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2025/2/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MiniSDKFramework/AdErrorCode.h>

NS_ASSUME_NONNULL_BEGIN


/// 手游激励视频广告
@interface MobileSlotManager : NSObject
@property(nonatomic,assign)BOOL isReadToPlay;//广告加载完成

@property(nonatomic,copy)adHandel didRewardBlock;

+(instancetype)shareInstance;

/// 加载激励视频
/// - Parameters:
///   - userID: 用户ID即渠道ID
///   - isHorizontal: 是否横屏
-(void)loadRewardADWithUserID:(NSString*)userID
         horizontal:(BOOL)isHorizontal;
/// 当前的vc
/// - Parameter rootVC: vc
-(void)showAd:(UIViewController*)rootVC;

@end

NS_ASSUME_NONNULL_END
