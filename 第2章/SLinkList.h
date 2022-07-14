/**
 * @brief 静态链表
 *
 * @author zhonghu e
 *
 * Contact: ezhonghu@qq.com
 */

#include<stdio.h>
#include<iostream>
#define MaxSize 10

//游标指向下一个位置序号,指向-1的为结束
//| 序号 | data | 游标 | 
//|:----:|:----:|:----:|
//|   0  |  头  |   2  |
//|   1  |  e2  |   6  |
//|   2  |  e1  |   1  |
//|   3  |  e4  |  -1  |
//|   4  |      |      |
//|   5  |      |      |
//|   6  |  e3  |   3  |
//|   7  |      |      |
//|   8  |      |      |
//|   9  |      |      |

typedef int ElemType;

typedef struct {
    ElemType data;
    int next;  //这里的next是游标(序号),不是指针
} SLinkList[MaxSize];



