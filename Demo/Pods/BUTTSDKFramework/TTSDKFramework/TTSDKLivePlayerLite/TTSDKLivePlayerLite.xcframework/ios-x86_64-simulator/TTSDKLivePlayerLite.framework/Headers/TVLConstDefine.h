//
//  TVLConstDefine.h
//  Pods
//
//  Created by zhongshaofen on 2017/7/19.
//
//

#pragma once

NS_ASSUME_NONNULL_BEGIN

// TODO: Divide into related modules.

OBJC_EXTERN const NSInteger kInvalidTimeShiftLowerBound;

typedef NS_ENUM(NSInteger, TVLStreamType) {
    TVLStreamTypeUnknown = -1,
    TVLStreamTypeAudio,
    TVLStreamTypeVideo,
};

typedef NS_ENUM(NSInteger, TVLAVStreamType) {
    TVLVideoStream,
    TVLAudioStream,
    TVLSubtStream,
    TVLStreamNB,
};

typedef NS_ENUM(NSInteger, TVLABRResolutionChangeType) {
    TVLABRResolutionChangeUnknow,
    TVLABRResolutionChangeAuto,
    TVLABRResolutionChangeSmoothlySwitch,
};

typedef NSString *TVLABRSwitchUserInfoKey;

FOUNDATION_EXPORT TVLABRSwitchUserInfoKey const TVLABRStrategyTypeKey;
FOUNDATION_EXPORT TVLABRSwitchUserInfoKey const TVLABRStrategySubtypeKey;

typedef NS_ENUM(NSUInteger, TVLABRSwitchPermissionRequestResult) {
    TVLABRSwitchPermissionRequestApproved = 0,
    TVLABRSwitchPermissionRequestRejectedForFixedResolution,
    TVLABRSwitchPermissionRequestRejectedForSuggestedResolutionInvalid,
};

typedef NS_ENUM(NSUInteger, TVLABRStrategyType) {
    TVLABRStrategyTypePerformance,  // Focus on the performance of the player.
    TVLABRStrategyTypeBandwidth,    // Focus on more reasonable bandwidth usage.
    TVLABRStrategyTypeQuality,      // Focus on displaying the best visual quality to the end-user.
};

typedef NS_ENUM(NSUInteger, TVLABRStrategySubtype) {
    TVLABRStrategySubtypeFakeResolution = 0,
};

typedef NSDictionary *_Nullable(^TVLOptimumNodeInfoRequest)(NSString *_Nonnull playURL);

typedef void(^TVLHTTPAdaptiveStreamingSwitchCompletion)(BOOL succeeded, NSError *_Nullable error, NSDictionary *_Nullable userInfo);

typedef void(^TVLNetworkRequestCompletion)(NSError *_Nullable error, id _Nullable jsonObj);

typedef NSDictionary *_Nullable(^TVLStrategyInfoRequest)(NSString *_Nullable command, NSDictionary *_Nullable strategyRequestInfo);

typedef void(^TVLSwitchResolutionCompletion)(BOOL succeeded, NSError *_Nullable error, NSDictionary *_Nullable userInfo);

typedef NS_ENUM(NSUInteger, TVLPictureType) {
    TVLPictureTypeNone = 0,   ///< Undefined
    TVLPictureTypeI,          ///< Intra
    TVLPictureTypeP,          ///< Predicted
    TVLPictureTypeB,          ///< Bi-dir predicted
    TVLPictureTypeS,          ///< S(GMC)-VOP MPEG-4
    TVLPictureTypeSI,         ///< Switching Intra
    TVLPictureTypeSP,         ///< Switching Predicted
    TVLPictureTypeBI,         ///< BI type
};

typedef NS_ENUM(NSUInteger, TVLLogLevel) {
    TVLLogLevelVerbose,
    TVLLogLevelDebug,
    TVLLogLevelInfo,
    TVLLogLevelWarn,
    TVLLogLevelError,
    TVLLogLevelNone,
};

typedef NS_ENUM(NSUInteger, TVLManagerState) {
    TVLManagerStateInitialized,
    TVLManagerStatePreparing,
    TVLManagerStateStarted,
    TVLManagerStatePaused,
    TVLManagerStateStopped,
    TVLManagerStateClosed,
};

typedef void(^TVLLogCallback)(TVLLogLevel level, NSString *_Nullable tag, NSString *_Nullable log);

typedef NS_ENUM(NSInteger, TVLPlayerLoadState) {
    TVLPlayerLoadStateUnknown,
    TVLPlayerLoadStateStalled,
    TVLPlayerLoadStatePlayable,
    TVLPlayerLoadStateError,
};

// LOB(line of business)
typedef NS_ENUM(NSInteger, TVLPlayerSpecifySceneForLOB) {
    TVLPlayerSpecifySceneDefault            = 0, // default.
    TVLPlayerSpecifySceneLowLatency         = 1, // rtm
    TVLPlayerSpecifySceneFastFirstFrame     = 2  // quic
    // others scenes....
};

typedef NS_ENUM(NSInteger, TVLPlayerStallReason) {
    TVLPlayerStallNone = -1,
    TVLPlayerStallNetwork,
    TVLPlayerStallDecoder,
    TVLPlayerStallReasonSDKBase = 1000,
    TVLPlayerStallWhenRetry,
};

typedef NS_ENUM(NSInteger, TVLStallEndReason) {
    TVLStallEndReasonInvalidValue,
    TVLStallEndReasonInterrupted = 0,
    TVLStallEndReasonBufferringEnd,
    TVLStallEndReasonRetrySuccess,
};

typedef NS_ENUM(NSInteger, TVLPlayerViewRenderType) {
    TVLPlayerViewRenderTypeInvalid                  = -1,
    TVLPlayerViewRenderTypeOpenGLES                 = 0,
    TVLPlayerViewRenderTypeMetal                    = 1,
    TVLPlayerViewRenderTypeSampleBufferDisplayLayer = 2,
    TVLPlayerViewRenderTypeOutput                   = 100,
};

typedef NS_ENUM(NSInteger, TVLPlayerViewRotateType) {
    TVLPlayerViewRotateTypeNone = 0,
    TVLPlayerViewRotateType90   = 1,/// 顺时针90度
    TVLPlayerViewRotateType180  = 2,
    TVLPlayerViewRotateType270  = 3,
};

typedef NS_ENUM(NSInteger, TVLPlayerPlaybackState) {
    TVLPlayerPlaybackStateUnknown,
    TVLPlayerPlaybackStateStopped,
    TVLPlayerPlaybackStatePlaying,
    TVLPlayerPlaybackStatePaused,
    TVLPlayerPlaybackStateError,
};

typedef NS_ENUM(NSInteger, TVLRetryReason) {
    TVLRetryReasonUnknown = -1000,
    TVLRetryReasonStall = -1001,
    TVLRetryReasonError = -1002,
    TVLRetryReasonBackgroundSwitch = -1003,
    TVLRetryReasonNetworkSwitching = -1004,
};

typedef NS_ENUM(NSUInteger, TVLImageLayoutType) {
    TVLLayoutTypeAspectFit,
    TVLLayoutTypeToFill,
    TVLLayoutTypeAspectFill
};

typedef NS_ENUM(NSInteger, TVLViewScalingMode) {
    TVLViewScalingModeNone,       // No scaling
    TVLViewScalingModeAspectFit,  // Uniform scale until one dimension fits
    TVLViewScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
    TVLViewScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds
};

typedef NS_ENUM(NSInteger, TVLPlayerViewAlignMode) {
    TVLPlayerViewAlignModeCenter = 0,
    TVLPlayerViewAlignModeLeftTop = 1,
    TVLPlayerViewAlignModeLeftCenter = 2,
    TVLPlayerViewAlignModeLeftBottom = 3,
    TVLPlayerViewAlignModeTopCenter = 4,
    TVLPlayerViewAlignModeBottomCenter = 5,
    TVLPlayerViewAlignModeRightTop = 6,
    TVLPlayerViewAlignModeRightCenter = 7,
    TVLPlayerViewAlignModeRightBottom = 8,
};

typedef NS_ENUM(NSUInteger, TVLPlayerType) {
    TVLPlayerTypeSystem       = 0, // system player
    TVLPlayerTypeVanGuard     = 1, // TTPlayerSDK
    TVLPlayerTypeRearGuard    = 2, // TTPlayerRearSDK backup version , need subspec DualCore In podfile
};

typedef NS_ENUM(NSInteger, TVLStreamAbnormalType) {
    TVLStreamAbnormalTypeNoError                = -1,
    TVLStreamAbnormalTypeDataDropped            = 0,
    TVLStreamAbnormalTypeDataRepeating          = 1,
    TVLStreamAbnormalTypeSEIUnavailable         = 2,
    TVLStreamAbnormalTypeSEIMayLost             = 3,
    TVLStreamAbnormalTypeSEIIndexRollback       = 4,
};

typedef NS_ENUM(NSInteger, TVLStreamDRMType) {
    TVLStreamDRMTypeNone                        = -1,
    TVLStreamDRMTypeOwn                         = 0,
    TVLStreamDRMTypeIntertrust                  = 1     //Third Part DRM Type
};

typedef NS_ENUM(NSInteger, TVLABRAction) {
    TVLABRActionUnknown = 0,
    TVLABRActionDowngrade = 1,
    TVLABRActionUpgrade = 2,
};

typedef NS_ENUM(int, TVLPlayerBusinessIdentity) {
    TVLPlayerBusinessIdentityLive = 0,
    TVLPlayerBusinessIdentityVOD,
    TVLPlayerBusinessIdentityRTC,
};

typedef NS_ENUM(NSInteger, TVLVRScopicType) {
    TVLVRScopicTypeUnknown = -1,
    TVLVRScopicTypeMono,
    TVLVRScopicTypeStereo,
};

typedef NS_ENUM(NSInteger, TVLPlayerDebugState) {
    TVLPlayerStateUnknown = 0,
    TVLPlayerDnsParsing,
    TVLPlayerTCPConnecting,
    TVLPlayerTCPConnected,
    TVLPlayerTCPFirstPacket,
    TVLPlayerFormatProbing,
    TVLPlayerFirstMediaPackage,
        
    TVLPlayerDecoderInitialing,
    TVLPlayerRenderInitialing,
    TVLPlayerFirstFrameDisplayed,
          
    //get from state in sdk
    TVLPlayerIdle,
    TVLPlayerSDKDnsParsing,
    TVLPlayerBuffering,
    TVLPlayerPlaying,
};

typedef NS_ENUM(NSInteger, TVLSRDynamicType) {
    TVLSRUnKnown = -1,
    TVLSRDynamicDisabled,
    TVLSRDynamicOneAndAHalfTimes,
    TVLSRDynamicDouble,
};

typedef NS_ENUM(NSInteger,TVLFilterType) {
    TVLFilterTypeEmpty,
    TVLFilterTypeDefault,
    TVLFilterTypeLookupTable,
    TVLFilterTypeYUVtoRGB,
    TVLFilterTypeLens,
    TVLFilterTypeCrop,
    TVLFilterTypeRGBtoYUV,
    TVLFilterTypeVR,
    TVLFilterTypeBMFVideoSRLut,
    TVLFilterTypeGaussianBlur,
    TVLFilterTypeBMP,
    TVLFilterTypeSDR2HDR,
    TVLFilterTypeDynamicGaussianBlur,
    TVLFilterTypeBMFVideoSharpLut,
    TVLFilterTypeBmfHDRLightnessNormaliza,
    TVLFilterTypePanorama,
    TVLFilterTypeHDRBrightNormalize,
    TVLFilterTypeBefComposer,
    TVLFilterTypeBmfVQScore
};

typedef NS_ENUM(NSInteger, TVLProcessorErrorType) {
    TVLProcessorNoError = 0,
    TVLProcessorUnknownError,
    TVLProcessorMetalPipelineError,
    TVLProcessorInitError,
    TVLProcessorTextureError,
    TVLProcessorClassError,
    TVLProcessorAllocError,
    TVLProcessorLifeIDError,
    TVLProcessorProcessingError,
    TVLProcessorAssetsError,
    TVLProcessorModelDownloadError
};

// Global static
typedef NS_ENUM(NSInteger, TVLKey4GlobalValue) {
    TVLGSKeyUseBaseThread_BOOL             = 0,
    TVLGSKeyUseThreadPool_BOOL             = 1,
    TVLGSKeyThreadPoolSize_INT             = 2,
    TVLGSKeyThreadSafeRefSwitcher          = 3,
    TVLGSKeyEnableGlobalMuteFeature        = 4,
    TVLGSKeyGlobalMute                     = 5, // is start global mute
    TVLGSKeyLooperOpenWait                 = 6,
    TVLGSKeyQosLooper                      = 7,
    TVLGSKeyLooperDetach                   = 8,
    TVLGSKeySetStateInOpenFail             = 9,
    TVLGSKeyGlobalIgnoreGlActive           = 22,
    TVLGSKeyEnableCheckAudioSession        = 29,
};

typedef NS_ENUM(NSInteger, TVLPlayerLiveStrategyType) {
    LIVESTRATEGY_PREDICT_BANDWIDTH = 0,
};

typedef NS_ENUM(NSUInteger, TVLNodeLiveStrategySdkType) {
    TVLLiveCoreSdk = 1,
    TVLLivePlayerSdk,
};

typedef NS_ENUM(NSInteger, TVLPlayerSmoothSwitchReason) {
    TVLSmoothlySwitchUnknow = -1,
    TVLSmoothlySwitchByUser,
    TVLSmoothlySwitchByStrategy,
};

typedef NS_ENUM(NSInteger, TVLSmoothlySwitchFailedReason) {
    TVLSmoothlySwitchFailedUnsupportedRes = -10000,           // smooth resolution not allowed in this preference
    TVLSmoothlySwitchFailedSameRes = -10001,                 //same resolution request with current resolution
    TVLSmoothlySwitchFailedInvalidPlayerStatus = -10002,     // Invalid player status will forbid this request
    TVLSmoothlySwitchFailedNotSupportSmooth = -10003,        // Not support smooth switch
    TVLSmoothlySwitchFailedConflictWithPlayer = -10004,      // conflict with player strategy
};

typedef NS_ENUM(NSInteger, VeLiveStreamDataCompareResult) {
    VeLiveCompareSuccess,
    VeLiveCompareCommonError,
    VeLiveCompareErrorWithStreamName,
    VeLiveCompareErrorWithResolution,
};

typedef NS_ENUM(NSInteger, VeLivePlayerBMFKernalType) {
    VeLivePlayerBMFUnknow = -1,
    VeLivePlayerBMFV1 = 0,  // SR_V1, support video_sr、image_sr.
    VeLivePlayerBMFV2 = 1,
    VeLivePlayerBMFNN = 2,
    VeLivePlayerBMFV1_ROI = 3, //SR_V1, support video_roi_sr.
    VeLivePlayerBMFV1_OPT = 4, // SR_V1 optimized version, support image_sr、video_sr(NV12)、video_roi_sr(NV12).
    VeLivePlayerBMFV1_FLEX = 5, // support dynamic resolution image sr.
    VeLivePlayerBMFV1_NEW = 6, // not use CVPixelBufferRef
};

typedef NS_ENUM(NSInteger, TVLSwitchNetworkResult) {
    TVLSwitchNetworkSucceed = 0,
    TVLSwitchNetworkNoPermission = -1,
    TVLSwitchNetworkNoNeed = -2,
    TVLSwitchNetworkNoNetwork = -3,
};


typedef NS_ENUM(NSInteger, TVLNetworkBehavior) {
    TVLNetworkBehaviorHighPLR = -5,
    TVLNetworkBehaviorHighRTT = -4,
    TVLNetworkBehaviorMuchRetry = -3,
    TVLNetworkBehaviorMuchStall = -2,
    TVLNetworkBehaviorWeakNetwork = -1,
    TVLNetworkBehaviorReserved = 0,
    TVLNetworkBehaviorGoodNetwork = 1,
};

typedef NS_ENUM(NSInteger, TVLSessionIDVersion) {
    TVLSessionIDVersion0,
    TVLSessionIDVersion1,
    TVLSessionIDVersion2
};

extern NSString *_Nullable const kLiveErrorMessageKey;
extern NSErrorDomain _Nullable const kLiveErrorDomain;

NS_ASSUME_NONNULL_END
