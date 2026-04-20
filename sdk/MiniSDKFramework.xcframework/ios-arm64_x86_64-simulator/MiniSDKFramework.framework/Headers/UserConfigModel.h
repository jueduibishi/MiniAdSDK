//
//  UserConfigModel.h
//  MiniSDKFramework
//
//  Created by l on 2026/4/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/// 用户信息配置，用于统计
@interface UserConfigModel : NSObject
@property(nonatomic,copy)NSString *_Nullable imei;//设备序列号；预留：iOS暂无
@property(nonatomic,copy)NSString *_Nullable oaid;//移动安全联盟生成的唯一标识
@property(nonatomic,copy)NSString *_Nullable uid;//49账号uid
@end

NS_ASSUME_NONNULL_END
