
/**
 Copyright (c) 2023 The VeLivePlayer project authors. All Rights Reserved.
 @brief VeLivePlayerObserver
*/

#import "TVLPlayerItem.h"
#import "VeLivePlayerError.h"
#import "TVLProtocol.h"
@class VeLivePlayerStatistics;
@class VeLivePlayerVideoFrame;
@class VeLivePlayerAudioFrame;
@class TVLManager;

/**
 * @locale zh
 * @type callback
 * @brief 播放事件回调。
 */
/**
 * @locale en
 * @type callback
 * @brief The live player observer.
 */
@protocol VeLivePlayerObserver <NSObject>

@optional
/**
 * @locale zh
 * @type callback
 * @brief 播放器错误信息回调，播放器出现错误时，触发此回调。
 * @list playerCallback
 * @order 1
 * @param player 触发该事件回调的播放器对象。
 * @param error 错误信息，详情请参见 [VeLivePlayerError](188120#VeLivePlayerError) 。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when a player error occurs.
 * @param player The player object that triggers the callback function.
 * @param error The error message. See VeLivePlayerError {@link #VeLivePlayerError} for details.
 * @list playerCallback
 * @order 1
 */
- (void)onError:(TVLManager *_Nonnull)player error:(VeLivePlayerError *_Nonnull)error;

/**
 * @locale zh
 * @type callback
 * @brief 视频首帧渲染事件回调。视频首帧渲染成功，或播放过程中发生重试，重试后的第一个视频帧渲染成功，均会触发此回调。
 * @list playerCallback
 * @order 2
 * @param player 触发该事件回调的播放器对象。
 * @param isFirstFrame 渲染成功的是否为视频首帧。<br>
 *                     - YES：视频首帧；
 *                     - NO：重试后第一个视频帧。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the first video frame is rendered at the beginning of playback or after a retry during playback.
 * @param player The player object that triggers the callback function.
 * @param isFirstFrame Whether the video frame is the first video frame rendered at the beginning of playback. <br>
 *                      - YES: The video frame is the first video frame rendered at the beginning of playback;
 *                      - NO: The video frame is the first video frame rendered after a retry during playback.
 * @list playerCallback
 * @order 2
 */
- (void)onFirstVideoFrameRender:(TVLManager *_Nonnull)player isFirstFrame:(BOOL)isFirstFrame;

/**
 * @locale zh
 * @type callback
 * @brief 音频首帧渲染事件回调。音频首帧渲染成功，或播放过程中发生重试，重试后的第一个音频帧渲染成功，均会触发此回调。
 * @list playerCallback
 * @param player 触发该事件回调的播放器对象。
 * @param isFirstFrame 渲染成功的是否为音频首帧。<br>
 *                     - YES：音频首帧；
 *                     - NO：重试后第一个音频帧。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the first audio frame is rendered at the beginning of playback or after a retry during playback.
 * @list playerCallback
 * @param player The player object that triggers the callback function.
 * @param isFirstFrame Whether the audio frame is the first audio frame rendered at the beginning of playback. <br>
 *                      - YES: The audio frame is the first audio frame rendered at the beginning of playback;
 *                      - NO: The audio frame is the first audio frame rendered after a retry during playback.
 */
- (void)onFirstAudioFrameRender:(TVLManager *_Nonnull)player isFirstFrame:(BOOL)isFirstFrame;

/**
 * @locale zh
  * @type callback
  * @brief 播放卡顿开始回调。
  * @param player 触发该事件回调的播放器对象
 * @list playerCallback
 * @order 3
  */
 /**
  * @locale en
  * @type callback
  * @brief Occurs when a playback stutter starts.
  * @param player The player object that triggers the callback function.
 * @list playerCallback
 * @order 3
  */
- (void)onStallStart:(TVLManager *_Nonnull)player;

/**
 * @locale zh
 * @type callback
 * @brief 播放卡顿结束回调。音频缓冲区达到起播条件且开始播放后，触发此回调。
 * @list playerCallback
 * @order 4
 * @param player 触发该事件回调的播放器对象。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when a playback stutter stops, that is, when playback resumes after there is enough audio buffer.
 * @param player The player object that triggers the callback function.
 * @list playerCallback
 * @order 4
 */
- (void)onStallEnd:(TVLManager *_Nonnull)player;

/**
 * @locale zh
 * @type callback
 * @brief 视频渲染卡顿回调。视频渲染发生卡顿时，触发此回调。
 * @list playerCallback
 * @param player 触发该事件回调的播放器对象。
 * @param stallTime 视频渲染卡顿时长，单位为 ms。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when video rendering stutters.
 * @list playerCallback
 * @param player The player object that triggers the callback function.
 * @param stallTime The stutter duration, in milliseconds.
 */
- (void)onVideoRenderStall:(TVLManager *_Nonnull)player stallTime:(int64_t)stallTime;

/**
 * @locale zh
 * @type callback
 * @brief 音频渲染卡顿回调。音频渲染发生卡顿时，触发此回调。
 * @list playerCallback
 * @param player 触发该事件回调的播放器对象。
 * @param stallTime 音频渲染卡顿时长，单位为 ms。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when audio rendering stutters.
 * @list playerCallback
 * @param player The player object that triggers the callback function.
 * @param stallTime The stutter duration, in milliseconds.
 */
- (void)onAudioRenderStall:(TVLManager *_Nonnull)player stallTime:(int64_t)stallTime;

/**
 * @locale zh
 * @type callback
 * @brief 清晰度档位发生变化回调。
 * @list playerCallback
 * @order 5
 * @param player 触发该事件回调的播放器对象。
 * @param resolution 切换后的清晰度档位，详情请参见 [VeLivePlayerResolution](188121#VeLivePlayerResolution) 。
 * @param error 切换清晰度档位时，是否发生错误，详情请参见 [VeLivePlayerError](188120#VeLivePlayerError)。
 * @param reason 清晰度档位切换的原因，详情请参见 [VeLivePlayerResolutionSwitchReason](188121#VeLivePlayerResolutionSwitchReason) 。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the video resolution changes.
 * @param player The player object that triggers the callback function.
 * @param resolution The updated resolution. See VeLivePlayerResolution {@link #VeLivePlayerResolution} for details.
 * @param error Whether an error occurred during resolution switching. See VeLivePlayerError {@link #VeLivePlayerError} for details.
 * @param reason The reason for resolution switching. See VeLivePlayerResolutionSwitchReason {@link #VeLivePlayerResolutionSwitchReason} for details.
 * @list playerCallback
 * @order 5
 */
- (void)onResolutionSwitch:(TVLManager *_Nonnull)player resolution:(VeLivePlayerResolution)resolution error:(VeLivePlayerError *)error reason:(VeLivePlayerResolutionSwitchReason)reason;

/**
 * @locale zh
 * @type callback
 * @brief 视频分辨率变化回调。视频大小发生变化时，触发此回调。
 * @list playerCallback
 * @order 6
 * @param player 触发该事件回调的播放器对象。
 * @param width 变化后的视频宽度，单位为 px。
 * @param height 变化后的视频高度，单位为 px。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the video size changes.
 * @param player The player object that triggers the callback function.
 * @param width The updated width of the video, in pixels.
 * @param height The updated height of the video, in pixels.
 * @list playerCallback
 * @order 6
 */
- (void)onVideoSizeChanged:(TVLManager *_Nonnull)player width:(int)width height:(int)height;

/**
 * @locale zh
 * @type api
 * @brief 字符串 SEI 消息回调，当播放器 SDK 接收到 SEI 消息时，触发该回调。需要开启 VeLivePlayerConfiguration 中 enableSei 属性。当 enableBinarySei 属性开启时，字符串 SEI 消息将不再发送。
 * @list playerCallback
 * @order 7
 * @param player 触发该事件回调的播放器对象。
 * @param message SEI 信息。
 */
/**
 * @locale en
 * @type api
 * @brief String SEI message callback. This callback is triggered when the player SDK receives an SEI message. It is necessary to enable the `enableSei` property in `VeLivePlayerConfiguration`. When the `enableBinarySei` property is enabled, the string SEI message will no longer be sent.
 * @param player The player object that triggers the callback function.
 * @param message The SEI message.
 * @list playerCallback
 * @order 7
 */
- (void)onReceiveSeiMessage:(TVLManager *_Nonnull)player message:(NSString *_Nonnull)message;

/**
 * @locale zh
 * @type api
 * @brief 二级制 SEI 消息回调，当播放器 SDK 接收到 SEI 消息时，触发该回调。需要开启 VeLivePlayerConfiguration 中 enableBinarySei 属性。当 enableBinarySei 属性开启时，字符串 SEI 消息将不再发送。
 * @list playerCallback
 * @order 7
 * @param player 触发该事件回调的播放器对象。
 * @param message SEI 信息。
 */
/**
 * @locale en
 * @type api
 * @brief Binary SEI message callback. This callback is triggered when the player SDK receives an SEI message. It is necessary to enable the `enableBinarySei` property in `VeLivePlayerConfiguration`. When the `enableBinarySei` property is enabled, the string SEI message will no longer be sent.
 * @param player The player object that triggers the callback function.
 * @param message The SEI message.
 * @list playerCallback
 * @order 7
 */
- (void)onReceiveBinarySeiMessage:(TVLManager *_Nonnull)player message:(NSData *_Nonnull)message;

/**
 * @locale zh
 * @type callback
 * @brief 主备流切换回调。
 * @list playerCallback
 * @order 8
 * @param player 触发该事件回调的播放器对象。
 * @param streamType 切换后的流类型为主路流或备路流，详情请参见 [VeLivePlayerStreamType](188121#VeLivePlayerStreamType) 。
 * @param error 触发主备流切换的原因，详情请参见 [VeLivePlayerError](188120#VeLivePlayerError) 。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the player switches between the primary stream and the backup stream.
 * @param player The player object that triggers the callback function.
 * @param streamType The type of the updated stream. See VeLivePlayerStreamType {@link #VeLivePlayerStreamType} for details.
 * @param error The reason for the switch. See VeLivePlayerError {@link #VeLivePlayerError} for details.
 * @list playerCallback
 * @order 8
 */
- (void)onMainBackupSwitch:(TVLManager *_Nonnull)player streamType:(VeLivePlayerStreamType)streamType error:(VeLivePlayerError *)error;

/**
 * @locale zh
 * @type callback
 * @brief 播放状态发生变化时，触发此回调。
 * @list playerCallback
 * @order 9
 * @param player 触发该事件回调的播放器对象。
 * @param status 当前播放器的状态，详情请参见 [VeLivePlayerStatus](188121#VeLivePlayerStatus) 。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the playback status changes.
 * @param player The player object that triggers the callback function.
 * @param status The updated status of the player. See VeLivePlayerStatus {@link #VeLivePlayerStatus} for details.
 * @list playerCallback
 * @order 9
 */
- (void)onPlayerStatusUpdate:(TVLManager *_Nonnull)player status:(VeLivePlayerStatus)status;

/**
 * @locale zh
 * @type callback
 * @brief 播放信息周期性回调。播放器 SDK 会周期性地回调本方法，您可以通过本方法获取当前播放器的播放地址、码率和帧率等信息。
 * @list playerCallback
 * @order 10
 * @param player 触发该事件回调的播放器对象。
 * @param statistics 播放器周期性回调的统计信息，详情请参见 [VeLivePlayerStatistics](188121#VeLivePlayerStatistics) 。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs periodically to report information such as the current pull stream address, bitrate, and frame rate.
 * @param player The player object that triggers the callback function.
 * @param statistics The playback statistics. See VeLivePlayerStatistics {@link #VeLivePlayerStatistics} for details.
 * @list playerCallback
 * @order 10
 */
- (void)onStatistics:(TVLManager *_Nonnull)player statistics:(VeLivePlayerStatistics *_Nonnull)statistics;

/**
 * @locale zh
 * @type callback
 * @brief 截图成功回调。当播放器调用 snapshot{@link #VeLivePlayer#snapshot} 截图成功后，触发此回调。
 * @list playerCallback
 * @order 11
 * @param player 触发该事件回调的播放器对象。
 * @param image 截图的 UIImage 对象。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when a screenshot is taken after snapshot {@link #VeLivePlayer#snapshot} is called.
 * @param player The player object that triggers the callback function.
 * @param image The UIImage object of the screenshot.
 * @list playerCallback
 * @order 11
 */
- (void)onSnapshotComplete:(TVLManager *_Nonnull)player image:(UIImage *_Nonnull)image;

/**
 * @locale zh
 * @type callback
 * @brief 视频帧回调。调用 [enableVideoFrameObserver:pixelFormat:bufferType:](188118#TVLManager(VeLivePlayer)-enablevideoframeobserver-pixelformat-buffertype) 开启视频帧解析回调后，当播放器成功解码视频帧时，会触发此回调。
 * @notes <br>
 *       如果自定义渲染使用纹理格式，建议在视频帧回调线程中执行渲染操作。
 * @list playerCallback
 * @order 12
 * @param player 触发该事件回调的播放器对象。
 * @param videoFrame 视频帧数据，包含像素格式、封装格式、视频宽高等信息，详情请参见 [VeLivePlayerVideoFrame](188121#VeLivePlayerVideoFrame) 。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the player decodes a video frame. Call [enableVideoFrameObserver:pixelFormat:bufferType:](docs-player-sdk-for-ios-api#TVLManager(VeLivePlayer)-enablevideoframeobserver-pixelformat-buffertype) to enable video frame callback.
 * @notes  <br>
 *       If you use the texture format for external rendering, we recommend that you render the video in the callback thread.
 * @list playerCallback
 * @order 12
 * @param player The player object that triggers the callback function.
 * @param videoFrame The video frame, including the pixel format, encapsulation format, width and height of the video, and other information. See VeLivePlayerVideoFrame {@link #VeLivePlayerVideoFrame} for details.
 */
- (void)onRenderVideoFrame:(TVLManager *_Nonnull)player videoFrame:(VeLivePlayerVideoFrame *_Nonnull)videoFrame;

/**
 * @locale zh
 * @type callback
 * @brief 音频帧回调。调用 [enableAudioFrameObserver:enableRendering:](188118#TVLManager(VeLivePlayer)-enableaudioframeobserver-enablerendering)开启音频帧解析回调后，当播放器成功解码音频帧时，会触发此回调。
 * @notes <br>
 *      回调的音频帧数据为 float32 格式，大端字节序存储。
 * @list playerCallback
 * @order 13
 * @param player 触发该事件回调的播放器对象。
 * @param audioFrame 音频帧数据，详情请参见 [VeLivePlayerAudioFrame](188121#VeLivePlayerAudioFrame)。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the player decodes an audio frame. Call [enableAudioFrameObserver:enableRendering:](docs-player-sdk-for-ios-api#TVLManager(VeLivePlayer)-enableaudioframeobserver-enablerendering) to enable audio frame callback.
 * @notes  <br>
 *      The audio data returned by the callback is of type Float32 and in big-endian byte order.
 * @list playerCallback
 * @order 13
 * @param player The player object that triggers the callback function.
 * @param audioFrame The audio frame. See VeLivePlayerAudioFrame {@link #VeLivePlayerAudioFrame} for details.
 */
- (void)onRenderAudioFrame:(TVLManager *_Nonnull)player audioFrame:(VeLivePlayerAudioFrame *_Nonnull)audioFrame;

/**
 * @locale zh
 * @type callback
 * @brief 超分开启失败。调用 [setEnableSuperResolution:](188118#TVLManager(VeLivePlayer)-setenablesuperresolution)开启超分后，当播放器不支持超分开启或者超分处理出错时，会触发此回调。
 * @list playerCallback
 * @order 14
 * @param player 触发该事件回调的播放器对象。
 * @param error 开启超分失败的原因，错误码请参见 [VeLivePlayerErrorCode](188120#VeLivePlayerErrorCode)。
 */
/**
 * @locale en
 * @type callback
 * @brief Occurs when the SDK fails to enable super resolution after [setEnableSuperResolution:](docs-player-sdk-for-ios-api#TVLManager(VeLivePlayer)-setenablesuperresolution) is called.
 * @list playerCallback
 * @order 14
 * @param player The player object that triggers the callback function.
 * @param error The reason of the failure. See VeLivePlayerErrorCode{@link #VeLivePlayerErrorCode} for details.
 */
- (void)onStreamFailedOpenSuperResolution:(TVLManager *_Nonnull)player error:(VeLivePlayerError *_Nullable)error;

/**
 * @locale zh
 * @type callback
 * @brief 您需要在此回调中返回 FairPlay 证书的 NSData 数据。
 * @list playerCallback
 * @order 15
 * @param player 触发该事件回调的播放器对象。
 */
/**
 * @locale en
 * @type callback
 * @brief You need to return the FairPlay certificate in NSData format in this callback. 
 * @param player The player instance that triggers the callback.
 * @list playerCallback
 * @order 15
 */
- (NSData *)getDrmResourceLoaderCertificateData:(TVLManager *_Nonnull)player;

/**
 * @locale zh
 * @type callback
 * @brief 您需要在此回调中返回 DRM license 的 URL。
 * @list playerCallback
 * @order 16
 * @param player 触发该事件回调的播放器对象。
 */
/**
 * @locale en
 * @type callback
 * @brief You need to return the URL of the DRM license in this callback.
 * @list playerCallback
 * @order 16
 * @param player The player instance that triggers the callback.
 */
- (NSString *)getDrmResourceLoaderLicenseUrl:(TVLManager *_Nonnull)player;

 /**
  * @locale zh
 * @hidden
 * @type callback
 * @brief Occurs when the player log should be uploaded.
 * @param player The player object that triggers the callback function.
 * @param event event info.
 * @param tag event tag.
 */
/**
 * @locale en
 * @list 
 * @hidden (iOS)
 */
/**
 * @locale zh
 * @list 
 * @hidden (Windows,Linux,macOS,Android,iOS)
 */
- (void)onMonitorLog:(TVLManager *_Nonnull)player event:(NSDictionary* _Nonnull)event tag:(NSString* _Nonnull)tag;


@end
