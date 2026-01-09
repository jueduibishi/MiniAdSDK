//
//  TableVC.m
//  AdUnionSDK
//
//  Created by 杨益凡 on 2025/2/18.
//

#import "TableVC.h"
#import "ViewController.h"
#import <MiniSDKFramework/SdkManager.h>

#define cellIdentifier @"cellIdentifier"


@interface TableVC ()
@property(nonatomic,strong)NSArray *mainArray;
@end

@implementation TableVC

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.title = @"测试";
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.mainArray = @[@"小程序广告",
                       @"手游广告",
                       @"h5广告",
                       @"以下设置，修改后需重启app",
                       [NSString stringWithFormat:@"小程序appID：%@",[TestID shareInstance].miniAppID],
                       [NSString stringWithFormat:@"小程序平台：%@",[TestID shareInstance].miniClient?@"游戏盒":@"快爆"],
                       [NSString stringWithFormat:@"小程序系统代码：%@",[TestID shareInstance].miniPlatform],
                       [NSString stringWithFormat:@"手游appID：%@",[TestID shareInstance].mobileAppID],
                       [NSString stringWithFormat:@"手游BundelID：%@",[TestID shareInstance].mobileBundleID],
                       [NSString stringWithFormat:@"手游激励视频用户ID：%@",[TestID shareInstance].mobileSlotUserID],
                       [NSString stringWithFormat:@"手游banner用户ID：%@",[TestID shareInstance].mobileBannerUserID],
                       [NSString stringWithFormat:@"手游原生(信息流)用户ID：%@",[TestID shareInstance].mobileNativeUserID],
                       [NSString stringWithFormat:@"H5appID：%@",[TestID shareInstance].h5AppID],
                       [NSString stringWithFormat:@"H5广告位ID：%@",[TestID shareInstance].h5PostID]];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:cellIdentifier];
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.mainArray.count;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];
    cell.textLabel.text = self.mainArray[indexPath.row];
    if ([cell.textLabel.text isEqualToString:@"以下设置，修改后需重启app"]) {
        cell.textLabel.textColor = [UIColor redColor];
    }
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (indexPath.row<3) {
        ViewController *vc = [[ViewController alloc]init];
        vc.title = self.mainArray[indexPath.row];
        vc.type = indexPath.row;
        vc.hidesBottomBarWhenPushed = YES;
        [self.navigationController pushViewController:vc animated:YES];
    }else{
        if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]]) {
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString] options:@{
                UIApplicationOpenURLOptionUniversalLinksOnly: @NO
            } completionHandler:nil];
        }
    }
}
#pragma mark -
#pragma mark -初始化

/// 小程序初始化
+(void)miniRegister{

    NSString *platformid = [TestID shareInstance].miniPlatform;
    NSString *gameid = [TestID shareInstance].miniAppID;
    clientType type = [TestID shareInstance].miniClient?client_youxihe:client_kuaibao;
    
    [SdkManager initType:type gameID:gameid platformID:platformid personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
        NSString *title;
        if (success) {
            title = @"小程序广告初始化成功";
        }else{
            title = [NSString stringWithFormat:@"来自小程序初始化：%@",errorString];
        }
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            dispatch_async(dispatch_get_main_queue(), ^{
                [TestID shareInstance].tishText=title;
                NSLog(@"%@",title);
            });
        });
    }];
}

/// 手游初始化
+(void)mobileRegister{
    NSString *appid =[TestID shareInstance].mobileAppID;
    NSString *bundleid = [TestID shareInstance].mobileBundleID;
    [SdkManager initMobileID:appid bundleID:bundleid personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
        NSString *title;
        if (success) {
            title = @"手游广告初始化成功";
        }else{
            title = [NSString stringWithFormat:@"来自手游初始化：%@",errorString];
        }
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            dispatch_async(dispatch_get_main_queue(), ^{
                [TestID shareInstance].tishText=title;
                NSLog(@"%@",title);
            });
        });
    }];
}
/// h5初始化
+(void)h5Register{
    [SdkManager initH5ID:[TestID shareInstance].h5AppID personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
        NSString *title;
        if (success) {
            title = @"h5广告初始化成功";
        }else{
            title = [NSString stringWithFormat:@"来自h5初始化：：%@",errorString];
        }
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            dispatch_async(dispatch_get_main_queue(), ^{
                [TestID shareInstance].tishText=title;
                NSLog(@"%@",title);
            });
        });
    }];
}

@end
