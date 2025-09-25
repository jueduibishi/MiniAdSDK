//
//  TVLPlayerItemPreferences.h
//  TTVideoLive
//
//  Created by chenzhaojie on 2018/12/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TVLPriority) {
    TVLPriorityLow = 0,
    TVLPriorityDefault = NSIntegerMax >> 1,
    TVLPriorityHigh = NSIntegerMax,
};

typedef NSString *_Nullable TVLPlayerItemPreferencesProperty;

OBJC_EXTERN TVLPlayerItemPreferencesProperty const TVLPlayerItemPreferencesPropertySourceType;
OBJC_EXTERN TVLPlayerItemPreferencesProperty const TVLPlayerItemPreferencesPropertyVideoCodecType;
OBJC_EXTERN TVLPlayerItemPreferencesProperty const TVLPlayerItemPreferencesPropertyFormatType;
OBJC_EXTERN TVLPlayerItemPreferencesProperty const TVLPlayerItemPreferencesPropertyProtocolType;
OBJC_EXTERN TVLPlayerItemPreferencesProperty const TVLPlayerItemPreferencesPropertyResolutionType;
OBJC_EXTERN TVLPlayerItemPreferencesProperty const TVLPlayerItemPreferencesPropertyParams;

typedef NSString *_Nullable TVLPreferencesDataKey;

OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeyID;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeyURL;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeyMediaSourceType;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeyMediaFormatType;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeyMediaResolutionType;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeySDKParams;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeyHTTPHeaders;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeySecretKey;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeyAppId;
OBJC_EXTERN const TVLPreferencesDataKey TVLPreferencesDataKeyCommonNeptuneTrace;

// MARK: -

typedef NSString *_Nullable TVLMediaSourceType;

OBJC_EXTERN const TVLMediaSourceType TVLMediaSourceTypeMain;
OBJC_EXTERN const TVLMediaSourceType TVLMediaSourceTypeBackup;

// MARK: -

typedef NSString *_Nonnull TVLVideoCodecType;

OBJC_EXTERN const TVLVideoCodecType TVLVideoCodecTypeH264;
OBJC_EXTERN const TVLVideoCodecType TVLVideoCodecTypeByteVC1;
OBJC_EXTERN const TVLVideoCodecType TVLVideoCodecTypeVVC;

// MARK: -

typedef NSString *_Nullable TVLMediaFormatType;

OBJC_EXTERN const TVLMediaFormatType TVLMediaFormatTypeFLV;
OBJC_EXTERN const TVLMediaFormatType TVLMediaFormatTypeM3U8;
OBJC_EXTERN const TVLMediaFormatType TVLMediaFormatTypeCMAF;
OBJC_EXTERN const TVLMediaFormatType TVLMediaFormatTypeDASH;
OBJC_EXTERN const TVLMediaFormatType TVLMediaFormatTypeLLASH;
OBJC_EXTERN const TVLMediaFormatType TVLMediaFormatTypeLLS;
OBJC_EXTERN const TVLMediaFormatType TVLMediaFormatTypeTSL;
OBJC_EXTERN const TVLMediaFormatType TVLMediaFormatTypeAVPH;

// MARK: -

typedef NSString *_Nullable TVLMediaProtocolType;

OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeTCP;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeTLS;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeQUIC;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeQUICU;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeKCP;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeRTP;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeH2;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeH2Q;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeH2QU;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeUDPSDP;
OBJC_EXTERN const TVLMediaProtocolType TVLMediaProtocolTypeQUICSDP;

// MARK: -

typedef NSString *_Nullable TVLMediaResolutionType;

OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeUnknow;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeAuto;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeOrigin;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeLD;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeSD;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeHD;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeFHD;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeUHD;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeMD;
OBJC_EXTERN const TVLMediaResolutionType TVLMediaResolutionTypeAudioOnly;

// MARK: -

typedef NSString *_Nullable TVLPreferencesParams;
typedef NSString *_Nullable TVLPreferencesSuggestProtocol;

// MARK: -
typedef NSString *_Nullable TVLMediaDRType;

OBJC_EXTERN const TVLMediaDRType TVLMediaDRTypeUnknow;
OBJC_EXTERN const TVLMediaDRType TVLMediaDRTypeHDR;
OBJC_EXTERN const TVLMediaDRType TVLMediaDRTypeSDR;

//MARK: -

/**
 A TVLPlayerItemPreferences object contains some resource info of a player item.
 */
@interface TVLPlayerItemPreferences : NSObject

@property (nonatomic, assign, readonly) NSUInteger ID;

@property (nonatomic, copy, readonly) TVLMediaSourceType sourceType;

@property (nonatomic, copy, readonly) TVLVideoCodecType videoCodecType;

@property (nonatomic, copy, readonly) TVLMediaFormatType formatType;

@property (nonatomic, copy, readonly) TVLMediaProtocolType protocolType;

@property (nonatomic, copy, readonly) TVLMediaDRType DRType;

@property (nonatomic, copy, readonly) NSString *_Nullable pushResolution;

@property (nonatomic, assign) BOOL protocolDowngraded;

@property (nonatomic, assign) BOOL ignoreSuggestedProtocolType;

@property (nonatomic, assign) BOOL LSSSuggestQuic;

@property (nonatomic, copy, readonly) TVLMediaResolutionType resolutionType;

@property (nonatomic, copy, readonly) TVLPreferencesParams params;

/// sdk_params
@property (nonatomic, copy, readonly) NSDictionary *_Nullable options;

@property (nonatomic, copy, readonly) NSDictionary *_Nullable HTTPHeaders;

@property (nonatomic, strong) NSDictionary *_Nullable HTTPPorts;

@property (nonatomic, strong) NSDictionary *_Nullable RTMPPorts;

@property (nonatomic, assign) TVLPriority priority;

@property (nonatomic, assign, getter=isHidden) BOOL hidden;

@property (nonatomic, assign, getter=isAdaptiveEnabled) BOOL adaptiveEnabled;

@property (nonatomic, assign, getter=isDefaultSelectd) BOOL defaultSelectd;

@property (nonatomic, assign, readonly) NSInteger defaultVideoBitrateForLLASH;

@property (nonatomic, assign, readonly) NSInteger defaultVideoBitrateInKbps;

@property (nonatomic, assign, readonly) NSInteger defaultVideoBitrate;

@property (nonatomic, assign, readonly) NSInteger GOPDurationInMillseconds;

@property (nonatomic, copy, readonly) TVLMediaFormatType suggestedFormatType;

@property (nonatomic, assign, readonly) BOOL supportsTimeShift;

@property (nonatomic, assign, readonly) BOOL allowsFormatFallback;

@property (nonatomic, assign, readonly) BOOL isVRModeAvailable;

@property (nonatomic, assign, readonly) NSInteger timeShiftLowerBoundInSeconds;

@property (nonatomic, assign) NSInteger timeShiftInSeconds;

@property (nonatomic, assign, getter=isUseFastOpenDurationFromSetAPI) BOOL useFastOpenDurationFromSetAPI;

@property (nonatomic, assign, getter=getFastOpenDuration) NSInteger fastOpenDuration;

@property (nonatomic, assign) BOOL enableLatencyNetworkAdaptOnRetry;

// If non null then this stream is an encryted ,otherwise is not.
@property (nonatomic, copy, readonly) NSString *_Nullable secretKey;

@property (nonatomic, assign) int cmafAbrPts;

@property (nonatomic, copy, readonly) NSString *_Nullable appId;

@property (nonatomic, assign, readonly) BOOL enableUseSDR2HDR;

@property (nonatomic, copy) NSString* commonNeptuneTrace;

@property (nonatomic, assign) BOOL enableGetConnectionInfo;

/**
 A convenience method create a instance with all property undefined.
 
 @return A preferences object with default values.
 */
+ (instancetype _Nonnull)defaultPreferences;

+ (instancetype _Nonnull)preferencesWithData:(NSDictionary<TVLPreferencesDataKey, id> *_Nullable)data;

- (void)updateOptionsWithData:(id)data;

- (NSString*)getStreamSuffix:(NSString*)url;

- (NSArray<NSURLQueryItem *> *_Nullable)getUncommonQueryWithSDKParams;

- (BOOL)isEqualToPreferences:(TVLPlayerItemPreferences *_Nonnull)preferences requiredProperties:(NSArray<TVLPlayerItemPreferencesProperty> *_Nullable)requiredProperties;

- (BOOL)isEqualToPreferences:(TVLPlayerItemPreferences *_Nonnull)preferences ignoreProperties:(NSArray<TVLPlayerItemPreferencesProperty> *_Nullable)ignoreProperties;

@end

@interface TVLPlayerItemPreferences (SVC)

@property (nonatomic, assign, readonly, getter=isSVCAvailable) BOOL SVCAvailable;

@property (nonatomic, assign, getter=isSVCEnabled) BOOL SVCEnabled;

@property (nonatomic, assign) NSInteger discardMaxTemporalIdOffset;

@property (nonatomic, assign) NSInteger discardInterval;

@end

NS_ASSUME_NONNULL_END
