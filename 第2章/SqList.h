/**
 * @brief 本文实现了:创建一个顺序表,并且提供插入、删除操作。顺序表按位序1开始。
 *
 * @author zhonghu e 1
 *
 * Contact: ezhonghu@qq.com
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h> //malloc 和 free 函数的头文件

using namespace std;

#define InitSize 10 //初始长度

//别名一个叫SeqList的结构类型（顺序表）
typedef struct{ 
    int *data;  //指示动态分配数组的指针
    int MaxSize;  //顺序表最大容量
    int length;  //顺序表已存放元素的长度
} SeqList;
        
//初始化（模板实例化）
void InitList(SeqList &L){  //带回变量L
    L.data = (int *)malloc(InitSize*sizeof(int));  //malloc申请一整片内存空间,并返回指向第一个元素地址的指针
    L.length = 0;
    L.MaxSize = InitSize;
}

//动态分配表长
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;  //保存原来表开头指针的指向传给指针p
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));  //表扩容
    //逐个把扩容前表里的数据元素搬到新扩容后的内存空间中
    for (int i=0 ; i<L.length ; i++){  //时间开销大
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;  //更新最大储存能力
    free(p);  //释放原来数组的旧数据元素
}

//顺序表插入操作
bool ListInsert(SeqList &L, int i, int e) {  //在i位置插入数据元素e,(i从1开始)
     
    //判断插入的位置i是否合法
    if (i<1 and i>L.length+1) {  
        return false;
    }

    //判断储存空间是否满
    if (L.length > L.MaxSize) {  
        return false;
    }

    //从最后一个数据元素往后移一位,依次向前执行此操作
    for (int j=L.length; j>i; j--) {
        L.data[j] = L.data[j-1];  
    }
    L.data[i-1] = e;  //移完之后插入新数据元素e(因为数组是从0开始,所以插入的位置是i-1)
    L.length++;
    return true;
}

//顺序表删除操作
bool ListDelete(SeqList &L, int i , int &e) {

    //判断输入i是否合理
    if (i<1 and i>L.length) {
        return false;
    }

    e = L.data[i-1];  //被删除元素赋给e
    for (int j=i; j<L.length ; j++) {
        L.data[j-1] = L.data[j];
    }
    L.length--;
;    return true;
}

//顺序表按位查找
int GetElem(SeqList L, int i) {
    return L.data[i-1];
}

//顺序表按值查找
int locateElem(SeqList L, int e) {
    //遍历比较
    for(int i=0; i<L.length ; i++){
        if (L.data[i]==e){  //注意:结构类型无法比较
            return i+1;  //因为要返回位序,所以加1
        }
    }
    return 0;
};


