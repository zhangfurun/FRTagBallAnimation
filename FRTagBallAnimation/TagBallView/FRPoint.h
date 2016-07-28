//
//  FRPoint.h
//  FRTagBallAnimation
//
//  Created by 张福润 on 16/7/28.
//  Copyright © 2016年 张福润. All rights reserved.
//

#ifndef FRPoint_h
#define FRPoint_h

struct FRPoint {
    CGFloat x;
    CGFloat y;
    CGFloat z;
};

typedef struct FRPoint FRPoint;


FRPoint FRPointMake(CGFloat x, CGFloat y, CGFloat z) {
    FRPoint point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}


#endif /* FRPoint_h */
