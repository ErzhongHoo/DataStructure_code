/**
 * @brief 单链表操作示范
 *
 * @author zhonghu e
 * Contact: ezhonghu@qq.com
 */

#include"LinkList.h"
#include<iostream>

using namespace std;

int main() {
    LinkList L;  //将L定义为LinkList类型变量==实例化单链表为L,返回指向该结点的指针(指向头结点)
     
    InitList(L); //初始化线性表
    cout << "单链表已初始化,返回头结点地址:" << L << endl;

    int a[]={66,55,44,33,22,11};
    CreateList_L_Front(L, a, 6);

    ShowList(L);

    cout << "表头插入元素77.." << endl;
    InserPriorNode(tail,77);
    ShowList(L);

    cout << "删除第3个元素.." << endl;
    int e;
    ListDelete(L, 3, e);
    ShowList(L);

    GetElem(L, 3, e);
    cout << "查找中..第3个元素是:" << e << endl;
    ShowList(L);

    return 0;
}
