//
//  TestID.h
//  MainClasse
//
//  Created by 杨益凡 on 2025/2/25.
//  Copyright © 2025 YYF. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TestID : NSObject
+(instancetype)shareInstance;
- (void)startMonitoring;


@property(nonatomic,copy)NSString *_Nullable miniAppID;
@property(nonatomic,copy)NSString *_Nullable miniPlatform;//1028
@property(nonatomic,assign)BOOL miniClient;/// NO = 快爆 YES=游戏盒

@property(nonatomic,copy)NSString *_Nullable mobileAppID;
@property(nonatomic,copy)NSString *_Nullable mobileBundleID;
@property(nonatomic,copy)NSString *_Nullable mobileSlotUserID;
@property(nonatomic,copy)NSString *_Nullable mobileBannerUserID;
@property(nonatomic,copy)NSString *_Nullable mobileNativeUserID;



@property(nonatomic,copy)NSString *_Nullable h5AppID;
@property(nonatomic,copy)NSString *_Nullable h5PostID;

@property(nonatomic,copy)NSString *_Nullable tishText;

@end

NS_ASSUME_NONNULL_END
