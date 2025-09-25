
/**
 Copyright (c) 2023 The VeLivePlayer project authors. All Rights Reserved.
 @brief VeLivePlayer
*/

#import "TVLManager+Interface.h"
#import "VeLivePlayerObserver.h"

@class VeLivePlayerLogConfig;

/**
 * @locale en
 * @brief Player Type.
 * @type keytype
 */
/**
 * @locale zh
 * @brief 播放器类型。
 * @type keytype
 */
typedef enum : NSUInteger {
    /**
     * @locale zh
     * @brief 自研播放器。
     */
    /**
     * @locale en
     * @brief Custom player.
     */
    VeLivePlayerTypeOwn,
    /**
     * @locale zh
     * @brief 系统播放器。
     */
    /**
     * @locale en
     * @brief System player.
     */
    VeLivePlayerTypeSystem,
} VeLivePlayerType;

NS_ASSUME_NONNULL_BEGIN
/**
 * @locale zh
 * @type api
 * @brief 直播播放器。
 */
/**
 * @locale en
 * @type api
 * @brief The live player.
 */
@interface TVLManager (VeLivePlayer)

/**
 * @locale zh
 * @type keytype
 * @brief 播放器的回调事件监听器。
 */
/**
 * @locale en
 * @type keytype
 * @brief The player observer.
 */
@property (nonatomic, weak, readonly, nullable) id<VeLivePlayerObserver> observer;

/**
 * @locale zh
 * @type keytype
 * @brief 获取播放器内部用于渲染视频画面的视图 view，调用本方法将 playerView 添加到应用的视图层级中，实现视频内容显示。
 */
/**
 * @locale en
 * @type keytype
 * @brief The view used by the player to render video. Add `playerView` to the view hierarchy of your app to display the video content.
 */
@property (nonatomic, strong, readonly) UIView *playerView;

/**
 * @locale zh
 * @type keytype
 * @brief 设置或获取播放器播放音量，默认值为 1.0。取值范围为 0.0～1.0。
 */
/**
 * @locale en
 * @type keytype
 * @brief The player volume. The default value is `1.0`. The value range is [0.0, 1.0].
 */
@property (nonatomic, assign) float volume;

/** 
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 设置或获取播放器播放音量，默认值为 1.0。取值范围为 0.0～1.0。
 */
/** 
 * @locale en
 * @hidden
 * @type keytype
 * @brief The player volume. The default value is `1.0`. The value range is [0.0, 1.0].
 */
@property (nonatomic, assign) float playerVolume;

/**
 * @locale en
 * @hidden (Windows,Linux,macOS,Android,iOS)
 * @type keytype
 * @brief You can use it to  ignore audio Interruption
 */
/**
 * @locale zh
 * @list 
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL ignoreAudioInterruption;


/**
 * @locale zh
 * @type keytype
 * @brief 检查播放器是否正在播放。
 * @return 是否正在播放。<br>
 *      - YES：正在播放；
 *      - NO：未播放。
 */
/**
 * @locale en
 * @type keytype
 * @brief Checks whether the player is playing.
 * @return Whether the player is playing. <br>
 *       - YES: The player is playing;
 *       - NO: The player is not playing.
 */
@property (nonatomic, assign, readonly) BOOL isPlaying;

/**
 * @locale zh
 * @type api
 * @brief 播放器初始化方法。
 * @list playerMethod
 * @order 9
 */
/**
 * @locale en
 * @type api
 * @brief Initializes the player.
 * @list playerMethod
 * @order 9
 */
- (instancetype)init;

/**
 * @locale en
 * @brief Initializes the specified type of player.
 * @list playerMethod
 * @param type The player type. Refer to [VeLivePlayerType](docs-player-sdk-for-ios-type-definition#VeLivePlayerType) for details.
 */
/**
 * @locale zh
 * @brief 初始化特定类型的播放器。
 * @list playerMethod
 * @param type 播放器类型，详情请参见 [VeLivePlayerType](188121#VeLivePlayerType)。
 */
- (instancetype)initWithType:(VeLivePlayerType)type;

/**
 * @locale zh
 * @type api
 * @brief 初始化播放器，用于设置是否开启 SEI 消息、是否开启硬件解码和是否开启本地 DNS 预解析等配置信息。
 * @notes 
 *     需要在调用 play{@link #VeLivePlayer#play} 开始播放之前，调用本方法进行播放器的初始化。
 * @param config 播放器配置信息，详情请参见 VeLivePlayerConfiguration{@link #VeLivePlayerConfiguration}。
 * @list playerMethod
 * @order 1
 */
/**
 * @locale en
 * @type api
 * @brief Configures player settings, including whether to turn on SEI messaging, hardware decoding, and local DNS prefetch.
 * @notes  <br>
 *     Call this method before calling play {@link #VeLivePlayer#play}.
 * @param config Player configurations. Refer to VeLivePlayerConfiguration {@link #VeLivePlayerConfiguration} for details.
 * @list playerMethod
 * @order 1
 */
- (void)setConfig:(VeLivePlayerConfiguration *_Nonnull)config;

/**
 * @locale zh
 * @type api
 * @brief 设置播放器回调，用于监听播放器 VeLivePlayer 的播放错误、播放状态、音视频首帧渲染状态和清晰度档位信息等回调事件。
 * @notes 
 *     需要在调用 play{@link #VeLivePlayer#play} 开始播放之前，调用本方法设置回调。
 * @param observer 播放器的事件回调对象。详情请参见 VeLivePlayerObserver{@link #VeLivePlayerObserver}。
 * @list playerMethod
 * @order 2
 */
/**
 * @locale en
 * @type api
 * @brief Sets the player observer to listen to the VeLivePlayer's events, such as playback errors or status updates, rendering of the first audio and video frame, and resolution switching.
 * @notes  <br>
 *     Call this method before calling play {@link #VeLivePlayer#play}.
 * @param observer The player observer. See VeLivePlayerObserver {@link #VeLivePlayerObserver} for details.
 * @list playerMethod
 * @order 2
 */
- (void)setObserver:(id<VeLivePlayerObserver> _Nullable)observer;

/**
 * @locale zh
 * @type api
 * @brief 设置播放器画面的填充模式。
 * @notes 
 *        - 如果用于起播设置，需要在调用 [play](#TVLManager(VeLivePlayer)-play) 开始播放之前，调用本方法设置视频的填充模式。
 *        - 如果用于调节填充模式，可以在播放过程中调用本方法动态调节视频的填充模式。
 * @list playerMethod
 * @order 3
 * @param fillMode 设置 SurfaceView 的填充模式，默认值为 `VeLivePlayerFillModeAspectFill`，详情请参见 [VeLivePlayerFillMode](188121#VeLivePlayerFillMode)。
 */
/**
 * @locale en
 * @type api
 * @brief Sets the fill mode of the player screen.
 * @notes 
 *        - Call this method before calling [play](#TVLManager(VeLivePlayer)-play) to set the initial fill mode of the player.
 *        - You can call this method during playback to dynamically adjust the fill mode.
 * @list playerMethod
 * @order 3
 * @param fillMode The fill mode of SurfaceView. The default value is `VeLivePlayerFillModeAspectFill`. See VeLivePlayerFillMode {@link #VeLivePlayerFillMode} for details.
 */
- (void)setRenderFillMode:(VeLivePlayerFillMode)fillMode;

/**
 * @locale zh
 * @type api
 * @brief 设置打印日志的级别。
 * @list playerMethod
 * @order 5
 * @param logLevel 日志级别，详情请参见 [VeLivePlayerLogLevel](188121#VeLivePlayerLogLevel) 。
 */
/**
 * @locale en
 * @type api
 * @brief Sets the level of the output log.
 * @param logLevel The level of the output log. For details, see VeLivePlayerLogLevel{@link #VeLivePlayerLogLevel}.
 * @list playerMethod
 * @order 5
 */
+ (void)setLogLevel:(VeLivePlayerLogLevel)logLevel;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 日志设置。
 * @param logConfig 日志设置. 详情请参见 VeLivePlayerLogConfig {@link #VeLivePlayerLogConfig}
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief Configures log settings.
 * @param logConfig Log settings. See VeLivePlayerLogConfig {@link #VeLivePlayerLogConfig} for details.
 */
+ (void)setLogConfig:(nonnull VeLivePlayerLogConfig *)logConfig;

/**
 * @locale zh
 * @type api
 * @brief 设置单个直播播放地址。
 * @notes <br/>
 *        需要在调用 [play](#TVLManager(VeLivePlayer)-play) 开始播放之前，调用本方法设置单个直播播放地址。
 * @list playerMethod
 * @order 6
 * @param url 直播播放地址
 */
/**
 * @locale en
 * @type api
 * @brief Sets a pull stream address.
 * @notes <br/>
 *        Call this method before calling [play](#TVLManager(VeLivePlayer)-play).
 * @list playerMethod
 * @order 6
 * @param url The pull stream address.
 */
- (void)setPlayUrl:(NSString *_Nonnull)url;

/**
 * @locale zh
 * @type api
 * @brief 获取播放器 SDK 的版本号。
 * @return
 *     播放器 SDK 版本号。
 * @list playerMethod
 * @order 4
 */
/**
 * @locale en
 * @type api
 * @brief Gets the version number of the Player SDK.
 * @return  <br>
 *     The version number of the Player SDK.
 * @list playerMethod
 * @order 4
 */
+ (NSString *_Nonnull )getVersion;

/**
 * @locale zh
 * @type api
 * @brief 设置域名和服务器的 IP 地址映射关系。
 * @param hostIpMap 域名和服务器 IP 地址的映射关系列表。其中 `Map` 的 Key 是域名，Value 是 `List` 类型，表示该域名对应的服务器 IP 地址列表
 * @list playerMethod
 * @order 17
 */
/**
 * @locale en
 * @type api
 * @brief Sets the mapping of domain names to server IP addresses.
 * @param hostIpMap The mapping of domain names to server IP addresses. The `Map` object uses the domain name as the key, and the corresponding value is a list of IP addresses for the servers associated with that domain. The value is of the `List` type.
 * @list playerMethod
 * @order 17
 */
- (void)setUrlHostIP:(NSDictionary *_Nonnull)hostIpMap;


/**
 * @hidden
 * @locale en
 * @brief Sets the mapping of domain names to server IP addresses.
 * @list playerMethod
 * @param hostIpMap The mapping of domain names to server IP addresses. The `Map` object uses the domain name as the key, and the corresponding value is a list of IP addresses for the servers associated with that domain. The value is of the `List` type.
 */
/**
 * @hidden
 * @locale zh
 * @brief 设置域名和服务器的 IP 地址映射关系。
 * @list playerMethod
 * @param hostIpMap 域名和服务器 IP 地址的映射关系列表。其中 `Map` 的 Key 是域名，Value 是 `List` 类型，表示该域名对应的服务器 IP 地址列表。
 */
+ (void)setHttpDNSHostIP:(NSDictionary *_Nonnull)hostIpMap;

/**
 * @locale zh
 * @type api
 * @brief 设置播放器高级配置。高级配置包括离屏渲染设置、缓冲区最大时长、ABR 码率自适应算法类型等，如需了解详细信息，请联系[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
 * @list playerMethod
 * @order 18
 * @param key 高级配置的参数名。
 * @param value 参数对应的参数值。
 */
/**
 * @locale en
 * @type api
 * @brief Configures advanced settings for the player, including offscreen rendering, maximum buffer duration, and adaptive bitrate (ABR) algorithms. [Create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support if you need further information.
 * @param key The parameter name of the advanced setting.
 * @param value The parameter value of the advanced setting.
 * @list playerMethod
 * @order 18
 */
- (void)setProperty:(NSString *_Nonnull)key value:(id _Nonnull)value;

/**
 * @locale zh
 * @type api
 * @brief 多路流信息配置。例如，您需要使用 ABR、手动切档和主备流等依赖多路流的功能，可以调用本方法进行配置。
 * @notes 
 *      需要在调用 play{@link #VeLivePlayer#play} 开始播放之前，调用本方法设置多路流信息。
 * @list playerMethod
 * @order 7
 * @param streamData 多路流信息配置。详情请参见 [VeLivePlayerStreamData](188121#VeLivePlayerStreamData) 。
 */
/**
 * @locale en
 * @type api
 * @brief Sets multiple live streams. Call this method if you need to enable features requiring multiple live streams, such as adaptive bitrate (ABR), manual resolution switching, and primary and backup streams.
 * @param streamData Configurations for multiple pull stream addresses. See VeLivePlayerStreamData {@link #VeLivePlayerStreamData} for details.
 * @notes  <br>
 *       Call this method before calling play {@link #VeLivePlayer#play}.
 * @list playerMethod
 * @order 7
 */
- (void)setPlayStreamData:(VeLivePlayerStreamData *_Nonnull)streamData;


/**
 * @locale en
 * @list 
 * @hidden (iOS)
 * @param item
 */
/**
 * @locale zh
 * @list
 * @hidden (iOS)
 * @brief 预创建播放器。
 * @notes 调用本方法会提前触发播放准备工作，包括预建连等。
 * @param item 待播放的直播流信息。
 */
- (void)prepare:(TVLPlayerItem *_Nonnull)item;

/**
 * @locale zh
 * @type api
 * @brief 开始/恢复播放。
 * @notes <br/>
 *        调用本方法，在播放器完成拉流准备和首帧渲染播放后，都会触发 [onPlayerStatusUpdate:status:](188119#VeLivePlayerObserver-onplayerstatusupdate-status) 播放器状态回调。
 * @list playerMethod
 * @order 10
 */
/**
 * @locale en
 * @type api
 * @brief Starts or resumes playback.
 * @notes <br/>
 *        After you call this method, the [onPlayerStatusUpdate:status:](docs-player-sdk-for-ios-callback#VeLivePlayerObserver-onplayerstatusupdate-status) callback is triggered both when the player finishes preparing for stream pulling and when the first frame is rendered.
 * @list playerMethod
 * @order 10
 */
- (void)play;

/**
 * @locale zh
 * @type api
 * @brief 暂停播放。
 * @notes 调用本方法暂停播放后，会触发 [onPlayerStatusUpdate:status:](188119#VeLivePlayerObserver-onplayerstatusupdate-status) 播放器状态回调。
 * @list playerMethod
 * @order 11
 */
/**
 * @locale en
 * @type api
 * @brief Pauses playback.
 * @notes <br/>
 *        When playback is paused after you call this method, the [onPlayerStatusUpdate:status:](docs-player-sdk-for-ios-callback#VeLivePlayerObserver-onplayerstatusupdate-status) callback is triggered.
 * @list playerMethod
 * @order 11
 */
- (void)pause;

/**
 * @locale zh
 * @type api
 * @brief 停止播放，不销毁播放器。
 * @notes 调用本方法停止播放后，会触发 [onPlayerStatusUpdate:status:](188119#VeLivePlayerObserver-onplayerstatusupdate-status) 播放器状态回调。
 * @list playerMethod
 * @order 12
 */
/**
 * @locale en
 * @type api
 * @brief Stops playback. This method does not destroy the player.
 * @notes <br/>
 *        When playback stops after you call this method, the [onPlayerStatusUpdate:status:](docs-player-sdk-for-ios-callback#VeLivePlayerObserver-onplayerstatusupdate-status) callback is triggered.
 * @list playerMethod
 * @order 12
 */
- (void)stop;

/**
 * @locale zh
 * @type api
 * @brief 停止播放，并销毁播放器。
 * @list playerMethod
 * @order 13
 */
/**
 * @locale en
 * @type api
 * @brief Stops playback and destroys the player.
 * @list playerMethod
 * @order 13
 */
- (void)destroy;


/**
 * @locale zh
 * @list playerMethod
 * @brief 检查播放器当前是否支持指定的分辨率档位。
 * @param resolution 分辨率档位，详情请参见 [VeLivePlayerResolution](188121#VeLivePlayerResolution)。
 * @return - 0：支持；
 *         - 其他：不支持。其他返回值详情请参见 [VeLivePlayerSupportResolutionSwitchError](188121#VeLivePlayerSupportResolutionSwitchError)。
 */
/**
 * @locale en
 * @list playerMethod
 * @brief Check whether the player currently supports the specified resolution level.
 * @param resolution Resolution levels. For details, please refer to [VeLivePlayerResolution](docs-player-sdk-for-ios-type-definition#VeLivePlayerResolution).
 * @return - 0: Supported;
 *         - Others: Not supported. For details of other return values, please refer to [VeLivePlayerSupportResolutionSwitchError](docs-player-sdk-for-ios-type-definition#VeLivePlayerSupportResolutionSwitchError).
 */
- (int)isSupportResolutionSwitch:(VeLivePlayerResolution)resolution;

/**
 * @locale zh
 * @type api
 * @brief 切换播放的清晰度档位。
 * @notes <br/>
 *        - 需要在调用 [setPlayStreamData:](#TVLManager(VeLivePlayer)-setplaystreamdata) 设置多档位后，调用本方法切换播放器的清晰度档位。
 *        - 调用本方法成功切换档位后，会触发清晰度档位变化 [onResolutionSwitch:resolution:error:reason:](188119#VeLivePlayerObserver-onresolutionswitch-resolution-error-reason) 回调。
 * @list playerMethod
 * @order 14
 * @param resolution 设置清晰度的目标档位，详情请参见 [VeLivePlayerResolution](188121#VeLivePlayerResolution) 。
 * @return
 *     - YES：成功；
 *     - NO：失败。
 */
/**
 * @locale en
 * @type api
 * @brief Changes the video resolution.
 * @notes <br/>
 *        - Call [setPlayStreamData:](#TVLManager(VeLivePlayer)-setplaystreamdata) to set multiple resolutions before calling this method.
 *        - Once the player switches to the new resolution after you call this method, the [onResolutionSwitch:resolution:error:reason:](docs-player-sdk-for-ios-callback#VeLivePlayerObserver-onresolutionswitch-resolution-error-reason) callback is triggered.
 * @list playerMethod
 * @order 14
 * @param resolution The video resolution. See VeLivePlayerResolution {@link #VeLivePlayerResolution} for details.
 * @return  <br>
 *     - YES: Success;
 *     - NO: Failure.
 */
- (void)switchResolution:(VeLivePlayerResolution)resolution;

/**
 * @locale zh
 * @type api
 * @brief 设置是否静音播放。
 * @param mute 是否开启静音播放，默认值为 NO。<br>
 *             - YES：开启；
 *             - NO：关闭。
 * @list playerMethod
 * @order 15
 */
/**
 * @locale en
 * @type api
 * @brief Sets whether to mute playback.
 * @param mute Whether to mute playback. The default value is `NO`. <br>
 *              - YES: Mute;
 *              - NO: Do not mute.
 * @list playerMethod
 * @order 15
 */
- (void)setMute:(BOOL)mute;

/**
 * @locale zh
 * @type api
 * @brief 获取是否处于静音状态。
 * @return 是否处于静音状态。<br>
 *     - YES：静音；
 *     - NO：未静音。
 * @list playerMethod
 * @order 16
 */
/**
 * @locale en
 * @type api
 * @brief Checks whether playback is muted.
 * @return Whether playback is muted. <br>
 *      - YES: Muted;
 *      - NO: Not muted.
 * @list playerMethod
 * @order 16
 */
- (BOOL)isMute;

/**
 * @locale zh
 * @type api
 * @brief 设置视频顺时针旋转角度。
 * @notes 
 *      - 支持在播放前和播放中动态修改视频旋转角度。
 *      - 每次调用本方法，播放器都将基于图像的原始角度进行旋转。
 *      - 当同时使用旋转和镜像功能，播放器会先进行镜像，再进行旋转。
 * @list playerMethod
 * @order 23
 * @param rotation 视频旋转角度，默认关闭旋转，详情请参见 [VeLivePlayerRotation](188121#VeLivePlayerRotation) 。
 */
/**
 * @locale en
 * @type api
 * @brief Sets the clockwise rotation angle of the video.
 * @param rotation The clockwise rotation angle of the video. Rotation is disabled by default. See VeLivePlayerRotation {@link #VeLivePlayerRotation} for details.
 * @notes  <br>
 *       - You can change the rotation angle before and during playback.
 *       - Each time this method is called, the player rotates the video based on the original video.
 *       - When you apply both rotation and mirroring to the video, the player will mirror the video and then rotate it.
 * @list playerMethod
 * @order 23
 */
- (void)setRenderRotation:(VeLivePlayerRotation)rotation;

/**
 * @locale zh
 * @type api
 * @brief 设置视频镜像。
 * @notes 
 *      - 支持在播放前和播放中动态修改视频镜像方式。
 *      - 每次调用本方法，播放器都将基于原始图像进行镜像。
 *      - 当同时使用旋转和镜像功能，播放器会先进行镜像，再进行旋转。
 * @list playerMethod
 * @order 24
 * @param mirror 视频镜像，默认关闭镜像，详情请参见 [VeLivePlayerMirror](188121#VeLivePlayerMirror) 。
 */
/**
 * @locale en
 * @type api
 * @brief Configures mirroring settings.
 * @param mirror Mirroring settings. Mirroring is disabled by default. See VeLivePlayerMirror {@link #VeLivePlayerMirror} for details.
 * @notes  <br>
 *       - You can change the mirroring settings before and during playback.
 *       - Each time this method is called, the player applies the mirroring settings to the original video.
 *       - When you apply both rotation and mirroring to the video, the player will mirror the video and then rotate it.
 * @list playerMethod
 * @order 24
 */
- (void)setRenderMirror:(VeLivePlayerMirror)mirror;

/**
 * @locale zh
 * @type api
 * @brief 视频截图。
 * @notes <br/>
 *        - 本方法仅在视频状态为播放时生效。
 *        - 调用本方法截图成功后，会触发 [onSnapshotComplete:image:](188119#VeLivePlayerObserver-onsnapshotcomplete-image) 回调，回调消息中包含截图的 UIImage 对象。
 * @list playerMethod
 * @order 19
 * @return
 *     - 0：当前状态支持截图；
 *     - VeLivePlayerErrorRefused{@link #VeLivePlayerErrorCode#VeLivePlayerErrorRefused}：当前状态不支持截图。
 */
/**
 * @locale en
 * @type api
 * @brief Takes a screenshot of the video.
 * @notes 
 *        - This method only takes effect during playback.
 *        - When a screenshot is captured after you call this method, the [onSnapshotComplete:image:](docs-player-sdk-for-ios-callback#VeLivePlayerObserver-onsnapshotcomplete-image) callback is triggered containing the `UIImage` object of the screenshot.
 * @list playerMethod
 * @order 19
 * @return 
 *      - 0: Screenshot capturing is allowed;
 *      - VeLivePlayerErrorRefused {@link #VeLivePlayerErrorCode#VeLivePlayerErrorRefused}: Screenshot capturing is not allowed.
 */
- (int)snapshot;

/**
 * @locale zh
 * @type api
 * @brief 设置视频帧回调。
 * @notes 
 *        - 您可以在使用外部渲染的场景下调用本方法，订阅视频帧的解码数据。
 *        - 调用本方法后，会触发 onRenderVideoFrame:videoFrame:回调，回调消息中包含每个视频帧的详细数据。
 *        - 如果您使用外部渲染，需要保证音视频同步。
 * @list playerMethod
 * @order 20
 * @param enable 是否开启视频帧回调，默认值为 NO。 <br>
 *               - YES：开启；
 *               - NO：关闭。
 * @param pixelFormat 回调的视频帧像素格式，详情请参见 [VeLivePlayerPixelFormat](188121#VeLivePlayerPixelFormat) 。
 * @param bufferType 回调的视频数据封装格式。详情请参见 [VeLivePlayerVideoBufferType](188121#VeLivePlayerVideoBufferType) 。
 */
/**
 * @locale en
 * @type api
 * @brief Sets the video frame observer.
 * @notes 
 *        - You can call this method to subscribe to decoded video data for external rendering.
 *        - After you call this method, the onRenderVideoFrame:videoFrame:is triggered once the SDK receives a video frame. The callback contains detailed information of the video frame.
 *        - If you use external rendering, you need to make sure the video and audio are synchronized.
 * @list playerMethod
 * @order 20
 * @param enable Whether to enable the video frame callback. The default value is `NO`. <br>
 *                - YES: Enable;
 *                - NO: Disable.
 * @param pixelFormat The pixel format of the video frame in the callback. See VeLivePlayerPixelFormat {@link #VeLivePlayerPixelFormat} for details.
 * @param bufferType The encapsulation format of the video data in the callback. See VeLivePlayerVideoBufferType {@link #VeLivePlayerVideoBufferType} for details.
 */
- (void)enableVideoFrameObserver:(BOOL)enable pixelFormat:(VeLivePlayerPixelFormat)pixelFormat bufferType:(VeLivePlayerVideoBufferType)bufferType;

/**
 * @locale zh
 * @type api
 * @brief 设置音频帧回调。
 * @notes 
 *        - 您可以在使用外部渲染的场景下调用本方法，订阅音频帧的解码数据。
 *        - 调用本方法后，会触发 [onRenderAudioFrame:audioFrame:](188119#VeLivePlayerObserver-onrenderaudioframe-audioframe) 回调，回调消息中包含每个音频帧的详细数据。
 *        - 如果您使用外部渲染，需要保证音视频同步。
 * @list playerMethod
 * @order 21
 * @param enable 是否开启音频帧回调，默认值为 NO。 <br>
 *               - YES：开启；
 *               - NO：关闭。
 * @param enableRendering 是否开启播放器渲染。默认值为 NO。<br>
 *                        - YES：开启；
 *                        - NO：关闭。
 */
/**
 * @locale en
 * @type api
 * @brief Sets the audio frame observer.
 * @notes <br/>
 *        - You can call this method to subscribe to decoded audio data for external rendering.
 *        - After you call this method, the [onRenderAudioFrame:audioFrame:](docs-player-sdk-for-ios-callback#VeLivePlayerObserver-onrenderaudioframe-audioframe) callback is triggered once the SDK receives a audio frame. The callback contains detailed information of the audio frame.
 *        - If you use external rendering, you need to make sure the video and audio are synchronized.
 * @list playerMethod
 * @order 21
 * @param enable Whether to enable the audio frame callback. The default value is `NO`. <br>
 *                - YES: Enable;
 *                - NO: Disable.
 * @param enableRendering Whether to enable player rendering. The default value is `NO`. <br>
 *                         - YES: Enable;
 *                         - NO: Disable.
 */
- (void)enableAudioFrameObserver:(BOOL)enable enableRendering:(BOOL)enableRendering;

/**
 * @locale zh
 * @type api
 * @brief 设置是否开启超分。
 * @notes 
 *        - 在收到首帧回调后，调用该方法开启超分。
 *        - 支持在播放中调用该接口，开启或关闭超分。
 *        - 如果机型、分辨率和帧率不符合限制，将无法开启超分，并触发 [onStreamFailedOpenSuperResolution:error:](188119#VeLivePlayerObserver-onstreamfailedopensuperresolution-error) 回调。
 * @list playerMethod
 * @order 22
 * @param enable 是否开启，默认值为 NO。<br>
 *                        - YES：开启；
 *                        - NO：关闭。
 */
/**
 * @locale en
 * @type api
 * @brief Enables or disables super resolution.
 * @notes <br/>
 *        - Call this method after receiving the onFirstVideoFrameRender:isFirstFrame:callback, or during playback.
 *        - Support calling this method during playback to turn on or off super-resolution.
 *        - If the SDK fails to enable super resolution due to device model, video resolution or frame rate, you will receive the [onStreamFailedOpenSuperResolution:error:](docs-player-sdk-for-ios-callback#VeLivePlayerObserver-onstreamfailedopensuperresolution-error).
 * @list playerMethod
 * @order 22
 * @param enable Whether to enable super resolution. The default value is NO. <br/>
 *        - YES: Turn on;
 *        - NO: Turn off.
 */
- (void)setEnableSuperResolution:(BOOL)enable;

/**
 * @locale zh
 * @hidden
 * @type api
 * @notes 
 *      - This method is used to activate the render
 *      - You should call this method in app delegate's applicationDidBecomeActive: method, or it may result
 *      - in no picture.
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
+ (void)startOpenGLESActivity;

/**
 * @locale zh
 * @hidden
 * @type api
 * @notes 
 *      - This method is used to deactive the render
 *      - You should call this method in app delegate's applicationWillResignActive: method, or it may leads
 *      - to crash.
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
+ (void)stopOpenGLESActivity;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief mute all
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
+ (void)setGlobalMute:(BOOL)mute;

/**
 * @locale zh
 * @hidden
 * @type api
 * @param SDKType Type of the sdk; 0: VeLivePlayer, 1:VeLivePusher, 2:LiveIO, 3:RTSPlayer
 * @param command Special command.
 * @param hashCode Indicate the instance of the SDK (Optional)
 * @param info Extra info, Must be a Json format.
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
+ (NSDictionary *_Nullable)executeVePlayerCommand:(NSInteger)SDKType command:(NSInteger)command hashCode:(NSInteger)hashCode info:(NSDictionary *_Nullable) info;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Gets the  video stream info. width, height and fps.
 * @return Video stream info.
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
- (VeLivePlayerVideoStreamInfo *_Nonnull)getVideoStreamInfo;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Using ceallular network
 * @notes  <br>
 *     Call this method before calling play {@link #VeLivePlayer#play}.
 * @return Video stream info.
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
- (void)setUsingCellularNetwork:(BOOL)usingCellularNetwork;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief switch to ceallular network,
 * @notes  <br>
 *     Call this method after calling play {@link #VeLivePlayer#play}.
 * @return  <br>
 *     - 0: Success;
 *     - <0: Failure.
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
- (int)switchToCellularNetwork:(int)reason detail:(NSString*)detail;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief switch to default network,
 * @notes  <br>
 *     Call this method after calling play {@link #VeLivePlayer#play}.
 * @return  <br>
 *     - 0: Success;
 *     - <0: Failure.
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
- (int)switchToDefaultNetwork:(int)reason detail:(NSString*)detail;

/**
 * @locale zh
 * @type api
 * @brief 获取流信息。
 * @notes - 在 [VeLivePlayerStatus](188121#VeLivePlayerStatus)（播放器状态）为 `VeLivePlayerStatusPrepared` 时，调用该方法。
 *        - 该方法目前仅适用于 HLS 格式的流。
 * @list playerMethod
 * @order 22
 */
/**
 * @type api
 * @brief Gets the  stream info
 * @notes  <br>
 *     After receiving the player status to VeLivePlayerStatusPrepare after receiving player status to VeLivePlayerStatusPrepared, invoke this method（This method currently only works for streams in HLS format）.
 * @return  <br>
 *     + 0: Success;
 *     + <0: Failure.
 */
/**
 * @locale en
 * @brief Gets the stream information.
 * @notes - Call this method when the [VeLivePlayerStatus](docs-player-sdk-for-ios-type-definition#VeLivePlayerStatus) (player status) is `VeLivePlayerStatusPrepared`.
 *        - This method is currently only applicable to HLS format streams.
 * @list playerMethod
 */
- (NSArray<VeLivePlayerStreamInfo *> *)getStreamList;


@end
NS_ASSUME_NONNULL_END
