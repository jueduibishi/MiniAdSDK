//
//  ViewController.h
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/28.
//

#import <UIKit/UIKit.h>

#define clientKey @"clientkey"
#define gameidKey @"gameidkey"
#define gameplatformKey @"gameplatformKey"

typedef NS_ENUM(NSInteger,adType){
    adType_mini=0,//小程序
    adType_mobile,//手游
    adType_h5,//h5
};

@interface ViewController : UIViewController
@property(nonatomic,assign)adType type;

+(id)userDefaultsObjectByKey:(NSString*)key;

+(void)setUserDefaults:(id)object forKey:(NSString*)key;

@end

