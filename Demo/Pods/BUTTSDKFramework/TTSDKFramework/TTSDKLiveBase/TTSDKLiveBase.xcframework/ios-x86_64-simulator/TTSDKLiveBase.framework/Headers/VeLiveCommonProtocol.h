//
//  VeLiveBaseProtocol.h
//  VCloudPandora
//
//  Created by Liuke on 2023/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VeLiveCommonProtocol <NSObject>
/**
 app_id: 12345, 字符串 (必填)
 app_name: ttsdk_demo 字符串
 ttsdk_version: 1.38.2-standard  字符串 (ToB必填)
 show_applog_debug_info:1/0 数字
 channel:channel 字符串
 service_vendor: cn/sg/va,  字符串 (必填，cn或者空表示国内，sg表示新加坡，va表示美东)
 should_init_applog: 0/1 数字 （0不初始化applog，默认为1）
 log_sdk_params: {
    enable:是否开启日志，数字
    log_path: 字符串
    max_log_size_m; 数字
    single_log_size_m; 数字
    log_expiretime_s; 数字
    enable_console; 0/1 数字
    enable_logfile; 0/1 数字
    log_level; 数字
    device_id:设备id，字符串
 }
 */
+ (void)initVeLive:(NSDictionary *)config;
+ (void)setCustomAppLogBody:(NSDictionary *)data;
+ (void)setCustomAppLogHeader:(NSDictionary *)data;
+ (void)event:(NSString *)event params:(NSDictionary *)params;
+ (void)setCurrentUserUniqueID:(nullable NSString *)uniqueID;
+ (void)enableReportApplog:(BOOL)enable;
@end

NS_ASSUME_NONNULL_END
