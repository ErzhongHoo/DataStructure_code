/**
 * @brief 单链表操作示范
 *
 * @author zhonghu e
 *
 * Contact: ezhonghu@qq.com
 */

#include"LinkList.h"
#include<iostream>

using namespace std;

int main() {
    LinkList L;  //将L定义为LinkList类型变量==实例化单链表为L,返回指向该结点的指针(指向头结点)
     
    InitList(L); //初始化线性表

    int a[]={11,22,33,44,55,66};
    CreateList_L_Front(L, a, 6);

    cout << "初始单链表:";
    ShowList(L);

    cout << "正在删除第3个元素..";
    int e;
    ListDelete(L, 3, e);

    cout << endl << "当前单链表:" ;
    ShowList(L);
    return 0;
}
