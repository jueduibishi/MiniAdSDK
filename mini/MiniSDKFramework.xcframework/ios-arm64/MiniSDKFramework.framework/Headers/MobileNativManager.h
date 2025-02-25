//
//  MobileNativManager.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2025/2/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MiniSDKFramework/AdErrorCode.h>

NS_ASSUME_NONNULL_BEGIN

/// 手游原生(信息流)广告
@interface MobileNativManager : NSObject
@property(nonatomic,copy)adHandel nativeBlock;
@property(nonatomic,copy)void (^showAdBlock)(NSArray <UIView*>* _Nullable adViewArray);//广告加载完成可展示
+(instancetype)shareInstance;


/// 加载原生(信息流)广告
/// - Parameters:
///   - curVC: 返回rootVC
///   - userID: 用户id
///   - adSize: 320*50*
///   - maxCount: 一次性加载的素材数量，1~3个
-(void)loadNativAD:(UIViewController*)curVC
             userID:userID
               size:(CGSize)adSize
           loadMax:(NSInteger)maxCount;

@end

NS_ASSUME_NONNULL_END
