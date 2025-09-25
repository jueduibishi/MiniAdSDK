//
//  TVLProtocol.h
//  Pods
//
//  Created by zhongshaofen on 2017/7/18.
//
//

#import <Foundation/Foundation.h>
#import "TVLConstDefine.h"
#import "TVLPlayerItem.h"
#import "NSError+TTVideoLive.h"
#import "VeLivePlayerDef.h"
#import "VeLivePlayerError.h"

// TODO: Need a better delegate protocol declaration.

@class TVLManager;

NS_ASSUME_NONNULL_BEGIN

@protocol TVLAdvising <NSObject>

@optional

- (void)playerItem:(TVLPlayerItem* _Nonnull)playerItem didSwitchFromPreviousPreferences:(TVLPlayerItemPreferences* _Nonnull)previousPreferences toCurrentPreferences:(TVLPlayerItemPreferences* _Nonnull)currentPreferences;

- (void)playerItem:(TVLPlayerItem* _Nonnull)playerItem willSwitchFromPreferences:(TVLPlayerItemPreferences* _Nonnull)fromPreferences toPreferences:(TVLPlayerItemPreferences* _Nonnull)toPreferences;

- (void)playerItem:(TVLPlayerItem* _Nonnull)playerItem currentResolution:(TVLMediaResolutionType)currentResolution degradeFailedWithError:(NSError* _Nonnull)error;

- (BOOL)playerItem:(TVLPlayerItem* _Nonnull)playerItem shouldReplaceCurrentPreferencesWithSuggestedPreferences:(TVLPlayerItemPreferences* _Nonnull)suggestedPreferences DEPRECATED_MSG_ATTRIBUTE("Will be deprecated.");

- (TVLPlayerItemPreferences* _Nonnull)playerItem:(TVLPlayerItem* _Nonnull)playerItem customizedPreferencesWithUserInfo:(NSDictionary* _Nullable)userInfo DEPRECATED_MSG_ATTRIBUTE("Will be deprecated.");;

@end

@protocol TVLABR <NSObject>

@optional

/// Whether the player should actively switch resolution or not.
/// - Parameters:
///   - manager: The live player informing the delegate of this impending event.
///   - currentResolution: Current resolution.
///   - suggestedResolution: Target resolution when live player was allowed to switch, suggested by live player.
///   - userInfo: Additional info which contains strategy context, like strategy type..
- (TVLABRSwitchPermissionRequestResult)manager:(TVLManager *)manager shouldAutomaticallySwitchCurrentResolution:(TVLMediaResolutionType)currentResolution toSuggestedResolution:(TVLMediaResolutionType)suggestedResolution userInfo:(nullable NSDictionary *)userInfo;

/// Inform the delegate that ABR switch did complete.
/// - Parameters:
///   - manager: The live player informing the delegate of this impending event.
///   - previousResolution: Resolution before switch performed.
///   - currentResolution: Target resolution when live player was allowed to switch, suggested by live player.
///   - userInfo: Additional info which contains strategy context, like strategy type..
- (void)manager:(TVLManager *)manager didAutomaticallySwitchFromPreviousResolution:(TVLMediaResolutionType)previousResolution toCurrentResolution:(TVLMediaResolutionType)currentResolution userInfo:(nullable NSDictionary *)userInfo;

- (void)manager:(TVLManager* _Nonnull)manager didAutomaticallySwitchFromPreviousResolution:(TVLMediaResolutionType)previousResolution toCurrentResolution:(TVLMediaResolutionType)currentResolution DEPRECATED_MSG_ATTRIBUTE("Will be deprecated.");

@end

@protocol TVLNetworking <NSObject>

@optional

- (void)manager:(TVLManager * _Nonnull)manager performRequestWithURL:(NSString* _Nonnull)URL method:(NSString* _Nonnull)method headerField:(NSDictionary* _Nullable)headerField params:(id _Nullable)params completion:(TVLNetworkRequestCompletion _Nullable)completion;

@end

@protocol TVLDelegate <TVLAdvising, TVLABR, TVLNetworking>

@required
- (void)recieveError:(NSError* _Nonnull)error;
- (void)startRender;
- (void)stallStart;
- (void)stallEnd;
- (void)onStreamDryup:(NSError* _Nonnull)error;
- (void)onMonitorLog:(NSDictionary* _Nonnull) event;

- (void)loadStateChanged:(NSNumber* _Nonnull)state;

@optional

- (void)manager:(TVLManager* _Nonnull)manager playerItemStatusDidChange:(TVLPlayerItemStatus)status;

- (void)manager:(TVLManager* _Nonnull)manager didReceiveSEI:(NSDictionary* _Nonnull)SEI;

- (void)manager:(TVLManager* _Nonnull)manager didReceiveImmidiatlySei:(NSDictionary* _Nonnull)SEI;

- (void)manager:(TVLManager* _Nonnull)manager videoSizeDidChange:(CGSize)size;

- (void)manager:(TVLManager* _Nonnull)manager videoCropAreaDidAutomaticallyChange:(CGRect)frame;

- (void)manager:(TVLManager* _Nonnull)manager willOpenAudioRenderWithSampleRate:(int)sampleRate channels:(int)channels duration:(int)duration;

- (void)manager:(TVLManager* _Nonnull)manager willProcessAudioFrameWithRawData:(float*_Nullable*_Nullable)rawData samples:(int)samples timeStamp:(int64_t)timestamp;

- (void)manager:(TVLManager* _Nonnull)manager didCloseInAsyncMode:(BOOL)isAsync;

- (void)manager:(TVLManager* _Nonnull )manager willOpenAudioProcessInAudioRecord:(int)sampleRate channels:(int)channels duration:(int)duration;

- (void)manager:(TVLManager* _Nonnull)manager willProcessAudioFrameInAudioRecord:(float*_Nullable*_Nullable)rawData samples:(int)samples timeStamp:(int64_t)timestamp;

- (void)itemStatusChanged:(NSNumber* _Nonnull)status DEPRECATED_MSG_ATTRIBUTE("Will be deprecated, use - manager:playerItemStatusDidChange: please.");

- (void)manager:(TVLManager* _Nonnull)manager videoCropAreaDidChange:(CGRect)frame DEPRECATED_MSG_ATTRIBUTE("Will be deprecated.");

- (void)manager:(TVLManager* _Nonnull)manager didReceiveBinarySei:(const uint8_t* _Nonnull)binarySei length:(int)size;

- (void)receivePlayerErrorForDebug:(NSError* _Nonnull)error;

- (void)videoBmfFlexSrUpdate:(TVLManager* _Nonnull)manager srType:(VeLivePlayerBMFFlexSRType)srType;

- (void)onNetworkQualityChanged:(TVLManager* _Nonnull)manager behavior:(int)behavior detail:(NSString* _Nonnull)detail;

- (void)onResolutionSwitch:(TVLManager *_Nonnull)manager resolution:(VeLivePlayerResolution)resolution error:(VeLivePlayerError *_Nonnull)error reason:(VeLivePlayerResolutionSwitchReason)reason;
@end

/// get app info params
@protocol TVLAppInfoFetcher <NSObject>

@optional

- (NSDictionary* _Nullable)getAppInfo;

- (NSDictionary* _Nullable)getEffectModel:(VeLivePlayerEffectType)effectType modelName:(NSString *)modelName;

@end

@protocol TVLLoudnessObserver <NSObject>

@optional

- (void)onLoudness:(float)souceLuft soucePeak:(float)sourcePeak targetLufs:(float)targetLufs isEnableExternalAETargetLufs:(bool)isEnableExternalAETargetLufs;

@end

@protocol TVLAudioInfoObserver <NSObject>

@optional
- (void)onAudioVolume:(NSDictionary*)info;
@end

@protocol VeLiveHLSVariant;
@protocol VeLiveHLSMultiVariantPlaylist <NSObject>
@property (nonatomic, copy) NSArray<id <VeLiveHLSVariant>> *variants;
@end

@protocol VeLiveHLSPlaylist;
@protocol VeLiveHLSVariant <NSObject>
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;
@property (nonatomic, assign) int bandwidth;
@property (nonatomic, copy) NSString *audioGroup;
@property (nonatomic, copy) NSString *videoGroup;
@property (nonatomic, copy) NSString *subtitlesGroup;
@property (nonatomic, copy) NSArray<id <VeLiveHLSPlaylist>> *playlists;
@property (nonatomic, copy) NSString *url;
@end

@protocol VeLiveHLSRendition;
@protocol VeLiveHLSPlaylist <NSObject>
@property (nonatomic, assign) int index;
@property (nonatomic, copy) NSArray<id <VeLiveHLSRendition>> *renditions;
@end

@protocol VeLiveHLSRendition <NSObject>
@property (nonatomic, assign) int trackType;
@property (nonatomic, assign) int infoId;
@property (nonatomic, copy) NSString *groupId;
@property (nonatomic, copy) NSString *language;
@property (nonatomic, copy) NSString *name;
@end

NS_ASSUME_NONNULL_END
