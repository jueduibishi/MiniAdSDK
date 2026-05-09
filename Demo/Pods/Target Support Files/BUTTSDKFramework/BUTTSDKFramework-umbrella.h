#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "TTLicenseManager.h"
#import "TTSDKCore.h"
#import "TTSDKManager+Debug.h"
#import "TTSDKManager.h"
#import "TTSDKFramework.h"
#import "TTSDKLiveBase.h"
#import "VeLiveCommon.h"
#import "VeLiveCommonProtocol.h"
#import "NSError+TTVideoLive.h"
#import "TTSDKLivePlayerLite.h"
#import "TTVideoLive.h"
#import "TVLConstDefine.h"
#import "TVLManager+Interface.h"
#import "TVLManager+Settings.h"
#import "TVLManager.h"
#import "TVLOption.h"
#import "TVLPlayerItem.h"
#import "TVLPlayerItemPreferences.h"
#import "TVLProtocol.h"
#import "TVLSettingsManager.h"
#import "VeLivePlayer.h"
#import "VeLivePlayerData.h"
#import "VeLivePlayerDef.h"
#import "VeLivePlayerError.h"
#import "VeLivePlayerGlobalManager.h"
#import "VeLivePlayerObserver.h"
#import "VeLivePlayerStream.h"
#import "VeLivePlayerStreamData.h"
#import "av_audio_wrapper.h"
#import "av_nativetrait.h"
#import "TTAVPlayerLoadControlInterface.h"
#import "TTAVPlayerMaskInfoInterface.h"
#import "TTAVTraitObject.h"
#import "TTPlayerDef.h"
#import "TTSDKPlayerCoreLiveLite.h"
#import "TTStreamInfo.h"

FOUNDATION_EXPORT double TTSDKFrameworkVersionNumber;
FOUNDATION_EXPORT const unsigned char TTSDKFrameworkVersionString[];

