
/**
 Copyright (c) 2023 The VeLivePlayer project authors. All Rights Reserved.
 @brief VeLivePlayerData
*/
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "TVLPlayerItemPreferences.h"
#import "VeLivePlayerStream.h"
#import "VeLivePlayerDef.h"
NS_ASSUME_NONNULL_BEGIN
/**
 * @locale zh
 * @type keytype
 * @brief 播放器初始化相关配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief The configurations for player initialization.
 */
@interface VeLivePlayerConfiguration : NSObject

/**
 * @locale zh
 * @brief 是否开启字符串 SEI 消息的解析，默认值为 NO。<br/>
 *        - YES：开启；
 *        - NO：关闭。
 */
/**
 * @locale en
 * @brief Whether to enable the parsing of string SEI messages. The default value is `NO`.<br/>
 *        - YES: Enable;
 *        - NO: Disable.
 */
@property (nonatomic, assign) BOOL enableSei;

/**
 * @locale zh
 * @brief 是否开启二进制 SEI 消息的解析，默认值为 NO。<br/>
 *        - YES：开启；
 *        - NO：关闭。
 * @notes 二进制 SEI 开启后，字符串 SEI 的回调将不再发送。
 */
/**
 * @locale en
 * @brief Whether to enable the parsing of binary SEI messages. The default value is `NO`.<br/>
 *        - YES: Enable;
 *        - NO: Disable.
 * @notes After binary SEI is enabled, callbacks for string SEI will no longer be sent.
 */
@property (nonatomic, assign) BOOL enableBinarySei;

/**
 * @locale zh
 * @brief 是否开启硬件解码功能，默认值为 YES。开启硬件解码后，如果出现硬件解码启动失败或硬件解码失败的情况，播放器内部会自动切换为软解。<br>
 *      - YES：开启；
 *      - NO：关闭。
 */
/**
 * @locale en
 * @brief Whether to turn on hardware decoding. The default value is `YES`. When hardware decoding is enabled, if the player fails to start hardware decoding or if hardware decoding fails, the player automatically switches to software decoding. <br>
 *       - YES: Enable;
 *       - NO: Disable.
 */
@property (nonatomic, assign) BOOL enableHardwareDecode;

/**
 * @locale zh
 * @brief 是否开启本地 DNS 预解析，默认值为 NO。开启本地 DNS 预解析可以缩短启播时间。如果本地 DNS 预解析出现异常，可能会影响播放器的正常使用。<br>
 *      - YES：开启；
 *      - NO：关闭。
 */
/**
 * @locale en
 * @brief Whether to enable local DNS prefetch. The default value is `NO`. Enabling local DNS prefetch can reduce the time required to start playback. If an abnormality occurs with local DNS prefetch, the player may not function properly. <br>
 *       - YES: Enable;
 *       - NO: Disable.
 */
@property (nonatomic, assign) BOOL enableLiveDNS;

/**
 * @locale zh
 * @brief 是否开启播放信息周期性回调。默认值为 NO。周期性回调参数详细说明请参见 [VeLivePlayerStatistics](#VeLivePlayerStatistics) 。当 enableStatisticsCallback 为 YES，且 [statisticsCallbackInterval](#VeLivePlayerConfiguration-statisticscallbackinterval) 大于 0 时，播放器会在指定的时间间隔内，周期性地回调播放器状态信息。<br/>
 *        - YES：开启；
 *        - NO：关闭。
 */
/**
 * @locale en
 * @brief Whether to enable periodic callbacks for playback information. The default value is `NO`. Refer to [VeLivePlayerStatistics](#VeLivePlayerStatistics) for more information on callback statistics. If `enableStatisticsCallback` is `YES` and [statisticsCallbackInterval](#VeLivePlayerConfiguration-statisticscallbackinterval) is greater than `0`, the player will periodically report the player status information after the specified time interval.<br/>
 *        - YES: Enable;
 *        - NO: Disable.
 */
@property (nonatomic, assign) BOOL enableStatisticsCallback;

/**
 * @locale zh
 * @brief 播放信息周期性回调的时间间隔，单位为 s，默认值为 5。当 [enableStatisticsCallback](#VeLivePlayerConfiguration-enablestatisticscallback) 为 YES，且 `statisticsCallbackInterval` 大于 0 时，播放器会在指定的时间间隔内，周期性地回调播放器状态信息。
 */
/**
 * @locale en
 * @brief The time interval for periodic callbacks that provide playback information, in seconds. The default value is `5`. If enableStatisticsCallback is `YES` and [enableStatisticsCallback](#VeLivePlayerConfiguration-enablestatisticscallback) is greater than `0`, the player will periodically report the player status information after the specified time interval.
 */
@property (nonatomic, assign) NSInteger statisticsCallbackInterval;

/**
 * @locale zh
 * @brief 网络超时时间，单位为 ms，默认值为 5000。播放器发起网络请求，如果超过了该时间仍未收到服务器响应，则认为网络请求失败。
 */
/**
 * @locale en
 * @brief Network timeout duration in milliseconds. The default value is `5000`. Once the player sends a network request, if the player does not receive a response from the server after the timeout duration, the network request is considered to have failed.
 */
@property (nonatomic, assign) NSInteger networkTimeoutMs;

/**
 * @locale zh
 * @brief 重试时间间隔，单位为 ms，默认值为 5000，仅在无备流时生效。<br>
 *     - 在无备流的场景下，若遇到网络异常等问题导致播放中断，播放器会立即进行重试，前三次重试为立即执行，第四次及之后的重试将按照设置的重试时间间隔执行；
 *     - 在有备流的场景下，重试时间间隔将不生效，所有重试均会立即执行。
 */
/**
 * @locale en
 * @brief Retry interval, in ms. The default value is 5000 and it is only effective when there is no backup stream. <br/>
 *        - In scenarios without a backup stream, if playback is interrupted due to issues such as network anomalies, the player will immediately retry. The first three retries are executed immediately, and the fourth and subsequent retries will be executed according to the set retry interval.
 *        - In scenarios with a backup stream, the retry interval will not take effect and all retries will be executed immediately.
 */
@property (nonatomic, assign) NSInteger retryIntervalTimeMs;

/**
 * @locale zh
 * @brief 在网络连接错误的情况下，播放器最大重试次数，默认值为 5。如果取值为 0，表示关闭播放器内部重试。<br>
 *     - 在无备流的场景下，每次重试，会消耗一次重试次数；
 *     - 在有备流的场景下，每次主备流切换，会消耗一次重试次数。
 */
/**
 * @locale en
 * @brief In the case of a network connection error, the maximum number of automatic retries of the player. The default value is `5`. If the value is `0`, the player will not automatically retry.<br/>
 *        - In a scenario without backup streams, each retry consumes one retry attempt.
 *        - In a scenario with backup streams, each primary-backup stream switch consumes one retry attempt.
 */
@property (nonatomic, assign) NSInteger retryMaxCount;

/**
 * @locale zh
 * @brief 默认初始化方法。
 */
/**
 * @locale en
 * @brief Initializes the configurations.
 */
- (instancetype _Nonnull)init;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 播放周期性统计信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief The playback statistics.
 */
@interface VeLivePlayerStatistics : NSObject

/**
 * @locale zh
 * @brief 当前直播的播放地址。
 */
/**
 * @locale en
 * @brief The current pull stream address.
 */
@property (nonatomic, strong, readonly, nullable) NSURL* url;

/**
 * @locale zh
 * @brief 是否使用硬件解码。<br>
 *     - YES：硬解；
 *     - NO：非硬解。
 */
/**
 * @locale en
 * @brief Whether hardware decoding is used. <br>
 *      - YES: Hardware decoding is used;
 *      - NO: Hardware decoding is not used.
 */
@property (nonatomic, readonly) BOOL isHardWareDecode;

/**
 * @locale zh
 * @brief 当前播放延时，单位为 ms。仅在使用了火山引擎视频直播推流 SDK 时，支持统计播放延时。
 */
/**
 * @locale en
 * @brief The current playback latency, in milliseconds. The latency data is available only if you use the BytePlus MediaLive Broadcast SDK to push the live stream.
 */
@property (nonatomic, readonly) int delayMs;

/**
 * @locale zh
 * @brief 从当前视频开始播放起，累计的卡顿时长，单位为 ms。
 */
/**
 * @locale en
 * @brief The cumulative duration of stutters that occurred since the beginning of playback, in milliseconds.
 */
@property (nonatomic, readonly) int stallTimeMs;

/**
 * @locale zh
 * @brief 带宽预测 ，单位为 kbps。
 */
/**
 * @locale en
 * @brief The estimated bandwidth, in kbps.
 */
@property (nonatomic, readonly) long bandwidthEstimation;

/**
 * @locale zh
 * @brief 视频的编码类型。
 */
/**
 * @locale en
 * @brief The encoding format of the video.
 */
@property (nonatomic, copy, readonly, nullable) NSString* videoCodec;

/**
 * @locale zh
 * @brief 当前播放视频的宽度，单位为 px。
 */
/**
 * @locale en
 * @brief The width of the video, in pixels.
 */
@property (nonatomic, readonly) int width;

/**
 * @locale zh
 * @brief 当前播放视频的高度，单位为 px。
 */
/**
 * @locale en
 * @brief The height of the video, in pixels.
 */
@property (nonatomic, readonly) int height;

/**
 * @locale zh
 * @brief 当前播放视频的帧率，单位为 fps。
 */
/**
 * @locale en
 * @brief The frame rate of the video, in fps.
 */
@property (nonatomic, readonly) float fps;

/**
 * @locale zh
 * @brief 实时下载的码率，单位为 kbps。
 */
/**
 * @locale en
 * @brief The downlink bitrate, in Kbps.
 */
@property (nonatomic, readonly) long bitrate;

/**
 * @locale zh
 * @brief 视频播放的缓冲区 buffer 大小，单位为 ms。
 */
/**
 * @locale en
 * @brief The video buffer, in milliseconds.
 */
@property (nonatomic, readonly) long videoBufferMs;

/**
 * @locale zh
 * @brief 音频播放的缓冲区 buffer 大小，单位为 ms。
 */
/**
 * @locale en
 * @brief The audio buffer, in milliseconds.
 */
@property (nonatomic, readonly) long audioBufferMs;

/**
 * @locale zh
 * @brief 当前播放的视频格式。
 */
/**
 * @locale en
 * @brief The video format.
 */
@property (nonatomic, readonly) VeLivePlayerFormat format;

/**
 * @locale zh
 * @brief 当前播放的传输协议。
 */
/**
 * @locale en
 * @brief The transmission protocol of the live stream.
 */
@property (nonatomic, readonly) VeLivePlayerProtocol protocol;

 
@end

/**
 * @locale zh
 * @type keytype
 * @brief 视频帧数据。
 */
/**
 * @locale en
 * @type keytype
 * @brief The video frame.
 */
@interface VeLivePlayerVideoFrame : NSObject

/**
 * @locale zh
 * @brief 视频帧数据封装格式，详情请参见 [VeLivePlayerVideoBufferType](#VeLivePlayerVideoBufferType)。
 */
/**
 * @locale en
 * @brief The encapsulation format. See [VeLivePlayerVideoBufferType](#VeLivePlayerVideoBufferType) for details.
 */
@property (nonatomic, readonly) VeLivePlayerVideoBufferType bufferType;

/**
 * @locale zh
 * @brief 视频帧像素格式，详情请参见 [VeLivePlayerPixelFormat](#VeLivePlayerPixelFormat)。
 */
/**
 * @locale en
 * @brief The pixel format. See [VeLivePlayerPixelFormat](#VeLivePlayerPixelFormat) for details.
 */
@property (nonatomic, readonly) VeLivePlayerPixelFormat pixelFormat;

/**
 * @locale zh
 * @brief 视频宽度，单位为 px。
 */
/**
 * @locale en
 * @brief The video width, in pixels.
 */
@property (nonatomic, readonly) NSInteger width;

/**
 * @locale zh
 * @brief 视频高度，单位为 px。
 */
/**
 * @locale en
 * @brief The video height, in pixels.
 */
@property (nonatomic, readonly) NSInteger height;

/**
 * @locale zh
 * @brief 视频帧的渲染时间戳，单位为 ms。
 */
/**
 * @locale en
 * @brief The timestamp indicating the time when the video frame is rendered, in milliseconds.
 */
@property (nonatomic, readonly) int64_t pts;

/**
 * @locale zh
 * @brief `pixelFormat` 为 `VeLivePlayerVideoBufferTypePixelBuffer` 时的视频数据。
 */
/**
 * @locale en
 * @brief The video data, if you set [VeLivePlayerVideoBufferType](#VeLivePlayerVideoBufferType) to `VeLivePlayerVideoBufferTypePixelBuffer`.
 */
@property (nonatomic, readonly, nullable) CVPixelBufferRef pixelBuffer;

/**
 * @locale zh
 * @brief `pixelFormat` 为 `VeLivePlayerVideoBufferTypeSampleBuffer` 时的视频数据。
 */
/**
 * @locale en
 * @brief The video data, if you set [VeLivePlayerVideoBufferType](#VeLivePlayerVideoBufferType) to `VeLivePlayerVideoBufferTypeSampleBuffer`.
 */
@property (nonatomic, readonly, nullable) CMSampleBufferRef sampleBuffer;

/**
 * @locale zh
 * @brief `pixelFormat` 为 `VeLivePlayerVideoBufferTypeNSData` 时的视频数据。
 */
/**
 * @locale en
 * @brief The video data, if you set [VeLivePlayerVideoBufferType](#VeLivePlayerVideoBufferType) to `VeLivePlayerVideoBufferTypeNSData`.
 */
@property (nonatomic, strong, readonly, nullable) NSData* data;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 音频帧数据。
 */
/**
 * @locale en
 * @type keytype
 * @brief The audio frame.
 */
@interface VeLivePlayerAudioFrame : NSObject

/**
 * @locale zh
 * @brief 音频帧数据封装格式，详情请参见 [VeLivePlayerAudioBufferType](#VeLivePlayerAudioBufferType)。
 */
/**
 * @locale en
 * @brief The encapsulation format of the audio data. See [VeLivePlayerAudioBufferType](#VeLivePlayerAudioBufferType) for details.
 */
@property (nonatomic, readonly) VeLivePlayerAudioBufferType bufferType;

/**
 * @locale zh
 * @brief 音频采样率，单位为 Hz。
 */
/**
 * @locale en
 * @brief The audio sample rate, in Hz.
 */
@property (nonatomic, readonly) int sampleRate;

/**
 * @locale zh
 * @brief 声道数。<br>
 *     - 1：单声道；
 *     - 2：双声道。
 */
/**
 * @locale en
 * @brief The number of audio channels. <br>
 *      - 1: Mono;
 *      - 2: Stereo.
 */
@property (nonatomic, readonly) int channels;

/**
 * @locale zh
 * @brief 音频位深度。
 */
/**
 * @locale en
 * @brief The audio bit depth.
 */
@property (nonatomic, readonly) int bitDepth;

/**
 * @locale zh
 * @brief 音频渲染时间戳，单位为 ms。
 */
/**
 * @locale en
 * @brief The timestamp indicating the time when the audio is rendered, in milliseconds.
 */
@property (nonatomic, readonly) CMTime pts;

/**
 * @locale zh
 * @brief PCM 音频数据。
 */
/**
 * @locale en
 * @brief The PCM audio data.
 */
@property (nonatomic, strong, readonly) NSData* data;

/**
 * @locale zh
 * @brief 音频采样点个数。
 */
/**
 * @locale en
 * @brief The number of audio samples.
 */
@property (nonatomic, readonly) int samples;

@end

/** 
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 流信息。
 */
/** 
 * @locale en
 * @hidden
 * @type keytype
 * @brief stream info..
 */
@interface VeLivePlayerVideoStreamInfo : NSObject

/** 
 * @locale zh
 * @brief 当前播放视频的宽度，单位为 px。
 */
/** 
 * @locale en
 * @brief The width of the video, in pixels.
 */
@property (nonatomic, readonly) int width;

/** 
 * @locale zh
 * @brief 当前播放视频的高度，单位为 px。
 */
/** 
 * @locale en
 * @brief The height of the video, in pixels.
 */
@property (nonatomic, readonly) int height;

/** 
 * @locale zh
 * @brief 当前播放视频的帧率，单位为 fps。
 */
/** 
 * @locale en
 * @brief The frame rate of the video, in fps.
 */
@property (nonatomic, readonly) float fps;


@end

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 流信息。
 */
/**
 * @locale en
 * @hidden
 * @type keytype
 * @brief stream info..
 */
@interface VeLivePlayerStreamInfo : NSObject

/**
 * @locale zh
 * @brief 视频的宽度，单位为 px。
 */
/**
 * @locale en
 * @brief The width of the video, in pixels.
 */
@property (nonatomic, assign) int width;

/**
 * @locale zh
 * @brief 视频的高度，单位为 px。
 */
/**
 * @locale en
 * @brief The height of the video, in pixels.
 */
@property (nonatomic, assign) int height;

/**
 * @locale zh
 * @brief 视频的带宽,单位为Bps
 */
/**
 * @locale en
 * @brief The bandwidth of the video,in Bps
 */
@property (nonatomic, assign) int bandwidth;

/**
 * @locale zh
 * @brief 视频的url。
 */
/**
 * @locale en
 * @brief The urlof the video.
 */
@property (nonatomic, copy) NSString *url;

@end

NS_ASSUME_NONNULL_END
