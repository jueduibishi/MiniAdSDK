//
//  LRViewController.h
//  Demo
//
//  Created by l on 2026/3/3.
//

#import <UIKit/UIKit.h>
#import "ViewController.h"
NS_ASSUME_NONNULL_BEGIN


/// 横屏
@interface LRViewController : UIViewController
@property(nonatomic,assign)adType type;

+(id)userDefaultsObjectByKey:(NSString*)key;

+(void)setUserDefaults:(id)object forKey:(NSString*)key;

NS_ASSUME_NONNULL_END

@end
