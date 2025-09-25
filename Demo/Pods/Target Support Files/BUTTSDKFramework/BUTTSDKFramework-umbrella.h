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
#import "TTSDKManager.h"
#import "TTSDKFramework.h"
#import "TTSDKLiveBase.h"
#import "VeLiveCommon.h"
#import "VeLiveCommonProtocol.h"

FOUNDATION_EXPORT double TTSDKFrameworkVersionNumber;
FOUNDATION_EXPORT const unsigned char TTSDKFrameworkVersionString[];

