//
//  VeLiveCommon.h
//  VeLiveCommon
//
//  Created by Liuke on 2024/3/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief 视频直播通用的公共配置类，提供 HTTPDNS 服务鉴权信息配置和域名解析的功能等。
 */
/**
 * @locale en
 * @type api
 * @brief A common class for Live service , providing HTTPDNS service authentication information configuration and domain resolution functions.
 */
@interface VeLiveCommon : NSObject
/**
 * @locale zh
 * @brief 是否上报埋点数据，默认为上报数据。
 * @list methods
 * @order 1
 * @param enable YES上报; NO不上报
 */
/**
 * @locale en
 * @brief enable report app log.
 * @list methods
 * @order 1
 * @param domains YES enable; NO disable. 
 */
+ (void)enableReportApplog:(BOOL)enable;

/**
 * @locale zh
 * @brief 设置自定义埋点数据，字典格式。设置为nil时表示不需要上报自定义数据。
 * @list methods
 * @order 2
 * @param data 自定义埋点数据
 */
/**
 * @locale en
 * @brief set custome app log. set nil is disable custom app log.
 * @list methods
 * @order 2
 * @param domains custom app log. 
 */
+ (void)setAppLogCustomData:(nullable NSDictionary *)data;

/**
 * @locale zh
 * @brief 获取设备id，需要集成RangersApplog。
 * @list methods
 * @order 3
 */
/**
 * @locale en
 * @brief get device id.
 * @list methods
 * @order 3
 */
+ (nullable NSString *)getDeviceID;

/**
 * @locale zh
 * @brief 用户自定义设置唯一标识，唯一标识会上报到埋点中。
 * @list methods
 * @order 4
 * @param data 自定义唯一标识
 */
/**
 * @locale en
 * @brief set custome unique id. this unique id will report to app log.
 * @list methods
 * @order 4
 * @param domains custom unique id. 
 */
+ (void)setCurrentUserUniqueID:(nullable NSString *)uniqueID;

+ (NSDictionary *)getSymbols;
@end

NS_ASSUME_NONNULL_END
