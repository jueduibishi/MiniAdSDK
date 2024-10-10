//
//  MIniBannerManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/29.
//

#import <Foundation/Foundation.h>
#import <MiniSDKFramework/AdErrorCode.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// banner广告
@interface MiniBannerManager : NSObject
@property(nonatomic,assign)BOOL isReadToPlay;//广告加载完成
@property(nonatomic,copy)adHandel bannerBlock;

+(instancetype)shareInstance;

/// 加载banner广告
/// - Parameters:
///   - curVC: 初始化返回rootVC
///   - onView: 显示的view
///   - adSize: 320*50*
-(void)loadBannerAD:(UIViewController*)curVC
           showView:(UIView*)onView
               size:(CGSize)adSize;
-(void)showAd;

@end

NS_ASSUME_NONNULL_END
