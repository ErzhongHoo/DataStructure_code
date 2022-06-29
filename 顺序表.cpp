/**
 * @brief 本文实现了:创建一个顺序表,并且提供插入、删除操作。顺序表按位序1开始。
 *
 * @author zhonghu e
 *
 * Contact: ezhonghu@qq.com
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h> //malloc 和 free 函数的头文件

using namespace std;

#define InitSize 10 //初始长度

//别名一个叫SeqList的struct(结构类型)
typedef struct{ 
    int *data;  //指示动态分配数组的指针
    int MaxSize;  //顺序表最大容量
    int length;  //顺序表已存放元素的长度
} SeqList;
        
//创建实例模板
void InitList(SeqList &L){
    L.data = (int *)malloc(InitSize*sizeof(int));  //malloc申请一整片内存空间,并返回指向第一个元素地址的指针
    L.length = 0;
    L.MaxSize = InitSize;
}

//动态分配数组长度
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;  //保存原来的数组开头地址给p指针
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));  //L.data扩容
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

int main() {
    SeqList L;  //创建实例模板,称为L
    InitList(L);  //初始化L
    //插入操作
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    //ListDelete(L, 1, e)
    //遍历输出线性表
    cout << "原始顺序表:";
    for (int k=0; k<L.length ; k++) {
        cout << L.data[k] << ",";
    }
    cout << endl <<  "顺序表已存储数据长度:" << L.length << endl;
    cout << "顺序表最大储存长度:" << L.MaxSize << endl;

    //删除操作
    int e = 1;
    cout << "执行删除操作中..." << endl;
    if (ListDelete( L, 3, e)) {
        cout << "已删除第3个元素,删除的值是:" << e << endl;
    }
    else {
        cout << "位序i不合法" << endl;
    };
    //遍历输出线性表
    cout << "当前顺序表:";
    for (int k=0; k<L.length ; k++) {
        cout << L.data[k] << ",";
    }
    cout << endl;

    //顺序表扩容
    cout << "顺序表扩容中..." << endl;
    IncreaseSize(L,3);
    cout << "扩容后最大储存长度:" << L.MaxSize << endl;

    //按位查找
    cout << GetElem(L, 3) << endl;
    
    //按值查找
    cout << locateElem(L,5) << endl;
    
    return 0;
}
