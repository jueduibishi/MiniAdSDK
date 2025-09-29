//
//  AdErrorCode.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark-通用定义

//服务器接口
typedef NS_ENUM(NSInteger,serverType){
    serverOnlineType=0,//正式网
    serverTestType,//测试
    serverOtType,//ot
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
};//banner广告错误

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

typedef NS_ENUM(int,NativErrorCode){
    nativInitFaildCode=0,//无广告位id，初始化失败
    nativLoadFailCode,//广告加载错误
    nativLoadSuccessCode,//广告加载成功
    nativDidBecomeVisibleCode,//广告展示
    nativDidClickCode,//广告点击成功
    nativRendSucCode,//渲染成功
    nativRendFailCode//渲染失败
};//原生(信息流)广告错误
#pragma mark-小程序
typedef NS_ENUM(NSInteger,clientType){
    client_youxihe=1,//游戏盒
    client_kuaibao,//快爆
};
#pragma mark-手游
//手游广告位类型-目前支持Banner、(信息流)、激励视频
typedef NS_ENUM(NSInteger,mobileADType){
    mobileADType_Banner=1,//Banner广告
    mobileADType_Start,//2开屏广告
    mobileADType_Insert,//3插屏广告
    mobileADType_Native,//4原生(信息流)广告
    mobileADType_Slot,//5激励视频广告
    mobileADType_Full,//6全屏视频广告
};
//手游渠道类型-目前仅支持Gromore
typedef NS_ENUM(NSInteger,mobileChannelType){
    mobileChannelType_GDT=1,//广点通-优量汇
    mobileChannelType_LD,//2乐逗
    mobileChannelType_mobvista,//3mobvista
    mobileChannelType_4399,//4-4399媒体
    mobileChannelType_toutiao,//5今日头条
    mobileChannelType_Gromore=9,//9Gromore
};


@interface AdErrorCode : NSObject
@end

NS_ASSUME_NONNULL_END
