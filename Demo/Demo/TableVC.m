//
//  TableVC.m
//  AdUnionSDK
//
//  Created by 杨益凡 on 2025/2/18.
//

#import "TableVC.h"
#import "ViewController.h"

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
    self.mainArray = @[@"小程序广告",@"手游广告",@"h5广告"];
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
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];

    ViewController *vc = [[ViewController alloc]init];
    vc.title = self.mainArray[indexPath.row];
    vc.type = indexPath.row;
    vc.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:vc animated:YES];
}

@end
