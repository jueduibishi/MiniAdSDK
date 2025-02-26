//
//  TableVC.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2025/2/18.
//

#import <UIKit/UIKit.h>
#import "TestID.h"

NS_ASSUME_NONNULL_BEGIN

@interface TableVC : UITableViewController
/// 小程序初始化
+(void)miniRegister;
/// 手游初始化
+(void)mobileRegister;
/// h5初始化
+(void)h5Register;
@end

NS_ASSUME_NONNULL_END
