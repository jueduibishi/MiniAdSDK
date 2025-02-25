//
//  ViewController.m
//  AdUnionSDK
//
//  Created by 杨益凡 on 2024/8/28.
//

#import "ViewController.h"
#import <MiniSDKFramework/SdkManager.h>
#import "AppDelegate.h"

#define screenViewTag 400
#define gameidViewTag 401
#define clientViewTag 402
#define bannerAdViewtag 403
#define kuaibaoTag 404

#define WeakObj(obj) __weak typeof(obj) obj##Weak = obj;
#define StrongObj(obj) __strong typeof(obj) obj = obj##Weak;


@interface ViewController (){
    UILabel *blockLabel1;
    UILabel *blockLabel2;
    UILabel *blockLabel3;
    
    UIView *nativView1;
    UIView *nativView2;
    
    NSArray *nativArray;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    [self testMini];
    [self testMobile];
    
    UILabel *oneLabel = [self createLabel:@"打开横屏，关闭竖屏，即时生效，不用重启" withFontSize:16];
    oneLabel.frame = CGRectMake(20, 350, 500, 30);
    oneLabel.userInteractionEnabled = YES;
    oneLabel.textColor=[UIColor blueColor];
    oneLabel.tag = bannerAdViewtag;
    [self.view addSubview:oneLabel];
    
    UISwitch *mySwitch = [[UISwitch alloc]initWithFrame:CGRectMake(350, 350, 70, 30)];
    mySwitch.on = NO;
    mySwitch.tag = screenViewTag;
    [self.view addSubview:mySwitch];
    
    
    //-------------------------------------------------
    
    UIButton *loadButton1 = [self createButton:@"加载广告" Target:self Sel:@selector(buttonClick:) font:12 tag:100];
    loadButton1.frame = CGRectMake(20, 450, 100, 50);
    
    [self.view addSubview:loadButton1];
    
    
    //-------------------------------------------------
    
    UIButton *slotButton = [self createButton:@"激励广告" Target:self Sel:@selector(buttonClick:) font:12 tag:110];
    slotButton.frame = CGRectMake(20, 550, 100, 50);
    
    [self.view addSubview:slotButton];
    
    
    
    //-------------------------------------------------
    blockLabel1 = [self createLabel:@"" withFontSize:12];
    blockLabel1.frame = CGRectMake(20, 620, 100, 60);
    blockLabel1.textColor=[UIColor blackColor];
    
    
    
    [self.view addSubview:blockLabel1];
    
    UIButton *changeButton = [self createButton:@"切换接口" Target:self Sel:@selector(changeServer) font:12 tag:112];
    changeButton.frame = CGRectMake(self.view.frame.size.width/2.0-50, self.view.frame.size.height-84, 100, 50);
    
    [self.view addSubview:changeButton];
}
-(void)testMini{
    if (self.type == adType_mini) {
        UILabel *tishLabel = [self createLabel:@"以下初始化设置，需要保存后重启app生效" withFontSize:16];
        tishLabel.frame = CGRectMake(20, 90, 500, 30);
        [self.view addSubview:tishLabel];
        
        UILabel *screenlabel = [self createLabel:@"竖屏id700315 横屏id 700319" withFontSize:16];
        screenlabel.textColor=[UIColor blueColor];
        screenlabel.userInteractionEnabled = YES;
        screenlabel.frame = CGRectMake(20, 150, 220, 30);
        [self.view addSubview:screenlabel];
        
        UITextField *gameField = [self createTextFieldWithFrame:CGRectMake(240, 150, 150, 30) superView:self.view backgroundColor:[UIColor clearColor] fontSize:16 textColor:[UIColor blackColor]];

        gameField.text = [ViewController userDefaultsObjectByKey:gameidKey];
        gameField.placeholder =@"请输入游戏id";
        gameField.tag = gameidViewTag;
        gameField.layer.borderWidth=1.0;
        gameField.layer.borderColor=[UIColor grayColor].CGColor;
        gameField.layer.cornerRadius =8.0;
        

        UILabel *clientlabel = [self createLabel:@"平台ID 1025、1028等" withFontSize:16];
        clientlabel.textColor=[UIColor blueColor];
        clientlabel.frame = CGRectMake(20, 200, 200, 30);
        [self.view addSubview:clientlabel];
        
        UITextField *clientField = [self createTextFieldWithFrame:CGRectMake(240, 200, 150, 30) superView:self.view backgroundColor:[UIColor clearColor] fontSize:16 textColor:[UIColor blackColor]];
        clientField.text = [ViewController userDefaultsObjectByKey:clientKey];
        clientField.placeholder =@"请输入平台ID";
        clientField.tag = clientViewTag;
        clientField.layer.borderWidth=1.0;
        clientField.layer.borderColor=[UIColor grayColor].CGColor;
        clientField.layer.cornerRadius =8.0;
        
        //-------------------------------------------------
        
        UIButton *saveButton = [self createButton:@"保存设置" Target:self Sel:@selector(buttonClick:) font:12 tag:99];
        saveButton.frame = CGRectMake(100, 260, 100, 50);
        [self.view addSubview:saveButton];
        
        //-------------------------------------------------

        UILabel *platformLabel = [self createLabel:@"开关打开为快爆，关闭为游戏盒，需要重启" withFontSize:16];
        platformLabel.frame = CGRectMake(20, 400, 500, 30);
        platformLabel.userInteractionEnabled = YES;
        platformLabel.textColor=[UIColor blueColor];
        [self.view addSubview:platformLabel];
        
        UISwitch *platformSwitch = [[UISwitch alloc]initWithFrame:CGRectMake(350, 400, 70, 30)];
        NSString *gamePlatform = [[NSUserDefaults standardUserDefaults] objectForKey:gameplatformKey];
        if (gamePlatform.integerValue == 0) {
            platformSwitch.on = NO;
        }else{
            platformSwitch.on = YES;
        }
        [platformSwitch addTarget:self action:@selector(switchValueChanged:) forControlEvents:UIControlEventValueChanged];
        [self.view addSubview:platformSwitch];
        
        //-------------------------------------------------
        UIButton *loadButton2 = [self createButton:@"加载广告" Target:self Sel:@selector(buttonClick:) font:12 tag:101];
        loadButton2.frame = CGRectMake(140, 450, 100, 50);
        
        [self.view addSubview:loadButton2];
        
        UIButton *loadButton3 = [self createButton:@"加载广告" Target:self Sel:@selector(buttonClick:) font:12 tag:102];
        loadButton3.frame = CGRectMake(260, 450, 100, 50);
        
        [self.view addSubview:loadButton3];
        
        UIButton *bannerButton = [self createButton:@"banner广告" Target:self Sel:@selector(buttonClick:) font:12 tag:111];
        bannerButton.frame = CGRectMake(140, 550, 100, 50);
        
        [self.view addSubview:bannerButton];
        
        UIButton *fullButton = [self createButton:@"插屏广告" Target:self Sel:@selector(buttonClick:) font:12 tag:112];
        fullButton.frame = CGRectMake(260, 550, 100, 50);
        
        [self.view addSubview:fullButton];
        
        //-------------------------------------------------

        
        blockLabel2 = [self createLabel:@"" withFontSize:12];
        blockLabel2.frame = CGRectMake(140, 620, 100, 60);
        blockLabel2.textColor=[UIColor blackColor];
        
        blockLabel3 = [self createLabel:@"" withFontSize:12];
        blockLabel3.frame = CGRectMake(260, 620, 100, 60);
        blockLabel3.textColor=[UIColor blackColor];
        
        [self.view addSubview:blockLabel2];
        [self.view addSubview:blockLabel3];
    }
}
-(void)testMobile{
    if (self.type == adType_mobile) {
        
        nativView1 = [[UIView alloc]initWithFrame:CGRectMake(20, 90, 300, 50)];
        nativView2 = [[UIView alloc]initWithFrame:CGRectMake(20, 670, 300, 50)];
        [self.view addSubview:nativView1];
        [self.view addSubview:nativView2];
        //-------------------------------------------------

        UIButton *loadButton2 = [self createButton:@"加载广告" Target:self Sel:@selector(buttonClick:) font:12 tag:101];
        loadButton2.frame = CGRectMake(140, 450, 100, 50);
        
        [self.view addSubview:loadButton2];
        
        UIButton *loadButton3 = [self createButton:@"加载广告" Target:self Sel:@selector(buttonClick:) font:12 tag:102];
        loadButton3.frame = CGRectMake(260, 450, 100, 50);
        
        [self.view addSubview:loadButton3];
        
        UIButton *bannerButton = [self createButton:@"banner广告" Target:self Sel:@selector(buttonClick:) font:12 tag:111];
        bannerButton.frame = CGRectMake(140, 550, 100, 50);
        
        [self.view addSubview:bannerButton];
        
        UIButton *fullButton = [self createButton:@"信息流广告" Target:self Sel:@selector(buttonClick:) font:12 tag:112];
        fullButton.frame = CGRectMake(260, 550, 100, 50);
        
        [self.view addSubview:fullButton];
        
        //-------------------------------------------------

        
        blockLabel2 = [self createLabel:@"" withFontSize:12];
        blockLabel2.frame = CGRectMake(140, 620, 100, 60);
        blockLabel2.textColor=[UIColor blackColor];
        
        blockLabel3 = [self createLabel:@"" withFontSize:12];
        blockLabel3.frame = CGRectMake(260, 620, 100, 60);
        blockLabel3.textColor=[UIColor blackColor];
        
        [self.view addSubview:blockLabel2];
        [self.view addSubview:blockLabel3];
    }
}
#pragma mark -
#pragma mark -h5激励视频 一次性点击展示(无预加载)
/// h5激励视频 一次性点击展示
-(void)h5SlotOnceShow{
    [SdkManager initH5ID:TestH5AppID personalAD:YES Complete:^(BOOL success, NSString * _Nullable errorString) {
        H5SlotManager *manager = [H5SlotManager shareInstance];
        WeakObj(manager)
        manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel1.text=result;
            StrongObj(manager)
            if (code == slotLoadSuccessCode) {
                [manager showAd:self];
            }
        };
        UISwitch *myswitch = [self.view viewWithTag:screenViewTag];
        [manager loadRewardADWithPost:TestH5PostID horizontal:myswitch.isOn];
        
    }];
}
#pragma mark -
#pragma mark -点击
-(void)buttonClick:(UIButton*)sender{
    NSInteger tag = sender.tag;
    if (tag == 99) {
        UITextField *clientField = [self.view viewWithTag:clientViewTag];
        if (clientField.text!=nil || clientField.text.length>0) {
            [ViewController setUserDefaults:clientField.text forKey:clientKey];
        }else{
            [ViewController setUserDefaults:@"1025" forKey:clientKey];
        }
        UITextField *gameField = [self.view viewWithTag:gameidViewTag];
        if (gameField.text!=nil || gameField.text.length>0) {
            [ViewController setUserDefaults:gameField.text forKey:gameidKey];
        }else{
            [ViewController setUserDefaults:@"700315" forKey:gameidKey];
        }
        UIButton *button =[self.view viewWithTag:99];
        [button setTitle:@"重启生效" forState:UIControlStateNormal];
    }
    if (tag == 100) {
        [self slotLoad];
    }
    if (tag == 110) {
        [self slotShow];
    }
    if (tag == 101) {
        [self bannerLoad];
        
    }
    if (tag == 111) {
        [self bannerShow];
    }
    if (tag == 102) {
        [self screenLoad];
        
    }
    if (tag == 112) {
        
        [self screenShow];
    }
}
#pragma mark -激励
-(void)slotLoad{
    
    if (self.type == adType_mini) {
        MiniSlotManager *manager = [MiniSlotManager shareInstance];
        manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel1.text=result;
        };
        UISwitch *myswitch = [self.view viewWithTag:screenViewTag];
        [manager loadRewardAD:myswitch.isOn];
    }else if (self.type == adType_mobile){

        MobileSlotManager *manager = [MobileSlotManager shareInstance];
        manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel1.text=result;
        };
        UISwitch *myswitch = [self.view viewWithTag:screenViewTag];
        [manager loadRewardADWithUserID:TestMobileSlotUserID horizontal:myswitch.isOn];
    }else if (self.type == adType_h5){
        H5SlotManager *manager = [H5SlotManager shareInstance];
        manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel1.text=result;
        };
        UISwitch *myswitch = [self.view viewWithTag:screenViewTag];
        [manager loadRewardADWithPost:TestH5PostID horizontal:myswitch.isOn];
    }
}
-(void)slotShow{
    if (self.type == adType_mini) {
        MiniSlotManager *manager = [MiniSlotManager shareInstance];
        manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel1.text=result;
        };
        if (manager.isReadToPlay) {
            
            [manager showAd:self];
        }
        else{
            self->blockLabel1.text=@"激励广告加载未完成";
        }
    }else if (self.type == adType_mobile){
        MobileSlotManager *manager = [MobileSlotManager shareInstance];
        manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel1.text=result;
        };
        if (manager.isReadToPlay) {
            [manager showAd:self];
        }
        else{
            self->blockLabel1.text=@"激励广告加载未完成";
        }
    }else if (self.type == adType_h5){
        
        //[self h5SlotOnceShow];
        H5SlotManager *manager = [H5SlotManager shareInstance];
        manager.didRewardBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel1.text=result;
        };
        if (manager.isReadToPlay) {
            [manager showAd:self];
        }
        else{
            self->blockLabel1.text=@"激励广告加载未完成";
        }
    }
}
#pragma mark -
#pragma mark -banner
-(void)bannerLoad{
    if (self.type == adType_mini) {
        MiniBannerManager *manager = [MiniBannerManager shareInstance];
        manager.bannerBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel2.text=result;
        };
        UILabel *label = [self.view viewWithTag:bannerAdViewtag];
        [manager loadBannerAD:self showView:label size:CGSizeMake(320, 50)];
    }else if (self.type == adType_mobile){
        MobileBannerManager *manager = [MobileBannerManager shareInstance];
        manager.bannerBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel2.text=result;
        };
        UILabel *label = [self.view viewWithTag:bannerAdViewtag];
        [manager loadBannerAD:self userID:TestMobileBannerUserID showView:label size:CGSizeMake(320, 50)];
    }
}

-(void)bannerShow{
    if (self.type == adType_mini) {
        MiniBannerManager *manager = [MiniBannerManager shareInstance];
        if (manager.isReadToPlay) {
            [manager showAd];
        }else{
            self->blockLabel2.text=@"banner广告加载未完成";
        }
    }else if (self.type == adType_mobile){
        MobileBannerManager *manager = [MobileBannerManager shareInstance];
        if (manager.isReadToPlay) {
            [manager showAd];
        }else{
            self->blockLabel2.text=@"banner广告加载未完成";
        }
    }
}
#pragma mark -
#pragma mark - 插屏广告 & 原生(信息流)
-(void)screenLoad{
    if (self.type == adType_mini) {
        MiniScreenManager *manager = [MiniScreenManager shareInstance];
        manager.screenBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel3.text=result;
        };
        [manager loadScreenAD];
    }else if (self.type == adType_mobile){
        MobileNativManager *manager = [MobileNativManager shareInstance];
        manager.nativeBlock = ^(int code, NSString * _Nonnull result) {
            NSLog(@"%d,%@",code, result);
            self->blockLabel3.text=result;
        };
        [manager loadNativAD:self userID:TestMobileNativeUserID size:CGSizeMake(320, 50) loadMax:2];
        manager.showAdBlock = ^(NSArray<UIView *> * _Nullable adModelArray) {
            if (adModelArray) {
                [self->nativView1 addSubview:adModelArray.firstObject];
                //...
                //...
                //代码示例，循环和其他逻辑略
                //XXmodel *model = [[XXmodel alloc]init];
                //model.adView = adModelArray.firstObject;
                //[self.dataSource insertObject:model atIndex:index];
                //[self.tableView reloadData];
                
            }
        };
    }else if (self.type == adType_h5){
        
    }
}
-(void)screenShow{
    if (self.type == adType_mini) {
        MiniScreenManager *manager = [MiniScreenManager shareInstance];
        if (manager.isReadToPlay) {
            [manager showAd:self];
        }else{
            self->blockLabel3.text=@"插屏广告加载未完成";
        }
    }else if (self.type == adType_mobile){
        NSLog(@"信息流一般不做预加载，获取到素材后直接刷新页面");
    }else if (self.type == adType_h5){
        
    }
}

#pragma mark -
#pragma mark -开关
-(void)switchValueChanged:(UISwitch*)swith{
    BOOL isOn = swith.isOn;
    if (isOn) {
        [ViewController setUserDefaults:@"1" forKey:gameplatformKey];
    }else{
        [ViewController setUserDefaults:@"0" forKey:gameplatformKey];
    }
}
#pragma mark -
#pragma mark -fun
-(UIButton*)createButton:(NSString*)title Target:(id)t_target Sel:(SEL)t_sel  font:(NSInteger)fontsize tag:(NSInteger)t_tag
{
    
    UIButton* button = [UIButton buttonWithType:UIButtonTypeCustom];
    if (title) {
        [button setTitle:[[NSString alloc] initWithFormat:@"%@", title] forState:UIControlStateNormal];
    }
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [button setBackgroundColor:[UIColor blueColor]];
    [button setTag:t_tag];
    button.adjustsImageWhenHighlighted = NO;
    button.exclusiveTouch = YES;
    [button addTarget:t_target action:t_sel forControlEvents:UIControlEventTouchUpInside];
    return button;
}

-(UITextField *)createTextFieldWithFrame:(CGRect)frame superView:(UIView *)superview backgroundColor:(UIColor *)backgroundColor fontSize:(CGFloat)fontsize textColor:(UIColor *)textColor
{
    UITextField *textField = [[UITextField alloc]initWithFrame:frame];
    textField.backgroundColor = backgroundColor;
    textField.font = [UIFont systemFontOfSize:fontsize];
    textField.textColor = textColor;
    textField.textAlignment = NSTextAlignmentLeft;
    textField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    textField.placeholder = @"";
    textField.keyboardType = UIKeyboardTypePhonePad;
    [superview addSubview:textField];
    return textField;
}

-(UILabel*)createLabel:(NSString*)t_text withFontSize:(NSUInteger)size
{
    UILabel* label = [[UILabel alloc] init];
    if (t_text) {
        [label setText:[[NSString alloc] initWithFormat:@"%@", t_text]];
    }
    label.textColor = [UIColor blueColor];
    label.textAlignment = NSTextAlignmentLeft;
    label.font = [UIFont systemFontOfSize:size];
    label.numberOfLines = 0;
    return label;
}
+(id)userDefaultsObjectByKey:(NSString*)key
{
    return [[NSUserDefaults standardUserDefaults] objectForKey:key];
}

+(void)setUserDefaults:(id)object forKey:(NSString*)key
{
    [[NSUserDefaults standardUserDefaults] setObject:object forKey:key];
    [[NSUserDefaults standardUserDefaults] synchronize];
}
-(NSInteger)integerValue:(id)sender
{
    if (sender == nil) {
        return 0;
    }
    else if (sender == [NSNull null]) {

        return 0;
    }
    else {
        return [sender integerValue];
    }
}

-(void)changeServer{
    NSString *title = @"当前为线上接口";
    serverType type = [SdkManager serverType];
    switch (type) {
        case serverTestType:
            title = @"当前为测试接口";
            break;
        case serverOtType:
            title = @"当前为OT接口";
            break;
            
        default:
            break;
    }
    NSString *gamePlatform = [[NSUserDefaults standardUserDefaults] objectForKey:gameplatformKey];
    NSString *titleAppen = [NSString stringWithFormat:@"%@,服务器为游戏盒",title];
    if (gamePlatform.integerValue == 1) {
        titleAppen = [NSString stringWithFormat:@"%@,服务器为好游快爆",title];
    }
    UIAlertController *alertCon = [UIAlertController alertControllerWithTitle:titleAppen message:nil preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *actionOn = [UIAlertAction actionWithTitle:@"线上接口" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [SdkManager setServerType:serverOnlineType];
    }];
    UIAlertAction *actionOT = [UIAlertAction actionWithTitle:@"OT接口" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [SdkManager setServerType:serverOtType];
    }];
    UIAlertAction *actionTest = [UIAlertAction actionWithTitle:@"测试接口" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [SdkManager setServerType:serverTestType];
    }];
    UIAlertAction *actioncancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {

    }];
    [alertCon addAction:actionOn];
    [alertCon addAction:actionOT];
    [alertCon addAction:actionTest];
    [alertCon addAction:actioncancel];
    [self presentViewController:alertCon animated:YES completion:nil];
}
@end
