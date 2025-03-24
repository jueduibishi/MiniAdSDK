//
//  MobileNativeModel.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2025/3/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 手游信息流渠道专用-返回渲染的view size
@interface MobileNativeModel : NSObject
@property(nonatomic,assign)CGSize adSize;//手游信息流渠道专用-返回渲染的view size
@property (nonatomic, copy) NSString *adViewID;

@end

NS_ASSUME_NONNULL_END
