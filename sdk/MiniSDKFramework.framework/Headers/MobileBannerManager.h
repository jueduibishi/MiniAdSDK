//
//  MobileBannerManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2025/2/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MiniSDKFramework/AdErrorCode.h>
NS_ASSUME_NONNULL_BEGIN


/// 手游banner视频广告
@interface MobileBannerManager : NSObject
@property(nonatomic,assign)BOOL isReadToPlay;//广告加载完成
@property(nonatomic,copy)adHandel bannerBlock;

+(instancetype)shareInstance;

/// 加载banner广告
/// - Parameters:
///   - curVC: 初始化返回rootVC
///   - userID: 用户ID即渠道ID
///   - onView: 显示的view
///   - adSize: 320*50*
-(void)loadBannerAD:(UIViewController*)curVC
             userID:userID
           showView:(UIView*)onView
               size:(CGSize)adSize;
-(void)showAd;


@end

NS_ASSUME_NONNULL_END
