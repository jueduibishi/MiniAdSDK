//
//  TVLSettingsManager.h
//  TTVideoLive
//
//  Created by chenzhaojie on 2019/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyLiveSettingsState;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsH264HardwareDecodeEnabled;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsByteVC1HardwareDecodeEnabled;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyMaxCacheSeconds;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyShouldReportTimeSeries;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyShouldReportSessionStop;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsHurryEnabled;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyCatchupSpeed;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyHurryTime;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeySlowPlaySpeed;
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeySlowPlayTime;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIgnoreVideoBufferring;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsHTTPKDegradeEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsFastOpenEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsFPSProbeSize;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsNTPSyncEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsEnableAdaptedWatermark;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsStartPlayAudioBufferThreshold;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsBufferingEndIgnoreVideo;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsAdvancedBufferringCheckEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsHTTPDNSEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsByteVC1DegradeEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyIsResolutionDegradeEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyResolutionDegradeConditionStallCount;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyAudioRenderDeviceType;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyJXCodecDropNALUEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyTCPFastOpenEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyPlayerViewRenderType;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyHTTPDNSServerHost;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyVideoAutoCropEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyPacketDidReceiveCallbackEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyRepeatedDataDroppingEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyFrameWillRenderCallbackEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyShouldUseAudioPool;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyShouldUseAudioGraphPool;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyShouldConfigPlayerAsynchronously;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyDroppingRepeatingDataDTSMaxDiff;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyStartRenderIgnoreWindowSize;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeySuperResolutionEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeySRResolutionBlockList;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyShouldTryAllResolvedIPAddresses;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyPlayerLogCallbackEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyTTPlayerCanPlayAtBackgroundWhenInPictureInPictureWrapper;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyTTPlayerAudioVolumeBalanceEnable;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyTTPlayerAudioVolumeBalancePregain;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyTTPlayerAudioVolumeBalanceThreshold;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyTTPlayerAudioVolumeBalanceRatio;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyTTPlayerAudioVolumeBalancePredelay;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyPTSSyncedSEINotificationEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyNTPServerName;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyStartRenderCallbackTriggeringMode;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyUseRearPlayerCore;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyRTCFallbackThreshodInMilliseconds;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyAVStackEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyFormatFallbackList;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyStallRetryTimeIntervalInMilliseconds;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyDecodeMultiSEIEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyNotifySEIImmediatelyBeforeFirstFrameEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyMarkingParsedSEIEnabled;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyEnableCMAFFastMode;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyEnableCMAFVideoMPDRefresh;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyEnableAudioClockOffset;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyDRMKeyRequestRetryTimes;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyShouldLogToConsole;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyShouldDrawBorderOfPlayerView;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyForbiddenBytevc1SoftwareDecode;

FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyEnabledSoftwareDecodeFallback;

// NTP. used to sync the clock between server
FOUNDATION_EXTERN NSString *_Nullable TVLSettingsItemKeyClientServerTimeDiff;

@protocol TVLSettingsManagerDataSource <NSObject>

- (NSDictionary *_Nullable)currentSettings;

- (NSDictionary *_Nullable)currentCommonParams;

@end

@interface TVLSettingsManagerDataSource : NSObject <TVLSettingsManagerDataSource>

+ (instancetype _Nonnull)defaultDataSource;

@property (nonatomic, assign) BOOL allowsSettingsAutoUpdate;

- (void)updateSettings:(BOOL)forced;

@end

@interface TVLSettingsManager : NSObject

@property (nonatomic, weak) id<TVLSettingsManagerDataSource> _Nullable dataSource;

@property (copy, readonly) NSDictionary *currentSettings;

+ (instancetype _Nonnull)defaultManager;

- (void)updateCurrentSettings;

- (BOOL)hasSettingsForKey:(NSString *)key;

- (NSDictionary *)currentCommonParams;

@end

@interface TVLSettingsManager (Settings)

@property (nonatomic, copy, readonly) NSArray *_Nullable recommendedResolutionDegradeSequence;

@property (nonatomic, assign, readonly) NSInteger resolutionDegradeConditionStallCount;

@property (nonatomic, assign, readonly) BOOL isResolutionDegradeEnabled;

@property (nonatomic, assign, readonly) BOOL isHTTPDNSEnabled;

@property (nonatomic, assign, readonly) BOOL isAdvancedBufferringCheckEnabled;

@property (nonatomic, assign, readonly) BOOL isByteVC1DegradeEnabled;

@property (nonatomic, assign, readonly) BOOL isHTTPKDegradeEnabled;

@property (nonatomic, assign, readonly) BOOL isFastOpenEnabled;

@property (nonatomic, assign, readonly) BOOL isH264HardwareDecodeEnabled;

@property (nonatomic, assign, readonly) BOOL isByteVC1HardwareDecodeEnabled;

@property (nonatomic, assign, readonly) BOOL isClockSynchronizationEnabled;

@property (nonatomic, assign, readonly) float ntpTimeDiffByApp;

@property (nonatomic, assign, readonly) BOOL shouldReportTimeSeries;

@property (nonatomic, assign, readonly) BOOL shouldReportSessionStop;

@property (nonatomic, assign, readonly) BOOL shouldIgnoreVideoBufferring;

@property (nonatomic, assign, readonly) NSInteger maxCacheDurationInSeconds;

@property (nonatomic, assign, readonly, getter=isHurryEnabled) BOOL hurryEnabled;

@property (nonatomic, assign, readonly) NSInteger hurryTime;

@property (nonatomic, assign, readonly) NSInteger slowPlayTime;

@property (nonatomic, assign, readonly) float catchSpeed;

@property (nonatomic, assign, readonly) float slowSpeed;

@property (nonatomic, assign, readonly) NSInteger FPSProbeSize;

@property (nonatomic, assign, readonly) BOOL isAdaptedWatermarkEnabled;

@property (nonatomic, assign, readonly) NSInteger startPlayAudioBufferThresholdInMilliseconds;

@property (nonatomic, assign, readonly) BOOL isBufferingEndIgnoreVideo;

@property (nonatomic, assign, readonly) NSInteger audioRenderDeviceType;

@property (nonatomic, assign, readonly) BOOL isJXCodecDropNALUEnabled;

@property (nonatomic, assign, readonly) BOOL isTCPFastOpenEnabled;

@property (nonatomic, assign, readonly) BOOL isVideoAutoCropEnabled;

@property (nonatomic, assign, readonly) BOOL shouldUseAudioPool;

@property (nonatomic, assign, readonly) BOOL shouldUseAudioGraphPool;

@property (nonatomic, assign, readonly) BOOL shouldEnableRenderStall;

@property (nonatomic, assign, readonly) BOOL shouldConfigPlayerAsynchronously;

@property (nonatomic, assign, readonly) NSInteger playerViewRenderType;

@property (nonatomic, assign, readonly) NSString * HTTPDNSServerHost;

@property (nonatomic, assign, readonly) BOOL isPacketDidReceiveCallbackEnabled;

@property (nonatomic, assign, readonly) BOOL isRepeatedDataDroppingEnabled;

@property (nonatomic, assign, readonly) BOOL isFrameWillRenderCallbackEnabled;

@property (nonatomic, assign, readonly) NSInteger droppingRepeatingDataDTSMaxDiff;

@property (nonatomic, assign, readonly) BOOL startRenderIgnoreWindowSize;

@property (nonatomic, assign, readonly) BOOL isSuperResolutionEnabled;

@property (nonatomic, copy, readonly) NSArray<NSString *> *_Nullable SRResolutionBlockList;

@property (nonatomic, assign, readonly) BOOL isPlayerLogCallbackEnabled;

@property (nonatomic, assign, readonly) BOOL shouldTryAllResolvedIPAddresses;

@property (nonatomic, assign, readonly) BOOL isTTPlayerCanPlayAtBackgroundWhenInPictureInPictureWrapper;

@property (nonatomic, assign, readonly) BOOL isAudioVolumeBalanceEnable;

@property (nonatomic, assign, readonly) float audioVolumeBalancePregain;

@property (nonatomic, assign, readonly) float audioVolumeBalanceThreshold;

@property (nonatomic, assign, readonly) float audioVolumeBalanceRatio;

@property (nonatomic, assign, readonly) float audioVolumeBalancePredelay;

@property (nonatomic, assign, readonly) BOOL isPTSSyncedSEINotificationEnabled;

@property (nonatomic, assign, readonly) NSString *_Nullable NTPServerName;

@property (nonatomic, assign, readonly) NSInteger startRenderCallbackTriggeringMode;

@property (nonatomic, assign, readonly) BOOL useRearPlayerCore;

@property (nonatomic, assign, readonly) NSInteger RTCFallbackThreshodInMilliseconds;

@property (nonatomic, assign, readonly) BOOL isAVStackEnabled;

@property (nonatomic, copy, readonly) NSArray<NSString *> *_Nullable formatFallbackList;

@property (nonatomic, assign, readonly) NSInteger stallRetryTimeIntervalInMilliseconds;

@property (nonatomic, assign, readonly) BOOL isDecodeMultiSEIEnabled;

@property (nonatomic, assign, readonly) BOOL isNotifySEIImmediatelyBeforeFirstFrameEnabled;

@property (nonatomic, assign, readonly) BOOL isMarkingParsedSEIEnabled;

@property (nonatomic, assign, readonly) BOOL isCMAFFastModeEnabled;

@property (nonatomic, assign, readonly) BOOL isCMAFVideoMPDRefreshEnabled;

@property (nonatomic, assign, readonly) BOOL isDroppingDTSRollbackFrameEnabled;

@property (nonatomic, copy, readonly) NSDictionary *_Nullable lowLatencyFLVDefaultStrategyMap;

@property (nonatomic, assign, readonly) BOOL isHandleBackgroundInAvViewEnebled;

@property (nonatomic, assign, readonly) BOOL isSkipSetSameWindowEnabled;

@property (nonatomic, assign, readonly) BOOL isAvoidUnnecessarySettingsConfigureEnabled;

@property (nonatomic, assign, readonly) BOOL isCacheVoiceIDEnabled;

@property (nonatomic, assign, readonly) BOOL isIgnoreBackgroundRenderStallEnabled;

@property (nonatomic, assign, readonly) BOOL isAudioClockOffsetEnabled;

@property (nonatomic, assign, readonly) NSInteger drmKeyRequestFailRetryTimes;

@property (nonatomic, assign, readonly) BOOL isSetupPlayerViewInAdvanceEnabled;

@property (nonatomic, copy, readonly) NSDictionary *_Nullable autoTestScript;

@property (nonatomic, assign, readonly) BOOL shouldLogToConsole;

@property (nonatomic, assign, readonly) BOOL shouldDrawBorderOfPlayerView;

@property (nonatomic, assign, readonly) BOOL bytevc1SoftwareDecodeForbiden;

@property (nonatomic, assign, readonly) BOOL isCanFallbackToSoftwareDecode;

@property (nonatomic, assign, readonly) BOOL shouldUseLiveStreamStrategySDK;

/// applog report switch
@property (nonatomic, assign, readonly) BOOL shouldReportByApplog;
/// use new session_id
@property (nonatomic, assign, readonly) NSInteger newSessionIdVersion;
@property (nonatomic, assign, readonly) NSInteger newEventIndex;

@property (nonatomic, assign, readonly) NSInteger forceUseMetalRender;

@property (nonatomic, assign, readonly) BOOL shouldIgnoreCheckMetalDevice;

@property (nonatomic, assign, readonly) BOOL allowToChangeLogCallbackValue;

@property (nonatomic, assign, readonly) BOOL shouldUseTraitObjectInVideo;

@property (nonatomic, assign, readonly) BOOL shouldUseTraitObjectInAudio;

@property (nonatomic, assign, readonly) NSInteger enablePreCreatedPlayer;

@property (nonatomic, assign, readonly) NSInteger enablePreparePreConnect;

@property (nonatomic, assign, readonly) NSInteger enablePlayerPrepareOptimize;

@property (nonatomic, assign, readonly) BOOL enablePlayerPostPrepare;

@property (nonatomic, assign, readonly) NSInteger playerPostPrepareCallStartMoment;

@property (nonatomic, assign, readonly) BOOL enableUseStopState;

@property (nonatomic, assign, readonly) NSInteger enableAudioSession;

@property (nonatomic, assign, readonly) NSInteger enableSetEffectUseLock;

@property (nonatomic, assign, readonly) BOOL disableStopInReset;

@property (nonatomic, assign, readonly) BOOL enableParseDNSNoBlock;

@property (nonatomic, assign, readonly) BOOL enablePlayerStopAsync;

@property (nonatomic, assign, readonly) BOOL updateTraitObjectOptionsBeforePlay;

@property (nonatomic, assign, readonly) BOOL updateTraitObjectOptionsWithoutCache;

@property (nonatomic, assign, readonly) BOOL shouldUseLiveCallbackTraitObject;

@property (nonatomic, assign, readonly) BOOL enablePreProcess;

@property (nonatomic, assign, readonly) BOOL shouldTryCorrectLiveStreamSessionID;

@property (nonatomic, assign, readonly) BOOL enableSetCommonTraceConfig;

@property (nonatomic, assign, readonly) BOOL enableReportPullRestart;

@end

@interface TVLSettingsManager (Monitoring)

@property (nonatomic, strong, readonly) NSDictionary *_Nullable settingsInfo;

@end

NS_ASSUME_NONNULL_END
