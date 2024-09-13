//
//  MiniSlotManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/29.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MiniSDKFramework/AdErrorCode.h>

NS_ASSUME_NONNULL_BEGIN



/// 激励视频
@interface MiniSlotManager : NSObject
@property(nonatomic,assign)BOOL isReadToPlay;//广告加载完成

@property(nonatomic,copy)adHandel didRewardBlock;

+(instancetype)shareInstance;

/// 加载激励视频
/// - Parameter isDirection: 是否横屏
-(void)loadRewardAD:(BOOL)isHorizontal;
/// 当前的vc
/// - Parameter rootVC: vc
-(void)showAd:(UIViewController*)rootVC;
@end

NS_ASSUME_NONNULL_END
