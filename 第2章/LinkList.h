/**
 * @brief 单链表结构定义、初始化、插入、删除、查找
 *
 * @author zhonghu e
 *
 * Contact: ezhonghu@qq.com
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;


//定义结点
//┌──────────┐
//│data│next*│
//└──────────┘
typedef struct LNode {
    //一个结点由data+next组成
    int data;  //存放数据(数据域)
    struct LNode *next;  //指针指向下一个结点(指针域)
}LNode, *LinkList;  //LNode *强调结点指针, LinkList强调单链表,其实等价,区分是为了让可读性更高
 
LNode * tail;  //表尾指针

//初始化结点(带头结点)
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));  //分配一个头结点,返回指向这个单链表的头结点的指针
    //L = new LNode;
    if (L == NULL) {  //返回为NULL：内存不足,分配失败
        return false;
    }
    L->next = NULL; //这个初始化的节点为头节点,让其指针域指向NULL(因为之后暂时还没有结点)
    return true;
}

//按位查找,返回第i个LNode结点的指向(带头节点)
LNode * GetElem(LinkList L, int i) {
    if (i<1) {
        return NULL;
    }
    LNode *p;  //声明一个指针p,用于指向当前扫描的结点
    int j=0;  //用于说明当前的p指向的是第几个结点,从0开始
    p = L;  //让p指针指向头结点
    while (p!=NULL && j<i) {
        j++;  //遍历直到i的前一个结点停下,或到表尾
    }
    cout << p->data << endl;
    return p;
}

//按值查找
LNode * LocateElem(LinkList L, int e) {
    LNode *p = L->next;  //从第1个结点开始查找
    while (p!=NULL && (p->data != e)) {  //直到p指向的结点数据域为e
        p = p->next;
    }
    return p;  //找到后返回该指针
}


//插入某个结点之后(不从头节点开始遍历)(后插)
bool InserNextNode(LNode *p ,int e) {
    if (p==NULL) {  
        cout << "错误！" << endl;
        return false;
    }

   /* 
    * //例:往a3插入一个新结点s(i=3)
    * //a1 -> a2[data|next]   a3 ->a4 ->...
    * //       \             /
    * //         s[data:next]
   */
    LNode *s = (LNode *)malloc(sizeof(LNode));  //新分配一个结点
    if (s==NULL) {  //判断是否内存不足而无法分配空间
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//在i结点前插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, int e) {
    if (i < 1) {
        return false;
    }

    LNode *p = GetElem(L, i-1);  //找到第i-1个结点,让指针p指向
    return InserNextNode(p, e);
}



////不带头结点插入
//bool noHeadNodeListInsert(LinkList &L, int i, int e) {
//    if (i<1) {
//        return false;
//    }
//
//    //不带头结点主要是i=1不同
//    // L        a1 -> a2
//    //  \      /
//    //   s[data:next]
//    if (i=1) {
//        LNode *s = (LNode *)malloc(sizeof(LNode));
//        s->data = e;
//        s->next = L;  //指向L原本指向的位置(i=1)
//        L = s;  //头指针指向新结点
//        return true;
//    }
//
//    LNode *p;  //指针p指向当前扫描到结点的位置
//    int j=1;  //指针p指向第几个结点(从第1个结点开始扫描)
//    p = L;  //L指向的是第一个结点(没有头结点)
//    while (p!=NULL && j<i-1) {
//        p = p->next;
//        j++;
//    }
//
//    if (p==NULL) {
//        return false;
//    }
//
//    LNode *s = (LNode *)malloc(sizeof(LNode));
//    s->data = e;
//    s->next = p;
//    p->next = s;
//    return true;
//    }
//}

//指定结点前插操作
bool InserPriorNode(LNode *p, int e) {
    if (p==NULL) {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s==NULL) {
        return false;
    }
    
    //  unknow  -> a(i-1)         a(i) -> ...
    //              \            /
    //              s[data|next]
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//尾插操作
LinkList List_TailInsert(LinkList &L, int e) {
    int x;  //元素类型为整形
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s,*r = L;  //r为尾指针
    scanf("%d",&x);
    while (x!=9999) {  //输入9999表示结束输入
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;  //上一个表尾结点
        r = s;  //r指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 已知一维数组A[n]中存有线性表的数据元素,利用头插法创建单链表L
// 头插法缺点:输入顺序和存入顺序相反
bool CreateList_L_Front(LinkList &L,int a[],int n ) {
    LNode *p;  
    int i;
    for(i=n-1; i>=0; i--) {
        p = (LNode *)malloc(sizeof(LNode)); //创建新结点
        p->data=a[i];    // 数据域赋值
        p->next=L->next;  //新结点的指针指向原来L指向的位置
        L->next=p;   //L指针指向新结点
    }
    tail = p;
    cout << "表尾地址:" << tail << endl;
    return 0;
}

//按位序删除(带头结点)
//有头结点,依次往后查找
bool ListDelete(LinkList &L, int i, int &e) {
   if (i<1) {
       return false;
   }

   LNode *p;
   int j=0;
   p = L;
   while (p!=NULL && j<i-1) {  //找到第i-1个结点
       p = p->next;  //p指向第i-1个结点
       j++;
   }

   //GetElem(L, i-1);

   if (p==NULL) {
       return false;
   }

   if (p->next == NULL){
       return false;
   }

   //...-> a(i-1) -> a(i) ->a(i+1) -> ...
   //      |                ^
   //      ---------------->|
   //      p         q       
   LNode *q = p->next;  //q指向p的后继(i)
   e = q->data;  //暂存被删除的内容
   p->next = q->next;  //i-1直接指向i+1个结点(跳过i结点)
   free(q);  //q在这个函数中只充当中间人的角色,使用后释放
   return true;
}

//指定结点删除
//不知道头结点
bool DeleteNode(LNode *p) {
    if (p=NULL) {
        return false;
    }

    LNode *q = p->next;
    p->data = q->next->data;  //把i的data传给i-1的data
    p->next = q->next;  //i-1指针直接指向i+1(跳过i结点)
    free(q);
    return true;
}


////头插法建立单链表
//LinkList List_HeadInsert (LinkList &L) {
//    LNode *s;
//    int x;
//    L = (LinkList)malloc(sizeof (LNode));
//    L->next=NULL;
//    scanf("%d", &dx);
//    while(x!=9999) {
//        s = (LNode*)malloc(sizeof(LNode));
//        s->data=x;
//        s->next = L->next;
//        L->next = s;
//        scanf("%d", &dx);
//    }
//    return L;
//}
        
//输出链表内容
void ShowList(LinkList L) {  
    cout << "表:";
    while(L) {
      printf("%d ",L->data);
      L=L->next;
    }
    printf("\n");
}
