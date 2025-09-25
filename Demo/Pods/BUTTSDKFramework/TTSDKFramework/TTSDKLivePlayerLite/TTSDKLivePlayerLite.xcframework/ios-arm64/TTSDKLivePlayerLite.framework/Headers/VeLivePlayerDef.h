
/**
 Copyright (c) 2023 The VeLivePlayer project authors. All Rights Reserved.
 @brief VeLivePlayerDef
*/

/**
 * @locale zh
 * @type keytype
 * @brief 直播播放器状态。
 * 
 */
/**
 * @locale en
 * @type keytype
 * @brief The status of the live player.
 * 
 */
typedef NS_ENUM(NSInteger, VeLivePlayerStatus) {
    /**
     * @locale zh
     * @brief 播放器准备完成，等待渲染。
     */
    /**
     * @locale en
     * @brief The player finishes preparing and is waiting to render the video.
     */
    VeLivePlayerStatusPrepared,

    /**
     * @locale zh
     * @brief 正在播放状态。
     */
    /**
     * @locale en
     * @brief Playback is currently in progress, meaning that the first frame has been rendered and no errors have occurred to the player.
     */
    VeLivePlayerStatusPlaying,

    /**
     * @locale zh
     * @brief 暂停播放状态。
     */
    /**
     * @locale en
     * @brief The playback is paused.
     */
    VeLivePlayerStatusPaused,

    /**
     * @locale zh
     * @brief 停止播放状态。
     */
    /**
     * @locale en
     * @brief The playback is stopped.
     */
    VeLivePlayerStatusStopped,

    /**
     * @locale zh
     * @brief 播放器发生错误。
     */
    /**
     * @locale en
     * @brief An error has occurred to the player.
     */
    VeLivePlayerStatusError,
};

/**
 * @locale zh
 * @type keytype
 * @brief 直播播放器日志打印级别。
 */
/**
 * @locale en
 * @type keytype
 * @brief The output log level of the player.
 */
typedef NS_ENUM(NSUInteger, VeLivePlayerLogLevel) {
    /**
     * @locale zh
     * @brief 输出 VERBOSE、DEBUG、INFO、WARNING 和 ERROR 级别的日志。
     */
    /**
     * @locale en
     * @brief Output logs at the VERBOSE, DEBUG, INFO, WARNING, and ERROR levels.
     */
    VeLivePlayerLogLevelVerbose,
    /**
     * @locale zh
     * @brief 输出 DEBUG、INFO、WARNING 和 ERROR 级别的日志。
     */
    /**
     * @locale en
     * @brief Output logs at the DEBUG, INFO, WARNING, and ERROR levels.
     */
    VeLivePlayerLogLevelDebug,
    /**
     * @locale zh
     * @brief 输出 INFO、WARNING 和 ERROR 级别的日志。
     */
    /**
     * @locale en
     * @brief Output logs at the INFO, WARNING, and ERROR levels.
     */
    VeLivePlayerLogLevelInfo,
    /**
     * @locale zh
     * @brief 输出 WARNING 和 ERROR 级别的日志。
     */
    /**
     * @locale en
     * @brief Output logs at the WARNING and ERROR levels.
     */
    VeLivePlayerLogLevelWarn,
    /**
     * @locale zh
     * @brief 输出 ERROR 级别的日志。
     */
    /**
     * @locale en
     * @brief Output logs at the ERROR level.
     */
    VeLivePlayerLogLevelError,
    /**
     * @locale zh
     * @brief 关闭日志打印。
     */
    /**
     * @locale en
     * @brief Disable log printing.
     */
    VeLivePlayerLogLevelNone,
};

/**
 * @locale zh
 * @type keytype
 * @brief 直播播放器画面的填充模式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The fill mode of the player screen.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerFillMode) {
    /**
     * @locale zh
     * @brief 视频填满画布。视频帧等比缩放，直至填满画布，超出屏幕的部分将被裁剪，画面可能不完整。
     */
    /**
     * @locale en
     * @brief Uniformly scale the video until the screen is completely filled. Part of the video may be cropped.
     */
    VeLivePlayerFillModeAspectFill,

    /**
     * @locale zh
     * @brief 显示完整的视频帧。视频帧等比缩放，直至视频帧恰好在画布上全部显示。如果视频帧长宽比例与画布不同，视窗上未被视频帧填满区域将填充为黑色。
     */
    /**
     * @locale en
     * @brief Display the full video. The video is uniformly scaled until one dimension of the video hits the boundary of the screen. Any remaining space on the screen will be filled with black.
     */
    VeLivePlayerFillModeAspectFit,

    /**
     * @locale zh
     * @brief 视频帧自适应画布。视频帧非等比缩放，直至填满画布。在此过程中，视频帧的长宽比例可能会发生变化。
     */
    /**
     * @locale en
     * @brief Stretch the video to fill the screen. The aspect ratio of the video might change.
     */
    VeLivePlayerFillModeFullFill,
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频帧像素格式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The pixel format of the video frame.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerPixelFormat) {
    /**
     * @locale zh
     * @brief 未知格式。
     */
    /**
     * @locale en
     * @brief Unknown format.
     */
    VeLivePlayerPixelFormatUnknown,

    /**
     * @locale zh
     * @brief NV12 格式。
     */
    /**
     * @locale en
     * @brief NV12.
     */
    VeLivePlayerPixelFormatNV12,

    /**
     * @locale zh
     * @brief YUVI420 格式。
     */
    /**
     * @locale en
     * @brief YUVI420.
     */
    VeLivePlayerPixelFormatI420,

    /**
     * @locale zh
     * @brief BGRA 格式。
     */
    /**
     * @locale en
     * @brief BGRA.
     */
    VeLivePlayerPixelFormatBGRA32,
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频数据封装格式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The encapsulation format of the video data.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerVideoBufferType) {
    /**
     * @locale zh
     * @brief 未知格式。
     */
    /**
     * @locale en
     * @brief Unknown format.
     */
    VeLivePlayerVideoBufferTypeUnknown,

    /**
     * @locale zh
     * @brief CVPixelBufferRef 格式。
     */
    /**
     * @locale en
     * @brief CVPixelBufferRef.
     */
    VeLivePlayerVideoBufferTypePixelBuffer,

    /**
     * @locale zh
     * @brief CVSampleBufferRef 格式。
     */
    /**
     * @locale en
     * @brief CVSampleBufferRef.
     */
    VeLivePlayerVideoBufferTypeSampleBuffer,

    /**
     * @locale zh
     * @brief NSData 格式。
     */
    /**
     * @locale en
     * @brief NSData.
     */
    VeLivePlayerVideoBufferTypeNSData,
};

/**
 * @locale zh
 * @type keytype
 * @brief 音频数据封装格式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The encapsulation format of the audio.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerAudioBufferType) {
    /**
     * @locale zh
     * @brief 未知格式。
     */
    /**
     * @locale en
     * @brief Unknown format.
     */
    VeLivePlayerAudioBufferUnknown,

    /**
     * @locale zh
     * @brief CVSampleBufferRef 格式，音频数据以样本缓冲区 sample buffer 的形式进行处理和渲染。
     */
    /**
     * @locale en
     * @brief CVSampleBufferRef. The audio data is processed and rendered as sample buffers.
     */
    VeLivePlayerAudioBufferTypeSampleBuffer,

    /**
     * @locale zh
     * @brief NSData 格式，音频数据以 NSData 对象的形式进行处理和渲染。
     */
    /**
     * @locale en
     * @brief NSData. The audio data is processed and rendered as NSData objects.
     */
    VeLivePlayerAudioBufferTypeNSData,
};

/**
 * @locale zh
 * @type keytype
 * @brief 直播播放器清晰度档位变化原因。
 */
/**
 * @locale en
 * @type keytype
 * @brief The reason why the video resolution has changed.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerResolutionSwitchReason) {
    /**
     * @locale zh
     * @brief ABR 自动切档。
     */
    /**
     * @locale en
     * @brief The resolution is switched automatically through the adaptive bitrate (ABR) feature.
     */
    VeLivePlayerResolutionSwitchByAuto = 0,

    /**
     * @locale zh
     * @brief 调用 [switchResolution:](188118#TVLManager(VeLivePlayer)-switchresolution)手动切换档位。
     */
    /**
     * @locale en
     * @brief The resolution is changed after [switchResolution:](docs-player-sdk-for-ios-api#TVLManager(VeLivePlayer)-switchresolution) is called.
     */
    VeLivePlayerResolutionSwitchByManual,
};

/**
 * @locale zh
  * @type keytype
  * @brief 视频顺时针旋转角度。
  */
 /**
  * @locale en
  * @type keytype
  * @brief The clockwise video rotation angle.
  */
typedef NS_ENUM(NSInteger, VeLivePlayerRotation) {
    /**
     * @locale zh
     * @brief 关闭旋转。
     */
    /**
     * @locale en
     * @brief No rotation.
     */
    VeLivePlayerRotation0       = 0,

    /**
     * @locale zh
     * @brief 顺时针旋转 90 度。
     */
    /**
     * @locale en
     * @brief Rotate 90 degrees clockwise.
     */
    VeLivePlayerRotation90      = 90,

    /**
     * @locale zh
     * @brief 顺时针旋转 180 度。
     */
    /**
     * @locale en
     * @brief Rotate 180 degrees clockwise.
     */
    VeLivePlayerRotation180     = 180,

    /**
     * @locale zh
     * @brief 顺时针旋转 270 度。
     */
    /**
     * @locale en
     * @brief Rotate 270 degrees clockwise.
     */
    VeLivePlayerRotation270     = 270,
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频镜像。
 */
/**
 * @locale en
 * @type keytype
 * @brief The mirroring option.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerMirror) {
    /**
     * @locale zh
     * @brief 关闭镜像。
     */
    /**
     * @locale en
     * @brief No mirroring.
     */
    VeLivePlayerMirrorNone  = 0,

    /**
     * @locale zh
     * @brief 水平镜像。
     */
    /**
     * @locale en
     * @brief Horizontal mirroring.
     */
    VeLivePlayerMirrorHorizontal,

    /**
     * @locale zh
     * @brief 垂直镜像。
     */
    /**
     * @locale en
     * @brief Vertical mirroring.
     */
    VeLivePlayerMirrorVertical,
};

/**
 * @locale zh
 * @type keytype
 * @brief 直播播放器的清晰度档位。
 */
/**
 * @locale en
 * @type keytype
 * @brief The player resolution.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerResolution) {
    /**
     * @locale zh
     * @brief 原始流。
     */
    /**
     * @locale en
     * @brief Original.
     */
    VeLivePlayerResolutionOrigin = 0,
    
    /**
     * @locale zh
     * @brief UHD 超高清。
     */
    /**
     * @locale en
     * @brief Ultra high definition (UHD).
     */
    VeLivePlayerResolutionUHD,
    
    /**
     * @locale zh
     * @brief FHD 全高清
     */
    /**
     * @locale en
     * @brief Full High definition (FHD).
     */
    VeLivePlayerResolutionFHD,

    /**
     * @locale zh
     * @brief HD 高清。
     */
    /**
     * @locale en
     * @brief High definition (HD).
     */
    VeLivePlayerResolutionHD,
    
    /**
     * @locale zh
     * @brief SD 标清。
     */
    /**
     * @locale en
     * @brief Standard definition (SD).
     */
    VeLivePlayerResolutionSD,
    
    /**
     * @locale zh
     * @brief LD 低清。
     */
    /**
     * @locale en
     * @brief Low definition (LD).
     */
    VeLivePlayerResolutionLD,

    /**
     * @locale zh
     * @brief MD 审核档位
     * @hidden (iOS)
     */
   /**
    * @locale en
    * @hidden (iOS)
    */
    VeLivePlayerResolutionMD,

    /**
     * @locale zh
     * @brief 仅音频
     * @hidden (iOS)
     */
   /**
    * @locale en
    * @hidden (iOS)
    */
    VeLivePlayerResolutionAO,

    /**
     * @locale zh
     * @brief 自动档位。
     */
   /**
    * @locale en
    * @brief Auto.
    */
    VeLivePlayerResolutionAUTO,

};

/**
 * @locale zh
 * @type keytype
 * @brief 直播播放传输协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The transmission protocol.
 */
/**
 * @locale zh
 * @type keytype
 * @brief 传输协议。
 */
typedef NS_ENUM(NSInteger, VeLivePlayerProtocol) {
    /**
     * @locale zh
     * @brief TCP 协议。
     */
    /**
     * @locale en
     * @brief TCP.
     */
    VeLivePlayerProtocolTCP = 0,
    
    /**
     * @locale zh
     * @brief QUIC 协议。
     */
    /**
     * @locale en
     * @brief QUIC.
     */
    VeLivePlayerProtocolQUIC,
    
    /**
     * @locale zh
     * @brief TLS 协议。
     */
    /**
     * @locale en
     * @brief TLS.
     */
    VeLivePlayerProtocolTLS,
    
  /**
   * @locale en
   * @brief HTTP。
   */
   /**
    * @locale zh
    * @brief HTTP 协议。
    */
    VeLivePlayerProtocolHTTP2,
};

/**
 * @locale zh
 * @type keytype
 * @brief 直播播放格式。
 */
/**
 * @locale en
 * @type keytype
 * @brief The format of the live stream.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerFormat) {
    /**
     * @locale zh
     * @brief FLV 格式。
     */
    /**
     * @locale en
     * @brief FLV.
     */
    VeLivePlayerFormatFLV = 0,
    
    /**
     * @locale zh
     * @brief HLS 格式。
     */
    /**
     * @locale en
     * @brief HLS.
     */
    VeLivePlayerFormatHLS,
    
    /**
     * @locale zh
     * @brief RTM 格式。
     */
    /**
     * @locale en
     * @brief Real Time Media (RTM).
     */
    VeLivePlayerFormatRTM,
};

/**
 * @locale zh
 * @type keytype
 * @brief 直播播放流类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief The type of the live stream.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerStreamType) {
    /**
     * @locale zh
     * @brief 主路流。
     */
    /**
     * @locale en
     * @brief The primary stream.
     */
    VeLivePlayerStreamTypeMain = 0,
    
    /**
     * @locale zh
     * @brief 备路流。
     */
    /**
     * @locale en
     * @brief The backup stream.
     */
    VeLivePlayerStreamTypeBackup,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 直播播放 BMF 超分类型的枚举。
 */
/**
 * @locale en
 * @hidden
 * @type keytype
 * @brief The BMF super-resolution type.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerBMFFlexSRType) {
    /**
     * @locale zh
     * @brief 未知超分类型
     */
    /**
     * @locale en
     * @brief Unknown type.
     */
    VeLivePlayerBMFScale_Unknow = -1,
    /**
     * @locale zh
     * @brief 1.5 倍超分类型，即分辨率是原始分辨率的 1.5 倍
     */
    /**
     * @locale en
     * @brief Upscale the video resolution by 1.5 times.
     */
    VeLivePlayerBMFScale_1_5 = 0,
    /**
     * @locale zh
     * @brief 2 超分类型，即分辨率是原始分辨率的 2 倍
     */
    /**
     * @locale en
     * @brief Upscale the video resolution by 2 times.
     */
    VeLivePlayerBMFScale_2_0 = 1,
    /**
     * @locale zh
     * @brief 1.1 倍超分类型，即分辨率是原始分辨率的 1.1 倍
     */
    /**
     * @locale en
     * @brief Upscale the video resolution by 1.1 times.
     */
    VeLivePlayerBMFScale_1_1 = 2,
    /**
     * @locale zh
     * @brief 1.2 倍超分类型，即分辨率是原始分辨率的 1.2 倍
     */
    /**
     * @locale en
     * @brief Upscale the video resolution by 1.2 times.
     */
    VeLivePlayerBMFScale_1_2 = 3,
    /**
     * @locale zh
     * @brief 1.3 倍超分类型，即分辨率是原始分辨率的 1.3 倍
     */
    /**
     * @locale en
     * @brief Upscale the video resolution by 1.3 times.
     */
    VeLivePlayerBMFScale_1_3 = 4,
    /**
     * @locale zh
     * @brief 1.4 倍超分类型，即分辨率是原始分辨率的 1.4 倍
     */
    /**
     * @locale en
     * @brief Upscale the video resolution by 1.4 times.
     */
    VeLivePlayerBMFScale_1_4 = 5
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 直播播放 BMF 超分功能的错误码枚举。
 */
/**
 * @locale en
 * @hidden
 * @type keytype
 * @brief Error code for BMF super-resolution.
*/
typedef NS_ENUM(NSInteger, VeLivePlayerBMFFlexSRErrorCode) {
    /**
     * @locale zh
     * @brief 未知错误
     */
    /**
     * @locale en
     * @brief Unknown error.
     */ 
    VeLivePlayerBMFFlexSRErrorUnknow = 0,
    /**
     * @locale zh
     * @brief 不满足超分的条件
     */
    /**
     * @locale en
     * @brief BMF super-resolution is not supported.
     */
    VeLivePlayerBMFFlexSRErrorCondition,
    /**
     * @locale zh
     * @brief 不支持该超分类型
     */
    /**
     * @locale en
     * @brief Unsupported BMF super-resolution type.
     */
    VeLivePlayerBMFFlexSRErrorSRType,
    /**
     * @locale zh
     * @brief 设置了重复的超分类型
     */
    /**
     * @locale en
     * @brief Duplicate BMF super-resolution type.
     */
    VeLivePlayerBMFFlexSRErrorSRTypeSame,
    /**
     * @locale zh
     * @brief 超分处理失败（仅在播放过程中设置生效）
     */
    /**
     * @locale en
     * @brief Fails to enable BMF super-resolution.
     */
    VeLivePlayerBMFFlexSRErrorProcessFailed,
    /**
     * @locale zh
     * @brief 超分设置成功
     */
    /**
     * @locale en
     * @brief Success.
     */
    VeLivePlayerBMFFlexSRSuccess,
};

/**
 * @brief 直播特效模型类型
 */
/**
 * @locale en
 * @type keytype
 * @hidden (iOS)
 */
/**
 * @locale zh
 * @type keytype
 * @hidden (iOS)
 */
typedef NS_ENUM(NSInteger, VeLivePlayerEffectType) {
    /**
     * @locale en
     * @hidden (iOS)
     */
    /**
     * @locale zh
     * @hidden (iOS)
     * @brief 未知模型
     */
    VeLivePlayerEffectUnknown,

    /**
     * @locale en
     * @hidden (iOS)
     */
    /**
     * @locale zh
     * @hidden (iOS)
     * @brief 音量均衡三期模型
     */
    VeLivePlayerEffectAudioBalance,

    /**
     * @locale en
     * @hidden (iOS)
     */
    /**
     * @locale zh
     * @hidden (iOS)
     * @brief 音质打分
      */
    VeLivePlayerEffectAudioMetric,

};

/**
 * @type keytype
 * @brief
 */
/**
 * @locale en
 * @type keytype
 * @brief Error message for resolution level switching.
 */
/**
 * @locale zh
 * @brief 分辨率档位切换报错信息。
 * @type keytype
 */
typedef NS_ENUM(NSInteger, VeLivePlayerSupportResolutionSwitchError) {
    /**
     * 没找到对应档位
     */
  /**
   * @locale en
   * @brief The corresponding resolution gear is not found.
   */
   /**
    * @locale zh
    * @brief 没有找到对应分辨率档位。
    */
    VeLivePlayerErrorResNotFound = -1,
    /**
     * 和当前档位相同
     */
  /**
   * @locale en
   * @brief The same as the current resolution level.
   */
   /**
    * @locale zh
    * @brief 和当前分辨率档位相同。
    */
    VeLivePlayerErrorSameRes = -2,
    /**
     * 播放器状态位非 prepare 状态
     */
  /**
   * @locale en
   * @brief The player status is not in the prepare state.
   */
   /**
    * @locale zh
    * @brief 播放器状态为非 prepare 状态。
    */
    VeLivePlayerErrorStatusInvalid = -3,
    /**
     * 档位错误
     */
  /**
   * @locale en
   * @brief Resolution level error.
   */
   /**
    * @locale zh
    * @brief 分辨率档位错误。
    */
    VeLivePlayerErrorInvalidRes = -4,
    /**
     * 配置不支持
     */
  /**
   * @locale en
   * @brief Configuration not supported.
   */
   /**
    * @locale zh
    * @brief 配置不支持。
    */
    VeLivePlayerErrorConfigNotSupport = -5,
    /**
     * 格式不支持
     */
  /**
   * @locale en
   * @brief Format not supported.
   */
   /**
    * @locale zh
    * @brief 格式不支持。
    */
    VeLivePlayerErrorFormatNotSupport = -6,
};
