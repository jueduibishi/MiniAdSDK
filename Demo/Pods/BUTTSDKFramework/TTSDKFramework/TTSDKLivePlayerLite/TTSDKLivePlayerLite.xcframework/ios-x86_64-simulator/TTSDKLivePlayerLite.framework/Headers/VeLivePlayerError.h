
/**
 Copyright (c) 2023 The VeLivePlayer project authors. All Rights Reserved.
 @brief VeLivePlayerError
*/

/**
 * @locale zh
 * @type errorcode
 * @brief 直播播放错误码。
 */
/**
 * @locale en
 * @type errorcode
 * @brief The playback error code.
 */
typedef NS_ENUM(NSInteger, VeLivePlayerErrorCode) {
    /**
     * @locale zh
     * @brief 没有错误。
     */
    /**
     * @locale en
     * @brief No error.
     */
    VeLivePlayerNoError = 0,
    
    /**
     * @locale zh
     * @brief License 证书无效。可能证书集成错误或证书过期，请检查证书集成方式和有效性。
     */
    /**
     * @locale en
     * @brief The SDK license is invalid. This error may occur due to incorrect integration of the license or if the license has expired. Review how the license was integrated and ensure that it is still valid.
     */
    VeLivePlayerInvalidLicense = -1,
    
    /**
     * @locale zh
     * @brief 调用时传入的参数不合法。请检查入参，并重新调用。
     */
    /**
     * @locale en
     * @brief Invalid parameters. Check the input parameter and call the method again.
     */
    VeLivePlayerInvalidParameter = -2,
    
    /**
     * @locale zh
     * @brief 调用被拒绝。方法调用时机不合法，请检查调用时机。
     */
    /**
     * @locale en
     * @brief The method call has been rejected. This error may occur when the method is called at an incorrect time.
     */
    VeLivePlayerErrorRefused = -3,
    
    /**
     * @locale zh
     * @brief 加载库文件失败。可能是 SDK 集成错误，请检查 SDK 集成方式。
     */
    /**
     * @locale en
     * @brief Failed to load the library file. This error may occur due to incorrect integration of the SDK license.
     */
    VeLivePlayerErrorLibraryLoadFailed = -4,
    
    /**
     * @locale zh
     * @brief 播放地址不存在或无效。可能是播放地址为空、地址格式不合法或地址长度不合法，请检查播放地址。
     */
    /**
     * @locale en
     * @brief The pull stream address does not exist or is invalid. This error may occur if the pull stream address is empty, or if the format or length of the address is invalid.
     */
    VeLivePlayerErrorPlayUrl = -100,
    
    /**
     * @locale zh
     * @brief 无法获取流数据。可能是直播流不存在、直播流中断或直播已结束，请检查直播状态。
     */
    /**
     * @locale en
     * @brief Unable to get the stream data. This error may occur if the live stream does not exist, is interrupted, or has ended. Please check the status of the live stream.
     */
    VeLivePlayerErrorNoStreamData = -101,
    
    /**
     * @locale zh
     * @brief 内部播放重试。可能由于播放器内部错误触发了重试。
     */
    /**
     * @locale en
     * @brief An internal retry to play the live stream, which might happen due to an internal player error.
     */
    VeLivePlayerErrorInternalRetryStart = -102,
    
    /**
     * @locale zh
     * @brief 内部重试失败。内部重试次数达到最大限制，播放器停止重试，您可以尝试重新播放。
     */
    /**
     * @locale en
     * @brief An internal retry failed and the maximum number of internal retries is reached. The player has stopped retrying. You may attempt a manual retry.
     */
    VeLivePlayerErrorInternalRetryFailed = -103,
    
    /**
     * @locale zh
     * @brief DNS 解析失败。可能是播放地址异常或客户端网络异常，请您检查播放地址和网络情况，如果故障未排除，请[创建工单](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)联系技术支持。
     */
    /**
     * @locale en
     * @brief DNS parsing failed. This error may occur due to an error in the pull stream address or the client's network conditions. If the error persists after you verify the pull stream address and network conditions, [create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for assistance.
     */
    VeLivePlayerErrorDnsParseFailed = -200,
    
    /**
     * @locale zh
     * @brief 网络请求失败。请检查网络情况，如果故障未排除，请[创建工单](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)联系技术支持。
     */
    /**
     * @locale en
     * @brief The network request failed. Check the network conditions. If the error persists, [create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for assistance.
     */
    VeLivePlayerErrorNetworkRequestFailed = -201,
    
    /**
     * @locale zh
     * @brief 直播格式解封装失败。可能是使用了不支持的直播流格式和协议，或音视频流错误；请检查流格式，如果故障未排除，请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief Video decapsulation failed. This error may occur if the live stream uses an unsupported format or protocol, or if there is an audio or video error. If the error persists, [create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for assistance.
     */
    VeLivePlayerErrorDemuxFailed = -300,
    
    /**
     * @locale zh
     * @brief 视频解码失败。可能使用了不支持的直播流音视频格式，或解码器出错；请检查音视频格式，如果故障未排除，请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief Decoding failed. This error may occur if the live stream uses an unsupported audio or video format. If the error persists, [create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for assistance.
     */
    VeLivePlayerErrorDecodeFailed = -301,
    
    /**
     * @locale zh
     * @brief 渲染失败。可能是音视频输出设备异常，请重试；如果故障未排除，请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief Rendering failed. This error may occur if there is an issue with the audio or video output devices. If the error persists, [create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for assistance.
     */
    VeLivePlayerErrorAVOutputFailed = -302,
    
    /**
     * @locale zh
     * @brief 该台设备不在超分机型白名单内，不支持超分功能。如您需要帮助，请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief The device model does not support super resolution. [Create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for any assistance you may need.
     */
    VeLivePlayerErrorSRDeviceUnsupported = -303,
    
    /**
     * @locale zh
     * @brief 当前分辨率高于超分的最大分辨率限制。如您需要帮助，请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief The current resolution exceeds the upper limit allowed for super resolution. [Create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for any assistance you may need.
     */
    VeLivePlayerErrorSRResolutionUnsupported = -304,
    
    /**
     * @locale zh
     * @brief 当前帧率高于超分的最大帧率限制。如您需要帮助，请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief The current frame rate exceeds the upper limit allowed for super resolution. [Create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for any assistance you may need.
     */
    VeLivePlayerErrorSRFpsUnsupported = -305,
    
    /**
     * @locale zh
     * @brief 超分初始化失败。请检查超分参数配置正确性和版本兼容性，如果故障未排除，请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief Fails to initialize super resolution. [Create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support if the error persists.
     */
    VeLivePlayerErrorSRInitFail = -306,
    
    /**
     * @locale zh
     * @brief 超分执行失败。请检查超分参数配置正确性和版本兼容性，如果故障未排除，请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief Fails to apply super resolution to the video. [Create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support if the error persists.
     */
    VeLivePlayerErrorSRExecuteFail = -307,
    
    /**
     * @locale zh
     * @brief 您使用的基础版 License 暂不支持 H.265 硬件解码，请登录火山引擎[视频直播控制台](https://console.volcengine.com/live/main/sdk)获取高级版 License。
     */
    /**
     * @locale en
     * @brief The SDK license does not provide support for the H.265 feature.
     */
    VeLivePlayerLicenseUnsupportedH265 = -308,
    
    /** 
     * @locale zh
     * @brief 播放器不支持清晰度的切换。
     */
   /**
    * @locale en
    * @brief The player does not support switching of definition.
    */
    VeLivePlayerErrorNotSupportResolutionSwitch = -310,

    /**
     * @locale zh
     * @brief DRM 鉴权失败。
     */
    /**
     * @locale en
     * @brief DRM authentication fails
     */
    VeLivePlayerDRMFetchCKCFailed = -400,
    
    /**
     * @locale zh
     * @brief 服务器播放上下文（SPC）生成失败。
     */
    /**
     * @locale en
     * @brief Fails to generate Server Playback Context (SPC)
     */
    VeLivePlayerDRMFetchSPCFailed = -401,
    
    /**
     * @locale zh
     * @brief 内部错误。请联系火山引擎[技术支持](https://console.volcengine.com/workorder/create?step=2&SubProductID=P00000076)。
     */
    /**
     * @locale en
     * @brief Internal error. [Create a ticket](https://console.byteplus.com/workorder/create?step=2&SubProductID=P00000980) to contact BytePlus technical support for assistance.
     */
    VeLivePlayerErrorInternal = -999,
    
};

/**
 * @locale zh
 * @type errorcode
 * @brief 直播播放错误。
 */
/**
 * @locale en
 * @type errorcode
 * @brief The playback error.
 */
@interface VeLivePlayerError : NSError

/**
 * @locale zh
 * @brief 直播播放错误码。
 */
/**
 * @locale en
 * @brief The error code.
 */
@property (nonatomic, readonly) NSInteger errorCode;

/**
 * @locale zh
 * @brief 直播播放错误信息。
 */
/**
 * @locale en
 * @brief The error message.
 */
@property (nonatomic, readonly, nullable) NSString* errorMsg;

@end
