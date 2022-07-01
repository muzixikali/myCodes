#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"


Status InitList(SqList *L){
    //为数组data分配空间
    L->data= (ElemType*) malloc(sizeof(ElemType)*MAXSIZE);
    //如果分配失败，退出，返回OVERFLOW状态码
    if (L->data==NULL){
        exit(OVERFLOW);
    }
    //如果分配成功，初始化线性表长度，返回OK状态码
    L->length=0;
    return OK;
}

BOOL IsListEmpty(SqList L){
    //根据length属性进行判断
    if(L.length==0){
        return TRUE;
    } 
    return FALSE;
    
}

int ListLength(SqList L){
    return L.length;
}

Status ClearList(SqList* L){
    //长度置零，逻辑上清空
    L->length=0;
    return OK;
}

Status DestoryList(SqList* L){
    //清空L的数据数组data
    free(L->data);
    return OK;
}

Status GetElem(SqList L,int i,ElemType* e){
    //索引小于0或大于length,返回INDEXOUT
    if (i<1 || i>L.length){
        return INDEXOUT;
    }
    *e=L.data[i-1];
    return OK;
}

int LocateElem(SqList L,ElemType e){
    //遍历查找，找到就返回位置i+1
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    //没找到返回NOTFOUND
    return NOTFOUND;
}

Status ListInsert(SqList* L,int i,ElemType e){
    //索引出错，返回INDEXOUT
    if( (i<1) || (i>L->length+1)){
        return INDEXOUT;
    }

    //长度达到最大限度，返回OVERFLOW
    if(L->length==MAXSIZE){
        return OVERFLOW;
    }

    //i号及以后的数据全体后移
    for(int j=L->length-1;j>=i-1;j--){
        L->data[j+1]=L->data[j];
    }

    //i号位置赋值数据e
    L->data[i-1]=e;
    //长度+1
    ++L->length;
    return OK;
}

Status ListDelete(SqList* L,int i,ElemType* e){
    //索引出错，返回INDEXOUT
    if ( (i<1) || (i>L->length) ){
        return INDEXOUT;
    }

    //将i号位置的数据赋给e
    *e=L->data[i-1];
    
    //i以后的数据全体前移
    for (int j=i;j<L->length;j++){
        L->data[j-1]=L->data[j];
    }
    //长度-1
    --L->length;
    return OK;
}