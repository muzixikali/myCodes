#include <stdlib.h>
#include "LinkList.h"

Status InitList(LinkList* L){
    //为头结点分配空间
    *L=(LinkList) malloc(sizeof(Node));
    if (L)
        //分配成功，将头结点的指针域置空
        (*L)->next=NULL;
        return OK;
    return OVERFLOW;
}

BOOL IsListEmpty(LinkList L){
    //根据头结点的下一个结点是否为空判断
    if (L->next==NULL){
        return TRUE;
    }
    return FALSE;
}

int ListLength(LinkList L){
    Node* p=L->next;
    int length=0;
    while(p){
        p=p->next;
        ++length;
    }
    return length;
}

Status ClearList(LinkList* L){
    //将头指针的指针域置空
    (*L)->next=NULL;
}

Status DestoryList(LinkList* L){
    free(*L);
}

Status GetElem(LinkList L,int i,ElemType* e){
    //p从第一个数据结点开始
    Node* p=L->next;
    int j=1;
    //循环直至p为空或找到位置为i的结点
    while( p && j<i)
    {
        p=p->next;
        ++j;
    }
    //!p说明到达单链表尾部,但还是没有找到i位置，即i>L->length
    //j>i说明i<=0
    //都返回INDEXOUT
    if ( !p || j>i){
        return INDEXOUT;
    }
    //现在p已经找到了位置为i的结点
    //将数据赋给e
    *e=p->data;
    return OK;
}

int LocateElem(LinkList L,ElemType e){
    //p从第一个数据结点开始
    Node* p=L->next;
    int j=1;
    //循环对比直至p为空或找到对应数据
    while ( p && p->data!=e)
    {
        p=p->next;
        ++j;
    }
    //p为空,说明没找到对应数据
    if (!p){
        return NOTFOUND;
    }
    //返回位置
    return j;
}

Status ListInsert(LinkList* L,int i,ElemType e){
    Node* p=(*L);
    int j=0;
    //找到第i-1个数据节点
    while( p && j<i-1){
        p=p->next;
        ++j;
    }
    //p为空说明i-1>L.length;即i>L.length+1
    //j>i-1说明i<1
    //都返回INDEXOUT
    if ( !p || j>i-1){
        return INDEXOUT;
    }
    //为新结点分配内存
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode){
        newNode->data=e;
        //新结点指向i-1结点的下一个结点
        if (p->next){
            newNode->next=p->next;
            //i-1结点指向新结点
            p->next=newNode;
        }
        else{
            newNode->next=NULL;
            p->next=newNode;
        }
        //插入成功
        return OK;
    }
    
    return OVERFLOW;
}

Status ListDelete(LinkList* L,int i,ElemType* e){
    Node* p=(*L);
    int j=0;
    //找到第i-1个数据节点
    while( p && j<i-1){
        p=p->next;
        ++j;
    }
    //p为空说明i-1>L.length;即i>L.length+1
    //j>i-1说明i<1
    //都返回INDEXOUT
    if ( !p || j>i-1){
        return INDEXOUT;
    }
    //保存被删除结点的地址，以便释放空间
    Node* deleted=p->next;
    *e=deleted->data;
    //i-1个结点指向被删除结点的下一个结点,逻辑删除
    p->next=deleted->next;
    //删除成功
    free(deleted);
    return OK;
}


