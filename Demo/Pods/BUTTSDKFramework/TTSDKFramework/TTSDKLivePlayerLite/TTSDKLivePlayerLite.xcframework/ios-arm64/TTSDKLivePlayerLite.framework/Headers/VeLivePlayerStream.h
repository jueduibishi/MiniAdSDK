
/**
 Copyright (c) 2023 The VeLivePlayer project authors. All Rights Reserved.
 @brief VeLivePlayerStream
*/
#import "VeLivePlayerDef.h"
NS_ASSUME_NONNULL_BEGIN
/**
 * @locale zh
 * @type keytype
 * @brief 流地址信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief The information about a pull stream address.
 */
@interface VeLivePlayerStream : NSObject

/**
 * @locale zh
 * @brief 播放地址。
 */
/**
 * @locale en
 * @brief The pull stream address.
 */
@property (nonatomic, copy, nonnull) NSString* url;

/**
 * @locale zh
 * @brief 清晰度档位，详情请参见 [VeLivePlayerResolution](#VeLivePlayerResolution)。
 */
/**
 * @locale en
 * @brief The resolution. See [VeLivePlayerResolution](#VeLivePlayerResolution) for details.
 */
@property (nonatomic, assign) VeLivePlayerResolution resolution;

/**
 * @locale zh
 * @brief 播放码率，单位为 bps。
 */
/**
 * @locale en
 * @brief The playback bitrate, in bps.
 */
@property (nonatomic, assign) int bitrate;

/**
 * @locale zh
 * @brief 传输协议，详情请参见 [VeLivePlayerProtocol](#VeLivePlayerProtocol)。
 */
/**
 * @locale en
 * @brief The transmission protocol. See [VeLivePlayerProtocol](#VeLivePlayerProtocol) for details.
 */
@property (nonatomic, assign) VeLivePlayerProtocol protocol;

/**
 * @locale zh
 * @brief 播放格式，详情请参见 [VeLivePlayerFormat](#VeLivePlayerFormat)。
 */
/**
 * @locale en
 * @brief The video format. See [VeLivePlayerFormat](#VeLivePlayerFormat) for details.
 */
@property (nonatomic, assign) VeLivePlayerFormat format;

/**
 * @locale zh
 * @brief 播放流类型为主路或备路，详情请参见 [VeLivePlayerStreamType](188121#VeLivePlayerStreamType)。
 */
/**
 * @locale en
 * @brief Whether the stream is a primary or a backup stream. See [VeLivePlayerStreamType](#VeLivePlayerStreamType) for details.
 */
@property (nonatomic, assign) VeLivePlayerStreamType type;

/**
 * @locale zh
 * @brief 单路直播流配置初始化方法。
 */
/**
 * @locale en
 * @brief Initializes a pull stream address.
 */
- (instancetype)init;

@end
NS_ASSUME_NONNULL_END
