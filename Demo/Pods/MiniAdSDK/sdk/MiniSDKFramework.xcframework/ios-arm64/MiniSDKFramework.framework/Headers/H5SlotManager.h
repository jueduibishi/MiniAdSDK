//
//  H5SlotManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2025/2/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MiniSDKFramework/AdErrorCode.h>
NS_ASSUME_NONNULL_BEGIN


/// h5激励视频广告
@interface H5SlotManager : NSObject
@property(nonatomic,assign)BOOL isReadToPlay;//广告加载完成

@property(nonatomic,copy)adHandel didRewardBlock;

+(instancetype)shareInstance;


/// 加载激励视频
/// - Parameters:
///   - postID: 广告位ID
///   - isHorizontal: 是否横屏 
-(void)loadRewardADWithPost:(NSString*)postID
         horizontal:(BOOL)isHorizontal;
/// 当前的vc
/// - Parameter rootVC: vc
-(void)showAd:(UIViewController*)rootVC;

@end

NS_ASSUME_NONNULL_END
