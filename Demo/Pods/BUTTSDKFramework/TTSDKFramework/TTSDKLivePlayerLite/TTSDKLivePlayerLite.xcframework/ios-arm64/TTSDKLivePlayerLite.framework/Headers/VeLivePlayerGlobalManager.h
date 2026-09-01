//
//  VeLivePlayerGlobalManager.h
//  TTVideoLive
//
//  Created by jiaochong on 2023/1/31.
//
#import <Foundation/Foundation.h>
#import "TVLConstDefine.h"

typedef NS_ENUM(NSInteger, VeLivePlayerNetworkStatus) {
    VeLivePlayerNetworkStatusUnKnow,
    VeLivePlayerNetworkStatusNotReachable,
    VeLivePlayerNetworkStatusViaWiFi,
    VeLivePlayerNetworkStatusViaWAN
};

typedef NS_ENUM(NSInteger, VeLivePlayerValueKey) {
    VeLivePlayerValueOfFreeFlowStatus = -1,
    VeLivePlayerValueOfPcdnWatchThreshold,
    VeLivePlayerValueOfPcdnH2pCache
};

typedef NS_ENUM(NSInteger, VeLivePlayerConfigType) {
    VeLivePlayerDolphinConfig,
    VeLivePlayerAppConfig
};

typedef NS_ENUM(NSInteger, VeLivePlayerLogType) {
    VeLivePlayerALogType,
    VeLivePlayerStaticLogType
};

typedef NSString *_Nullable VeLivePlayerLiveIOLogKey;

OBJC_EXTERN const VeLivePlayerLiveIOLogKey VeLivePlayerLiveIOMonitorLog;


typedef void(^VeLivePlayerLogCallback)(TVLLogLevel level, NSString *tag, NSString *log);

@protocol VeLivePlayerGlobalObserver <NSObject>

- (void)onMonitorLog:(NSDictionary *)eventLog logType:(VeLivePlayerLiveIOLogKey)logType;

@end


@interface VeLivePlayerGlobalManager : NSObject

@property (nonatomic, weak) id<VeLivePlayerGlobalObserver> observer;

+ (instancetype)defaultManager;

- (void)start;
- (void)stop;
- (void)updateConfig:(VeLivePlayerConfigType)configType config:(NSDictionary *)config;
// - (void)updateCurrentNetworkStatus:(VeLivePlayerNetworkStatus)networkStatus;
- (void)setAlogCallback:(VeLivePlayerLogCallback)logCallback;
- (id)getValueByKey:(VeLivePlayerValueKey)key;

//need move to private


@end
