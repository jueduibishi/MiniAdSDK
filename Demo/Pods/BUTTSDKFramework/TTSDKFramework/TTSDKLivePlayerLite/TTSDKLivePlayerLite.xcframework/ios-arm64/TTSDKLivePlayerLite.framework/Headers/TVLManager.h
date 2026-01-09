//
//  TVLManager.h
//  Pods
//
//  Created by zhongshaofen on 2017/7/18.
//
//

#import <Foundation/Foundation.h>
#import "VeLivePlayer.h"

@interface TVLManager (Strategy)

/**
 Try all IP addresses resolved by DNS or not. You are supposed to set this YES when single play URL only. Default is NO;
 */
@property (nonatomic, assign) BOOL shouldTryAllResolvedIPAddresses;

/**
 Allows resolution degrade or not. Default is NO;
 */
@property (nonatomic, assign) BOOL allowsResolutionDegrade;

/**
 Allows Forbid resolution degrade. Default is NO;
 */
@property (nonatomic, assign) BOOL shouldForbidResolutionDegrade;

/**
 Stall count that triggerring resolution degrade during a stream playing. Default is 4;
 */
@property (nonatomic, assign) NSInteger resolutionDegradeConditionStallCount;

/**
 Allows ByteVC1 degrade to H.264 if possible or not. Default is NO;
 */
@property (nonatomic, assign) BOOL allowsByteVC1Degrade;

/**
 Start up resolution degrade switch, Default is NO
 */
@property (nonatomic, assign) BOOL enableStartUpResolutionDegrade;

/**
 Support start up resolution degrade Thresh, unit ms, Default 0
 */
@property (nonatomic, assign) int startUpResolutionDegradeTimeThreshMs;

/**
 Suport start up resolution degrade short edge as Min(width, height)
 */
@property (nonatomic, assign) int startUpResolutionDegradeShortEdge;

@property (nonatomic, assign) int enableReportAlgoSei;

/**
 Recommended degrade sequence of resolution.
 */
+ (NSArray<TVLMediaResolutionType> *_Nonnull)recommendedResolutionDegradeSequence;

/**
 Provide a mapping table of IP <-> origin host. Only when user resolve domain themselves and use IP address to play dircetly.
 */
@property (nonatomic, strong) NSDictionary *_Nullable ipMappingTable;


/**
 * @param SDKType Type of the sdk; 0: VeLivePlayer, 1:VeLivePusher, 2:LiveIO, 3:RTSPlayer
 * @param command
 * @param hashCode Indicate the instance of the SDK (Optional)
 * @param info Extra info, Must be a Json format.
 */
+ (NSDictionary *_Nullable)executeCommand:(NSInteger)SDKType command:(NSInteger)command hashCode:(NSInteger)hashCode info:(NSDictionary *_Nullable) info;

@end

@interface TVLManager (SEI)

/**
 Delay calculated by timestamp of SEI. This property is key-value observable. Default is 0, and will not change if there is no timestamp info in SEI.
 */
@property (nonatomic, readonly, assign) NSInteger delay;

@end

@interface TVLManager (HTTPAdaptiveStreaming)

/**
 Switch resolution without interrupting current streaming. HAS valid only.
 */
- (void)switchToResolution:(TVLMediaResolutionType)resolution completion:(TVLHTTPAdaptiveStreamingSwitchCompletion _Nullable)completion;

/**
  * set toggle FastOpenDuration
  *
  * @param fastOpenDuration
  */
- (void)setFastOpenDuration:(NSInteger) fastOpenDuration;
@end

@interface TVLManager (SVC)

- (void)updateSVCParamsWithEnabled:(BOOL)enabled discardMaxTemporalIdOffset:(NSInteger)discardMaxTemporalIdOffset discardInterval:(NSInteger)discardInterval;

@end

@interface TVLManager (Debugging)

@property (nonatomic, readonly, assign) CGFloat renderingFPS;

@property (nonatomic, readonly, copy) NSDictionary *_Nullable debugInfoItems;

@property (nonatomic, readonly, copy) NSDictionary *_Nullable formattedDebugInfoItems;

@property (nonatomic, readonly, copy) NSString *_Nullable formattedDebugInfo;

@property (nonatomic, readonly, copy) NSDictionary *_Nullable connectionInfo;

/**
  thread safe
 */
@property (nonatomic, readonly, copy) NSDictionary *_Nonnull liveInfoItems;

@end

@interface TVLManager (Monitoring)

/**
 The  bigger one of current audio and video buffer.
 */
@property (nonatomic, readonly, assign) NSInteger currentBufferInMilliSeconds;

@property (nonatomic, readonly, assign) NSInteger maxCacheDurationInSeconds;

@property (nonatomic, readonly, assign) BOOL isBufferingQueueFull;

@property (nonatomic, assign) BOOL shouldReportTimeSeries;

@property (nonatomic, assign) BOOL shouldReportAudioFrame;

@property (nonatomic, assign) BOOL enableAudioProcessorInPlaying;

@property (nonatomic, assign) BOOL shouldUseVideoFrameInViceView;

@property (nonatomic, copy) NSString *_Nullable commonTag;

@property (nonatomic, assign) BOOL enableAudioRecording;

+ (nullable NSDictionary *)liveStreamInfoWithMonitorLog:(nonnull NSDictionary *)monitorLog;

- (void)setProjectKey:(NSString *_Nullable)projectKey;

- (void)setPreviewFlag:(BOOL)isPreview;

@end

@interface TVLManager (Deprecating)

+ (NSArray<TVLMediaResolutionType> *_Nonnull)recommendedrResolutionDegradeSequence DEPRECATED_MSG_ATTRIBUTE("Will be deprecated.");

- (void)closeAsync DEPRECATED_MSG_ATTRIBUTE("Will be deprecated, and you are highly recommended to close sasynchronously with GCD methods as this method does.");

- (BOOL)isManagerOfPlayer:(id _Nullable)player;

@end
