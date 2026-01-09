//
//  TVLPlayerItem.h
//  TTVideoLive
//
//  Created by chenzhaojie on 2018/11/23.
//

#import <Foundation/Foundation.h>
#import "TVLPlayerItemPreferences.h"
#import "TVLConstDefine.h"
#import <CoreGraphics/CGGeometry.h>
#import "VeLivePlayerStream.h"
#import "VeLivePlayerDef.h"

NS_ASSUME_NONNULL_BEGIN

@class TVLPlayerItemAccessLog;
@class TVLPlayerItemAccessLogEvent;

typedef NS_ENUM(NSInteger, TVLPlayerItemStatus) {
    TVLPlayerItemStatusUnknown,
    TVLPlayerItemStatusReadyToPlay,
    TVLPlayerItemStatusReadyToRender,
    TVLPlayerItemStatusFailed,
    TVLPlayerItemStatusCompleted,
};

FOUNDATION_EXTERN NSString *_Nullable const TVLPlayerItemSuggestedPreferencesUserInfoItemError;
FOUNDATION_EXTERN NSString *_Nullable const TVLPlayerItemSuggestedPreferencesUserInfoItemFallbackInfo;

@interface TVLPlayerItem : NSObject

/**
 The size at which the visual portion of the item is presented by the player. It will return CGSizeZero prior to the player item becoming ready to play.
 */
@property (nonatomic, readonly) CGSize presentationSize;

/**
 The player item’s current preferences.
 */
@property (nonatomic, strong, nonnull) TVLPlayerItemPreferences *preferences;

/**
 Preferences that the player item’s supported.
 */
@property (nonatomic, copy, readonly) NSArray<TVLPlayerItemPreferences *> *supportedPreferences;

/**
 Resolutions that the player item’s supported.
 */
@property (nonatomic, copy, readonly) NSArray<TVLMediaResolutionType> *supportedResolutionTypes;

/**
 Prepares a player item with a given URL.

 @param URL A URL identifying the media resource to be played.
 @return A new player item, prepared to use URL. If URL is invalid, nil will return.
 */
- (instancetype)initWithURL:(NSURL *)URL;

/**
 Returns a new player item, prepared to use a given URL.

 @param URL A URL identifying the media resource to be played.
 @return A new player item, prepared to use URL. If URL is invalid, nil will return.
 */
+ (instancetype)playerItemWithURL:(NSURL *)URL;

/**
 Prepares a player item with stream data.

 @param streamData Stream related information.
 @return A new player item, initialized with stream data. If info data is invalid, nil will return.
 */
+ (instancetype)playerItemWithStreamData:(NSDictionary *)streamData;

/**
 Compare two streamdatas are equal or not in url dimension
 @param streamData1 the first stream data
 @param streamData2 the second stream data
 @return BOOL the stream data is equal or not
 */
+ (VeLiveStreamDataCompareResult)compareStreamData:(NSDictionary *)streamData1 data2:(NSDictionary *)streamData2;

- (nullable TVLPlayerItemPreferences *)recommendedPreferencesWithResolution:(TVLMediaResolutionType)resolution DEPRECATED_MSG_ATTRIBUTE("Will be deprecated.");

- (nullable TVLPlayerItemPreferences *)suggestedPreferencesWithPreferences:(TVLPlayerItemPreferences *)preferences userInfo:(nullable NSDictionary *)userInfo;

/**
 get current play video short edge, as min(width, height).
 need calculation every time
 */
- (int)getCurrentShortEdge;

/**
 get current stream data.
 */
- (NSDictionary*)currentStreamData;

@end

@interface TVLPlayerItem (TVLPlayerItemLogging)

- (nullable TVLPlayerItemAccessLog *)accessLog;

@end

@interface TVLPlayerItemAccessLog : NSObject

@property (nonatomic, readonly, nullable) NSArray<TVLPlayerItemAccessLogEvent *> *events;

@property (nonatomic, readonly, copy) NSDictionary *currentAccessLogInfo;

@property (nonatomic, readonly, copy) NSDictionary *currentAccessLogDebugInfo;

@property (nonatomic, readonly, assign) NSInteger currentVideoBufferInMilliSeconds;

@property (nonatomic, readonly, assign) NSInteger currentAudioBufferInMilliSeconds;

@property (nonatomic, readonly, assign) NSInteger currentTotalStallCount;

@property (nonatomic, readonly, assign) NSInteger currentTotalStallTime;

@end

NS_ASSUME_NONNULL_END
