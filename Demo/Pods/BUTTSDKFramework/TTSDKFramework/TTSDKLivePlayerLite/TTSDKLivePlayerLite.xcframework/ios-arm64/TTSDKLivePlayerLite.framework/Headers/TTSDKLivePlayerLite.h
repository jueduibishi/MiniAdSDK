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

#import "VeLivePlayerData.h"
#import "TVLOption.h"
#import "TVLPlayerItem.h"
#import "TVLPlayerItemPreferences.h"
#import "VeLivePlayerStream.h"
#import "VeLivePlayerStreamData.h"
#import "NSError+TTVideoLive.h"
#import "TVLConstDefine.h"
#import "VeLivePlayerDef.h"
#import "VeLivePlayerError.h"
#import "TTVideoLive.h"
#import "TVLManager+Interface.h"
#import "TVLManager+Settings.h"
#import "TVLManager.h"
#import "TVLProtocol.h"
#import "TVLSettingsManager.h"
#import "VeLivePlayer.h"
#import "VeLivePlayerGlobalManager.h"
#import "VeLivePlayerObserver.h"



FOUNDATION_EXPORT double TTSDKLivePlayerLiteVersionNumber;
FOUNDATION_EXPORT const unsigned char TTSDKLivePlayerLiteVersionString[];
