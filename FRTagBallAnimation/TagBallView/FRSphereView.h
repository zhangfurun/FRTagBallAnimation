//
//  FRSphereView.h
//  FRTagBallAnimation
//
//  Created by 张福润 on 16/7/28.
//  Copyright © 2016年 张福润. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FRSphereView : UIView

@property(nonatomic,assign) BOOL isTimerStart;

- (void)setItems:(NSArray *)items;

- (void)timerStart;

- (void)timerStop;


@end
