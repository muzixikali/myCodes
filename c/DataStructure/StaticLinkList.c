#include"StaticLinkList.h"

Status InitList(StaticLinkList L){
    int i;
    for (i=0;i<MAXSIZE-1;i++){
        //依次指向下一个结点
        L[i].cursor=i+1;
    }
    L[MAXSIZE-1].cursor=0;  //最后一个节点指向第一个有数据的结点,目前都没有数据,指向0
    return OK;
}

int Prepare_Component(StaticLinkList L){
    int i=L[0].cursor;  //0号位置记录着备用链表的第一个位置
    if(L[0].cursor){
        //更新备用链表的位置
        L[0].cursor=L[i].cursor;
    }
    return i;
}

int ListLength(StaticLinkList L){
    int j=0;
    int i=L[MAXSIZE-1].cursor;
    //从第一个数据项开始循环计数,直至最后一个数据项(cursor指向0)
    while(i){
        i=L[i].cursor;
        j++;
    }
    return j;
}

Status GetElem(StaticLinkList L,int i,ElemType* e){
    int j,k;
    //索引出错
    if( i<1 || i>ListLength(L)){
        return INDEXOUT;
    }
    k=MAXSIZE-1;
    //找到第i个数据结点
    for(j=1;j<=i;j++){
        k=L[k].cursor;
    }
    *e=L[k].data;
    return OK;
}

Status ListInsert(StaticLinkList L,int i,ElemType e){
    int j,k,l;
    k=MAXSIZE-1;
    //索引出错
    if( i<1 || i>ListLength(L)+1){
        return INDEXOUT;
    }
    //为新结点准备空闲位置
    j=Prepare_Component(L);
    if (j){
        L[j].data=e;
        //找到第i-1个数据项
        for (l=1;l<=i-1;l++){
            k=L[k].cursor;
        }
        //新结点指向i-1个数据项的指向结点
        L[j].cursor=L[k].cursor;
        //i-1个数据项的游标指向新结点
        L[k].cursor=j;
        return OK;
    }
    return OVERFLOW;
}

void Free_Component(StaticLinkList L,int k)
{
    L[k].cursor=L[0].cursor; //连接备用链表
    L[0].cursor=k;  //更新空闲的备用链表
}

Status ListDelete(StaticLinkList L,int i,ElemType* e){
    int j,k;
    //索引出错
    if( i<1 || i>ListLength(L)){
        return INDEXOUT;
    }
    k=MAXSIZE-1;
    //找到第i-1个数据结点
    for(j=1;j<=i-1;j++){
        k=L[k].cursor;
    }
    j=L[k].cursor;
    *e=L[j].data;
    L[k].cursor=L[j].cursor;
    Free_Component(L,j);
    return OK;
}