/**
 * @brief 实现双链表
 *
 * @author zhonghu e
 *
 * Contact: ezhonghu@qq.com
 */

#include<stdio.h>
#include<iostream>

//┌───────────────────┐
//│ prior*|data|next* │
//└───────────────────┘

typedef struct DNode {
    int data;
    struct DNode *prior;  //指向直接前驱
    struct DNode *next;  //指向直接后继
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L) {
    L = (DNode *)malloc(sizeof(DNode));
    if (L==NULL) {
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//判空操作
bool Empty(DLinkList &L) {
    if (L->next == NULL){
        return true;
    }
    else {
        return false;
    }

}

bool InserNextDNode(DNode *p, DNode *s){
    if (p==NULL || s==NULL) {  //非法参数
        return false;
    }
    s->next = p->next;
    if (p->next !=NULL){
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
}

//删除p结点的后继结点
bool DeleteNextNode (DNode *p){
   if (p==NULL){
       return false;
   }
   DNode *q = p->next;
   if (q==NULL){
       return false;
   }
   p->next = q->next;
   if (q->next != NULL){
       q->next->prior = p;
   }
   free(q);
   return true;
}

//销毁双链表
void DestroyList(DLinkList &L) {
    while (L->next != NULL) {
        DeleteNextNode(L);
    }
    free(L);
    L = NULL;
}

//双链表遍历
