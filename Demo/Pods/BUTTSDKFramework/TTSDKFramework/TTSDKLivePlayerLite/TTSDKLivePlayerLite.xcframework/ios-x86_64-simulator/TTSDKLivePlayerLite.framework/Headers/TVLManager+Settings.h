//
//  TVLManager+Settings.h
//  TTVideoLive
//
//  Created by chenzhaojie on 2019/5/13.
//

#import "TVLManager.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Properties of settings have a higher priority, and will configure player with given configuration before play performed when shouldIgnoreSettings set to NO.
 */
@interface TVLManager (Settings)

/**
 Ignore settings or not. Default is NO.
 */
@property (nonatomic, assign) BOOL shouldIgnoreSettings;

@property (nonatomic, assign, readonly) BOOL allowsReceivePacketCallback;

@property (nonatomic, assign, readonly) BOOL allowsRenderFrameCallback;

- (void)configPlayerWithSettings;

@end

NS_ASSUME_NONNULL_END
