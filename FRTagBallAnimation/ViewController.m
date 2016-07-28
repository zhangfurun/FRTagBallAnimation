//
//  ViewController.m
//  FRTagBallAnimation
//
//  Created by 张福润 on 16/7/27.
//  Copyright © 2016年 张福润. All rights reserved.
//

#import "ViewController.h"

#import "FRSphereView.h"

@interface ViewController ()
{
    NSUInteger tagNumber; //显示标签的个数
}

@property (nonatomic,strong) FRSphereView *sphereView; // 球型标签View
@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    tagNumber = 40;
    self.view.backgroundColor = [UIColor whiteColor];
    
    NSMutableArray *array = [NSMutableArray array];
    for (NSInteger i = 0; i < tagNumber; i ++) {
        UIButton *btn = [UIButton buttonWithType:UIButtonTypeSystem];
        [btn setTitle:[NSString stringWithFormat:@"%ld", i] forState:UIControlStateNormal];
        btn.backgroundColor = [UIColor colorWithRed:arc4random_uniform(255)/255. green:arc4random_uniform(255)/255. blue:arc4random_uniform(255)/255. alpha:1.];
        [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        btn.titleLabel.font = [UIFont systemFontOfSize:24.];
        btn.frame = CGRectMake(0, 0, 60, 30);
        btn.layer.cornerRadius = 3;
        btn.clipsToBounds = YES;
        [btn addTarget:self action:@selector(buttonPressed:) forControlEvents:UIControlEventTouchUpInside];
        [array addObject:btn];
        [self.sphereView addSubview:btn];
    }
    [self.sphereView setItems:array];
    [self.view addSubview:self.sphereView];
    
}

#pragma mark - Method
- (FRSphereView *)sphereView {
    if (!_sphereView) {
        CGFloat sphereViewW = self.view.frame.size.width - 30 * 2;
        CGFloat sphereViewH = sphereViewW;
        _sphereView = [[FRSphereView alloc] initWithFrame:CGRectMake(30, 100, sphereViewW, sphereViewH)];
    }
    return _sphereView;
}

#pragma mark
- (void)buttonPressed:(UIButton *)btn
{
    [self.sphereView timerStop];
    
    [UIView animateWithDuration:0.3 animations:^{
        btn.transform = CGAffineTransformMakeScale(2., 2.);
    } completion:^(BOOL finished) {
        [UIView animateWithDuration:0.3 animations:^{
            btn.transform = CGAffineTransformMakeScale(1., 1.);
        } completion:^(BOOL finished) {
            [self.sphereView timerStart];
        }];
    }];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
