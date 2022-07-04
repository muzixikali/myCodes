#include"SqQuene.h"
#include<stdlib.h>

Status InitQuene(SqQuene* Q){
    Q->data=(ElemType *)malloc(sizeof(ElemType));
    if(Q->data){
        //队列为空时队头队尾相同
        Q->font=0;
        Q->rear=0;
        return OK;
    }
    return OVERFLOW;
}

int QueneLength(SqQuene Q){
    return (Q.rear-Q.font+MAXSIZE)%MAXSIZE;
}

BOOL IsQueneEmpty(SqQuene Q){
    if (Q.font==Q.rear){
        return TRUE;
    }
    return FALSE;
}

Status ClearQuene(SqQuene* Q){
    Q->font=0;
    Q->rear=0;
    return OK;
}

Status DestoryQuene(SqQuene* Q){
    free(Q->data);
    return OK;
}

Status Enter(SqQuene* Q,ElemType e){
    //栈满
    if( (Q->rear+1)%MAXSIZE==Q->font ){
        return OVERFLOW;
    } 
    //队尾加1
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}

Status Out(SqQuene* Q,ElemType* e){
    //栈空
    if(Q->font==Q->rear){
        return NULLERROR;
    }
    //队头加1
    *e=Q->data[Q->font];
    Q->font=(Q->font+1)%MAXSIZE;
    return OK;
}