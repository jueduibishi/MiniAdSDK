//
//  BaseNavigationController.m
//  NurserySong
//
//  Created by YYF on 15/5/12.
//  Copyright (c) 2015年 YYF. All rights reserved.
//

#import "BaseNavigationController.h"

@interface BaseNavigationController ()

@end

@implementation BaseNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.modalPresentationStyle=UIModalPresentationFullScreen;
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//处理leftbaritem和右滑手势冲突 大坑！！
//return YES :手势有效, NO :手势无效
//- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer {
//    
//    NSInteger num = self.viewControllers.count;
//    if (num >= 2) {
//        NSString *temp = NSStringFromClass([self.viewControllers.lastObject class]);
//        // 禁止侧滑返回
//        if ([temp isEqualToString:@"KBIDCertifyVC"] ||
//            [temp isEqualToString:@"BindingPhoneVC"] || [temp isEqualToString:@"PostTipVC"] || [temp isEqualToString:@"ReplyPostTipVC"] || [temp isEqualToString:@"VideoPostTipVC"]) {
//            return NO;
//        }
//    }
//    return self.childViewControllers.count>1;
//}

#pragma mark -
#pragma mark -竖屏
-(UIInterfaceOrientationMask)supportedInterfaceOrientations{
    return [self.topViewController supportedInterfaceOrientations];
}

- (BOOL)shouldAutorotate
{
    return [self.topViewController shouldAutorotate];
}

-(UIInterfaceOrientation)preferredInterfaceOrientationForPresentation
{
    return [self.topViewController preferredInterfaceOrientationForPresentation];
}

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated {

    if(self.viewControllers.count >= 1)
    {
        viewController.hidesBottomBarWhenPushed = YES;
    }

    [super pushViewController:viewController animated:animated];
}

-(void)dealloc{
    
}

@end
