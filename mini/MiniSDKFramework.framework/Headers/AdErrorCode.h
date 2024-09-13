//
//  AdErrorCode.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,clientType){
    client_youxihe=1,//游戏盒
    client_kuaibao,//快爆
};

typedef void(^adHandel)(int code,NSString *result);

typedef NS_ENUM(int,slotErrorCode){
    slotInitFailCode=0,//无广告位id，初始化失败
    slotLoadFailCode,//广告加载错误
    slotLoadSuccessCode,//广告加载成功
    slotPlayFailCode,//广告播放错误
    slotPlaySuccedCode,//广告播放完成
    slotClickCode,//广告点击
    slotCloseCode,//广告关闭
    slotReWardSucCode,//广告奖励到达
    slotReWardFailCode,//广告奖励发放失败
    slotSkipCode,//广告被跳过
};//激励广告错误

typedef NS_ENUM(int,bannerErrorCode){
    bannerInitFaildCode=0,//无广告位id，初始化失败
    bannerLoadFailCode,//广告加载错误
    bannerLoadSuccessCode,//广告加载成功
    bannerClickCode,//广告点击
    bannerCloseCode,//广告关闭
};

typedef NS_ENUM(int,screenErrorCode){
    screenInitFaildCode=0,//无广告位id，初始化失败
    screenLoadFailCode,//广告加载错误
    screenLoadSuccessCode,//广告加载成功
    screenPlayFailCode,//广告播放错误
    screenPlaySuccedCode,//广告播放完成
    screenClickCode,//广告点击
    screenCloseCode,//广告关闭
    screenReWardSucCode,//广告奖励到达
    screenReWardFailCode,//广告奖励发放失败
    screenSkipCode,//广告被跳过
};

@interface AdErrorCode : NSObject

@end

NS_ASSUME_NONNULL_END
