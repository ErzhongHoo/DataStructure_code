/**
 * @brief 单链表初始化、插入、删除、查找
 *
 * @author zhonghu e
 *
 * Contact: ezhonghu@qq.com
 */

#include<stdio.h>
#include<stdlib.h>

//定义结点
typedef struct LNode {
    //一个结点由data+next组成
    int data;  //存放数据(数据域)
    struct LNode *next;  //指针指向下一个结点(指针域)
}LNode, *LinkList;  //LNode *强调结点指针, LinkList强调单链表,其实等价,区分是为了让可读性更高

//初始化结点(带头结点)
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));  //分配一个头结点,返回指向这个单链表的头结点的指针
    if (L == NULL) {  //内存不足,分配失败
        return false;
    }
    L->next = NULL; //头结点指针域指向NULL,不存数据,因为之后暂时还没有结点
    return true;
}

//按位查找,返回第i个LNode结点的指向(带头节点)
LNode * GetElem(LinkList L, int i) {
    if (i<0) {
        return false;
    }
    LNode *p;  //指针p指向当前扫描的结点
    int j=0;  //当前p指向的是第几个结点
    p = L;  //指向头结点,头节点是第0个结点,不存数据
    while (p!=NULL && j<i) {
        j++;
    }
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


//指定某个结点之后,插入操作(不从L开始)
bool InserNextNode(LNode &L, int e) {
    if (p==NULL) {  //i有误(不存在)
        return false;
    }
    LNods *p GetElem(LinkList L, i-1);  //p指针指向LNode的i-1结点
   /* 
    * //例:往a3插入一个新结点s(i=3)
    * //a1 -> a2[data|next]   a3 ->a4 ->...
    * //       \             /
    * //         s[data:next]
   */
    LNode *s = (LNode *)malloc(sizeof(LNode));  //新分配一个结点
    if (s==NULL) {  //判断是否内存不足,无法分配空间
        return false;
    }
    s->data = e;
    s-next = p->next;
    p->next = s;
    return true;
}

//在第i个位置插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, int e) {
    if (i < 1) {
        return false;
    }

    LNode *p = GetElem(L, i-1);  //找到第i-1个结点,让指针p指向
    return InserNextNode;
}



//不带头结点插入
bool noHeadNodeListInsert(LinkList &L, int i, int e) {
    if (i<1) {
        return false;
    }

    //不带头结点主要是i=1不同
    // L        a1 -> a2
    //  \      /
    //   s[data:next]
    if (i=1) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;  //指向L原本指向的位置(i=1)
        L = s;  //头指针指向新结点
        return true;
    }

    LNode *p;  //指针p指向当前扫描到结点的位置
    int j=1;  //指针p指向第几个结点(从第1个结点开始扫描)
    p = L;  //L指向的是第一个结点(没有头结点)
    while (p!=NULL && j<i-1) {
        p = P->next;
        j++;
    }

    if (p==NULL) {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p;
    p->next = s;
    return true;
    }
}

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
    p-data = e;
    return true;
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
        j++
    }

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
    LNode *q = p->next;  //q指的是要被删除的那个结点
    e = q->data;  //暂存被删除的内容
    p->next = q->next;  //i-1直接指向i+1个结点(跳过i结点)
    free(q);
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


//头插法建立单链表
LinkList List_HeadInsert (LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof (LNode));
    L->next=NULL;
    scanf("%d", &dx);
    while(x!=9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &dx);
    }
    return L;
}
        
void main() {
    LinkList L;  //实例化一个指向单链表的指针
     
    //初始化一个空表
    InitList(L); 
}
