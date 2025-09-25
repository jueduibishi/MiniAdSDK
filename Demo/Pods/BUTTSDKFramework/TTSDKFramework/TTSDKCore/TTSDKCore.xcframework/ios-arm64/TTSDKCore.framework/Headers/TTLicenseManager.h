//
//  TTLicenseManager.h
//  TTLicense
//
//  Created by 陈昭杰 on 2020/5/9.
//  Copyright © 2020 ByteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXTERN NSString * const TTLicenseNotificationLicenseInfoDidUpdate;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationLicenseDidAdd;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationLicensePathKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationIdKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationLicenseResultKey;

FOUNDATION_EXTERN NSString * const TTLicenseNotificationStatusDidCheck;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoModuleKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoStatusKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoIgnoreExpirationKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoLicenseVersionKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoAppIDKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoBundleIDKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoValidModulesKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoAuthorizationStartDateKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoAuthorizationEndDateKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationUserInfoAuthorizationRestTimeintervalKey;

FOUNDATION_EXTERN NSString * const kFeatureByteVC1Key;
FOUNDATION_EXTERN NSString * const kFeatureByteH266Key;
FOUNDATION_EXTERN NSString * const kFeatureVrPanoramaKey;
FOUNDATION_EXTERN NSString * const kFeatureABRKey;
FOUNDATION_EXTERN NSString * const kFeatureSuperResolutionKey;
FOUNDATION_EXTERN NSString * const kFeatureSubtitleAndMaskKey;
FOUNDATION_EXTERN NSString * const kFeatureVolumeBalanceKey;
FOUNDATION_EXTERN NSString * const kFeaturePCDNKey;
FOUNDATION_EXTERN NSString * const kFeatureIntertrustDrmKey;

@class TTLicenseManager;

typedef NS_ENUM(NSUInteger, TTLicenseStatus) {
    TTLicenseStatusInvalid                  = 0,
    TTLicenseStatusOK                       = 1,
    TTLicenseStatusExpired                  = 2,
    TTLicenseStatusParamErrorEdition        = 400,
    TTLicenseStatusParamErrorPackageName    = 401,
    TTLicenseStatusParamErrorFeatureName    = 402,
    TTLicenseStatusParamErrorModuleName     = 403,
};

typedef NS_ENUM(NSUInteger, TTLicenseModule) {
    TTLicenseModuleVOD          = 0,
    TTLicenseModuleUpload       = 1,
    TTLicenseModuleLivePush     = 2,
    TTLicenseModuleLivePull     = 3,
    TTLicenseModuleEditor       = 4,
};

typedef NS_ENUM(NSUInteger, TTLicenseModuleEdition) {
    TTLicenseModuleEditionStandard  = 0,
    TTLicenseModuleEditionPremium   = 1,
    TTLicenseModuleEditionEnterprise = 2,
};


@interface TTLicenseManager : NSObject

@property (class, nonatomic, strong, readonly) TTLicenseManager *defaultManager;

- (void)updateWithAppID:(NSString *)appID bundleID:(NSString *)bundleID licenseFile:(NSString *)filePath error:(NSError **)error;

- (TTLicenseModuleEdition)checkEditionWithModule:(TTLicenseModule)module;

- (TTLicenseStatus)checkStatusWithModule:(TTLicenseModule)module;

- (TTLicenseStatus)checkStatusWithModule:(TTLicenseModule)module feature:(const NSString *)featureName;

- (NSArray * _Nullable)getLicenseIds;

- (NSDictionary * _Nullable)getLicenseInfo:(NSString * _Nonnull)Id;

- (void)enableLicenseInfo:(BOOL)enable;

- (void)setDelegate:(id _Nullable)delegate;

@end
