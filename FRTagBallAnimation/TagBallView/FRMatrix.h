//
//  FRMatrix.h
//  FRTagBallAnimation
//
//  Created by 张福润 on 16/7/28.
//  Copyright © 2016年 张福润. All rights reserved.
//

#ifndef FRMatrix_h
#define FRMatrix_h

#import "FRPoint.h"

struct FRMatrix {
    NSInteger column;
    NSInteger row;
    CGFloat matrix[4][4];
};

typedef struct FRMatrix FRMatrix;

static FRMatrix FRMatrixMake(NSInteger column, NSInteger row) {
    FRMatrix matrix;
    matrix.column = column;
    matrix.row = row;
    for(NSInteger i = 0; i < column; i++){
        for(NSInteger j = 0; j < row; j++){
            matrix.matrix[i][j] = 0;
        }
    }
    
    return matrix;
}

static FRMatrix FRMatrixMakeFromArray(NSInteger column, NSInteger row, CGFloat *data) {
    FRMatrix matrix = FRMatrixMake(column, row);
    for (int i = 0; i < column; i ++) {
        CGFloat *t = data + (i * row);
        for (int j = 0; j < row; j++) {
            matrix.matrix[i][j] = *(t + j);
        }
    }
    return matrix;
}

static FRMatrix FRMatrixMutiply(FRMatrix a, FRMatrix b) {
    FRMatrix result = FRMatrixMake(a.column, b.row);
    for(NSInteger i = 0; i < a.column; i ++){
        for(NSInteger j = 0; j < b.row; j ++){
            for(NSInteger k = 0; k < a.row; k++){
                result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
            }
        }
    }
    return result;
}

static FRPoint FRPointMakeRotation(FRPoint point, FRPoint direction, CGFloat angle) {
    //    CGFloat temp1[4] = {direction.x, direction.y, direction.z, 1};
    //    FRMatrix directionM = FRMatrixMakeFromArray(1, 4, temp1);
    if (angle == 0) {
        return point;
    }
    
    CGFloat temp2[1][4] = {point.x, point.y, point.z, 1};
    //    FRMatrix pointM = FRMatrixMakeFromArray(1, 4, *temp2);
    
    FRMatrix result = FRMatrixMakeFromArray(1, 4, *temp2);
    
    if (direction.z * direction.z + direction.y * direction.y != 0) {
        CGFloat cos1 = direction.z / sqrt(direction.z * direction.z + direction.y * direction.y);
        CGFloat sin1 = direction.y / sqrt(direction.z * direction.z + direction.y * direction.y);
        CGFloat t1[4][4] = {{1, 0, 0, 0}, {0, cos1, sin1, 0}, {0, -sin1, cos1, 0}, {0, 0, 0, 1}};
        FRMatrix m1 = FRMatrixMakeFromArray(4, 4, *t1);
        result = FRMatrixMutiply(result, m1);
    }
    
    if (direction.x * direction.x + direction.y * direction.y + direction.z * direction.z != 0) {
        CGFloat cos2 = sqrt(direction.y * direction.y + direction.z * direction.z) / sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        CGFloat sin2 = -direction.x / sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        CGFloat t2[4][4] = {{cos2, 0, -sin2, 0}, {0, 1, 0, 0}, {sin2, 0, cos2, 0}, {0, 0, 0, 1}};
        FRMatrix m2 = FRMatrixMakeFromArray(4, 4, *t2);
        result = FRMatrixMutiply(result, m2);
    }
    
    CGFloat cos3 = cos(angle);
    CGFloat sin3 = sin(angle);
    CGFloat t3[4][4] = {{cos3, sin3, 0, 0}, {-sin3, cos3, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    FRMatrix m3 = FRMatrixMakeFromArray(4, 4, *t3);
    result = FRMatrixMutiply(result, m3);
    
    if (direction.x * direction.x + direction.y * direction.y + direction.z * direction.z != 0) {
        CGFloat cos2 = sqrt(direction.y * direction.y + direction.z * direction.z) / sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        CGFloat sin2 = -direction.x / sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        CGFloat t2_[4][4] = {{cos2, 0, sin2, 0}, {0, 1, 0, 0}, {-sin2, 0, cos2, 0}, {0, 0, 0, 1}};
        FRMatrix m2_ = FRMatrixMakeFromArray(4, 4, *t2_);
        result = FRMatrixMutiply(result, m2_);
    }
    
    if (direction.z * direction.z + direction.y * direction.y != 0) {
        CGFloat cos1 = direction.z / sqrt(direction.z * direction.z + direction.y * direction.y);
        CGFloat sin1 = direction.y / sqrt(direction.z * direction.z + direction.y * direction.y);
        CGFloat t1_[4][4] = {{1, 0, 0, 0}, {0, cos1, -sin1, 0}, {0, sin1, cos1, 0}, {0, 0, 0, 1}};
        FRMatrix m1_ = FRMatrixMakeFromArray(4, 4, *t1_);
        result = FRMatrixMutiply(result, m1_);
    }
    
    FRPoint resultPoint = FRPointMake(result.matrix[0][0], result.matrix[0][1], result.matrix[0][2]);
    
    return resultPoint;
}



#endif /* FRMatrix_h */
