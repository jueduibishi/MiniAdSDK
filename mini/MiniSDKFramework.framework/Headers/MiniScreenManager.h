//
//  MiniScreenManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MiniSDKFramework/AdErrorCode.h>

NS_ASSUME_NONNULL_BEGIN

@interface MiniScreenManager : NSObject
@property(nonatomic,assign)BOOL isReadToPlay;//广告加载完成

@property(nonatomic,copy)adHandel screenBlock;

+(instancetype)shareInstance;

/// 加载插屏广告
-(void)loadScreenAD;
/// 当前的vc
/// - Parameter rootVC: vc
-(void)showAd:(UIViewController*)rootVC;

@end

NS_ASSUME_NONNULL_END
