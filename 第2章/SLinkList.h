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

typedef int ElemType;

typedef struct {
    ElemType data;
    int next;  //这里的next是游标(序号),不是指针
} SLinkList[MaxSize];



