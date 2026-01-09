
/**
 Copyright (c) 2023 The VeLivePlayer project authors. All Rights Reserved.
 @brief VeLivePlayerStreamData
*/
#import "VeLivePlayerStream.h"
NS_ASSUME_NONNULL_BEGIN
/**
 * @locale zh
 * @type keytype
 * @brief 播放地址相关配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configurations for the pull stream addresses.
 */
@interface VeLivePlayerStreamData : NSObject

/**
 * @locale zh
 * @brief 是否打开 ABR 平滑切档功能，默认为 NO。<br>
 *     - YES：开启；
 *     - NO：关闭。
 */
/**
 * @locale en
 * @brief Whether to enable adaptive bitrate (ABR). The default value is `NO`. <br>
 *      - YES: Enable;
 *      - NO: Disable.
 */
@property (nonatomic, assign) BOOL enableABR;

/**
 * @locale zh
 * @brief 是否打开主备切换，默认为 NO。<br>
 *     - YES：开启；
 *     - NO：关闭。
 */
/**
 * @locale en
 * @brief Whether to enable switching between the primary and the backup stream. The default value is `NO`. <br>
 *      - YES: Enable;
 *      - NO: Disable.
 */
@property (nonatomic, assign) BOOL enableMainBackupSwitch;

/**
 * @locale zh
 * @brief 播放器的默认清晰度档位，默认使用原始流清晰度，详情请参见 [VeLivePlayerResolution](#VeLivePlayerResolution)。
 */
/**
 * @locale en
 * @brief The default resolution. The default value is `VeLivePlayerResolutionOrigin`, which indicates the original resolution. See [VeLivePlayerResolution](#VeLivePlayerResolution) for details.
 */
@property (nonatomic, assign) VeLivePlayerResolution defaultResolution;

/**
 * @locale zh
 * @brief 播放器的默认播放格式，默认值为 FLV，详情请参见 [VeLivePlayerFormat](#VeLivePlayerFormat)。
 */
/**
 * @locale en
 * @brief The default video format. The default value is `VeLivePlayerFormatFLV`. See [VeLivePlayerFormat](#VeLivePlayerFormat) for details.
 */
@property (nonatomic, assign) VeLivePlayerFormat defaultFormat;

/**
 * @locale zh
 * @brief 播放器的默认播放传输层协议，默认值为 TCP，详情请参见 [VeLivePlayerProtocol](#VeLivePlayerProtocol)。
 */
/**
 * @locale en
 * @brief The default transmission protocol. The default value is `VeLivePlayerProtocolTCP`. See [VeLivePlayerProtocol](#VeLivePlayerProtocol) for details.
 */
@property (nonatomic, assign) VeLivePlayerProtocol defaultProtocol;

/**
 * @locale zh
 * @brief 主路流地址列表，详情请参见 [VeLivePlayerStream](#VeLivePlayerStream)。
 */
/**
 * @locale en
 * @brief A list of main stream addresses. See [VeLivePlayerStream](#VeLivePlayerStream) for details.
 */
@property (nonatomic, copy, nullable) NSArray<VeLivePlayerStream *> * mainStream;

/**
 * @locale zh
 * @brief 备路流地址列表，详情请参见 [VeLivePlayerStream](#VeLivePlayerStream)。
 */
/**
 * @locale en
 * @brief A list of backup stream addresses. See [VeLivePlayerStream](#VeLivePlayerStream) for details.
 */
@property (nonatomic, copy, nullable) NSArray<VeLivePlayerStream *> * backupStream;

@end
NS_ASSUME_NONNULL_END
