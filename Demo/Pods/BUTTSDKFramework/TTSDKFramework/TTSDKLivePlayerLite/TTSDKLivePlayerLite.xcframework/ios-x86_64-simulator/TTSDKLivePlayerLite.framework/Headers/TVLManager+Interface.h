//
//  TVLManager+Interface.h
//  TTVideoLive
//
//  Created by bytedance on 2023/3/26.
//

#ifndef TVLManager_Interface_h
#define TVLManager_Interface_h

#import "TVLProtocol.h"
#import "TVLPlayerItem.h"
#import "TVLConstDefine.h"
#import "VeLivePlayerData.h"
#import "VeLivePlayerStreamData.h"

@interface TVLManager : NSObject

/**
 This method is used to activate the render
 You should call this method in app delegate's applicationDidBecomeActive: method, or it may result
 in no picture.
 */
+ (void)startOpenGLESActivity;

/**
 This method is used to deactive the render
 You should call this method in app delegate's applicationWillResignActive: method, or it may leads
 to crash
 */
+ (void)stopOpenGLESActivity;


/**
 Set Gloabl Value By Key
 */
+ (void)setGloablValue:(id _Nonnull )value forKey:(int)key;

/**
 Callback to get log of SDK. Considering efficiency, this property dosen't importIt any lock, and it is supposed to be set only once. Default is nil.
 */
@property (class, nonatomic, copy) TVLLogCallback _Nullable logCallback;

/**
 The delegate of a TVLManager instance to respond to playback related messages.
 */
@property (nonatomic, weak) id<TVLDelegate> _Nullable delegate;

/**
 Container of video content.
 */
@property (nonatomic, strong, readonly) UIView *_Nonnull playerView;

/**
 Render type. Default is TVLPlayerViewRenderTypeOpenGLES.
 */
@property (nonatomic, assign) TVLPlayerViewRenderType playerViewRenderType;

/**
 Video crop area. Default is CGRectNull, which means no crop.
 */
@property (nonatomic, assign) CGRect videoCropAreaFrame;

/**
 Video content area. Which depends on the scale mode of player view.
 */
@property (nonatomic, assign, readonly) CGRect videoAreaFrame;

/**
 Align mode of player view. Default is TVLPlayerViewAlignModeCenter.
 */
@property (nonatomic, assign) TVLPlayerViewAlignMode playerViewAlignMode;


/**
 Rotation of player view. Default is TVLPlayerViewRotateTypeNone.
 */
@property (nonatomic, assign) TVLPlayerViewRotateType playerViewRotateType;


/**
 Load state of player.
*/
@property (nonatomic, assign, readonly) TVLPlayerLoadState playerLoadState;

/**
 Player manager api state
 */
@property (nonatomic, assign, readonly) TVLManagerState state;

/**
 This property indicates the media is playing or not.
 */
@property (nonatomic, assign, readonly) BOOL isPlaying;

/**
 SDK provides DNS resolution and caching, and you can choose to use it or not.
 This strategy is well supported with HTTP streaming, but might failed with RTMP because not all media sever supports IP direct access. Default is YES.
 */
@property (nonatomic, assign) BOOL shouldUseLiveDNS;

/**
 Apply HTTP DNS. Default is NO.
 */
@property (nonatomic, assign, getter=isPreferredToHTTPDNS) BOOL preferredToHTTPDNS;

/**
 Indicates the player decodes with hardware or software. Default is NO, that says software decoding is default.
 */
@property (nonatomic, assign, getter=isHardwareDecode) BOOL hardwareDecode;

/**
 Allows audio rendering or not. Works for self-developed player only. Default is YES;
 */
@property (nonatomic, assign) BOOL allowsAudioRendering;

/**
 Allows video rendering or not. Works for self-developed player only and set before -play method called. Default is YES;
 */
@property (nonatomic, assign) BOOL allowsVideoRendering;

/**
 Optimum node info provided by this property, and default is nil. If you want to use node optimum, you are supposed to import NodeProber.
 */
@property (nonatomic, copy, nullable) TVLOptimumNodeInfoRequest optimumNodeInfoRequest;

/**
 SDK gets strategy via this block , and default is nil. If you want to use it, you are supposed to import NodeProber.
 */
@property (nonatomic, copy, nullable) TVLStrategyInfoRequest strategyInfoRequest;

/**
 The player’s current player item.
 */
@property (nonatomic, strong, readonly) TVLPlayerItem *_Nullable currentItem;

/**
 The value of this property is an error object that describes what caused the receiver to no longer be able to play items. The value of this property is nil if no error happened.
 */
@property (nonatomic, strong, readonly) NSError *_Nullable error;

/**
 The current playback state of the player.
 */
@property (nonatomic, assign, readonly) TVLPlayerPlaybackState playbackState;

/**
 Synchronize clock with NTP is enabled or not. Default is NO.
 */
@property (nonatomic, assign, getter=isClockSynchronizationEnabled) BOOL clockSynchronizationEnabled DEPRECATED_MSG_ATTRIBUTE("Own ClockSync has been deprecated.");

/**
 A NTP provide by app (middle). Default is NO.
 */
@property (nonatomic, assign, getter=isAppNTPEnabled) BOOL appNTPEnabled;

/**
 A NTP time provide by app.
 */
@property (nonatomic, assign) float ntpTimeDiffByApp;

/**
 The scale mode of player view. Default is TVLViewScalingModeAspectFit.
 */
@property (nonatomic, assign) TVLViewScalingMode playerViewScaleMode;

/**
 Media volume.
 */
@property (nonatomic, assign) float volume;

/**
 Video Processing status
 */
@property (nonatomic, readonly) BOOL didVideoProcessingOpened;

/**
 You can use it to enable ignore audio Interruption
 */
@property (nonatomic, assign) BOOL enableIgnoreAudioInterruption;

/**
 get app info delegate
 */
@property (nonatomic, weak, nullable) id<TVLAppInfoFetcher> appInfoFetcher;

/*
 You can use it to enable ignore audio Interruption
 */
@property (nonatomic, assign) BOOL enableReplacePauseToStopInRtm;

/**
 set bizSessionID, need set before play,preload,replaceCurrentItemWithPlayerItem,replaceCurrentItemWithURL
*/
@property (nonatomic, copy) NSString *_Nullable bizSessionId;

/**
 warning: this feature only support on sys ver > iOS 14.0
 default is NO , if your player will on a  PictureInPicture wrapper  at sometime , you can set this YES
 if set this YES , playerView will check if itSelf  on a PictureInPicture wrapper or not , if the result is true , the player can still play on background  app mode ,
 so this prop is just a config that determin if  playerView should check or not , this prop cannot determin if the player can still play on background  app mode
 Only condition
 */
@property (nonatomic, assign) BOOL supportPictureInPictureMode API_AVAILABLE(ios(14.0));


/**
 If you use the smooth switch function, you can get the current resolution by it when smooth switch happened.
 the default value is @"none", only update when the smooth switch happened.
 */
@property (nonatomic, strong, readonly) TVLMediaResolutionType currentSmoothResolution;

/**
 you can get that video render succed in player core from this property. This can help you to decide whether to layout the player view advanced. which can optimize the render cost time.
 */
@property (nonatomic, readonly) BOOL videoFrameDidRender;


/**
 observe loudness info in sei
 */
@property (nonatomic, weak, nullable) id<TVLLoudnessObserver> loudnessObserver;


/**
 observe audio info
 */
@property (nonatomic, weak, nullable) id<TVLAudioInfoObserver> audioVolumeObserver;

/**
 The designated initializer. Returns a newly initialized TVLManager object with the specific player type.

 @param isOwn Use own self-developed player.
 @return A newly initialized TVLManager object.
 */
- (instancetype _Nonnull)initWithOwnPlayer:(BOOL)isOwn NS_DESIGNATED_INITIALIZER;

/**
 Replaces the current player item with a new player item that   referenced by the given URL.

 @param URL A URL that identifies an audiovisual resource.
 */
- (void)replaceCurrentItemWithURL:(NSURL* _Nonnull)URL;

/**
 Replaces the current player item with a new player item.

 @param item A player item.
 */
- (void)replaceCurrentItemWithPlayerItem:(TVLPlayerItem *_Nonnull)item;

- (int)isCurrentItemSupportResolutionSwitch:(TVLMediaResolutionType)newResolution;

- (void)switchCurrentItemResolution:(TVLMediaResolutionType)newResolution;

- (void)switchCurrentItemPreferencesWithSupportedPreferences:(TVLPlayerItemPreferences *_Nonnull)preferences;

- (void)smoothlySwitchCurrentItemResolution:(TVLMediaResolutionType)newResolution switchReason:(TVLPlayerSmoothSwitchReason)switchReason completion:(TVLSwitchResolutionCompletion _Nullable)completion;
/**
 Return true if in preloading state(temporary for rts only)
 */
- (BOOL)isPreloading;
/**
 reset preload player
 */
-(void)resetPreloadPlayer;
/**
 Preload(temporary for rts only)
 */
- (void)preload:(TVLPlayerItem *_Nonnull)item;
/**
 Retry maximum time limit when get stalled. Default is 60 seconds.
 */
- (void)setRetryTimeLimit:(NSUInteger)timeLimit;

/**
 Retry time interval when get stalled. That says player will do retry after stall start with specific time interval till play resume. Default is 5 seconds.
 */
- (void)setRetryTimeInternal:(NSTimeInterval)retryTimeInternal;

/**
 Retry maximum count limit when get stalled. Default is 5 times.
 */
- (void)setRetryCountLimit:(NSInteger)retryCountLimit;

/**
 Configure player with specific options provided with SDK.
 
 @param value The new value for the player's option specified by key.
 @param key The identifier of the option.
 */
- (void)setOptionValue:(id _Nonnull)value forIdentifier:(id _Nonnull)identifier;

/**
 You can do some settings to player directly. Not recommend.

 @param value The new value for the player's setting specified by key.
 @param key The name of one of the player's settings.
 */
- (void)setValue:(int)value forKey:(int)key;

/**
 You can do some settings to player directly. Not recommend.
 
 @param value The new value for the player's setting specified by key.
 @param key The name of one of the player's settings.
 */
- (void)setFloatValue:(float)value forKey:(int)key;

/**
 The image layout of player view. Default is TVLLayoutTypeAspectFit.
 */
- (void)setImageLayoutType:(TVLImageLayoutType)imageLayoutType;

/**
 Indicates the player is muted or not. Default is NO.
 */
- (void)setMuted:(BOOL)muted DEPRECATED_MSG_ATTRIBUTE("Will be deprecated.");

/**
 Indicates the player is mute or not. Default is NO.
 */
- (void)setMute:(BOOL)mute;


/**
 Indicateds the player is muted or not.
 */
- (BOOL)isMute;

/**
 You can take screen shot with this method, and you will get the screen shot in the completion block.

 @param completionBlock Completion after screen shot got.
 */
- (void)takeScreenShot:(void(^)(UIImage * _Nullable image))completionBlock DEPRECATED_MSG_ATTRIBUTE("Has Deprecated");

/**
 Prepare playback in advance
 */
- (void)prepare:(TVLPlayerItem *_Nonnull)item;

/**
 Begins playback of the current item.
 */
- (void)play;

/**
 Pauses playback of the current item.
 */
- (void)pause;

/**
 Stop playback of the current item.
 */
- (void)stop;

/**
 Close player process.
 */
- (void)close;

/**
 Reset the player.
 */
- (void)reset;

/**
 Get current pixel buffer. Hardware decode valid only.
 */
- (CVPixelBufferRef _Nullable)copyPixelBuffer;

/**
Set Lut filter
 */
- (void)setEffect:(NSDictionary *_Nonnull)effectParam;


/**
 Get real-time metaData info
 */
- (NSString *_Nullable)currentMetaDataInfo;
 
 
/**
 you can get current crop pixel buffer
 
 @param topLeftX The x coordinate of the top left point in crop region, value must by in [0, 1];
 @param topLeftY The y coordinate of the top left point in crop region, value must by in [0, 1];
 @param cropW Crop width value of crop region, value must be in [0, 1];
 @param cropH Crop height value of crop region, value must be in [0, 1];
 @return CropCVPixelBuffer in hardware case or nil in other wrong case
 */
- (CVPixelBufferRef _Nullable)cropCopyPixelBuffer:(float)topLeftX topLeftY:(float)topLeftY cropW:(float)cropW cropH:(float)cropH;

/**
 you can get the db value from current audio stream buffer
 return NSInteger value range[-91, -1]
 if return 0 means the calculate process not run;
 */
- (NSInteger)currentAudioStreamDecibel;

/**
 you can get player debug state from this
 */
- (TVLPlayerDebugState)currentPlayerDebugState;


/**
 You can add request header by yourself
 
 @params header add header in request
 */
- (void)addExtraHttpRequestHeadersByUser:(NSDictionary *_Nullable)header;

/**
 you can set the view size before play to make the render time faster.
 the size get from the streamData, so you should ensure that the playitem has been setted to player by replaceCurrentItemWithItem. If not, it will set  (1,1) size to view;
 */
- (CGSize)setViewPresetSize;

/**
 set control message of json
 */
- (BOOL)setPullControlMessageInfo:(NSString *_Nullable)messageInfoJson;

@end


#endif /* TVLManager_Interface_h */
