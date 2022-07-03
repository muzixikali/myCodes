#include"SqStack.h"
#include<stdlib.h>

Status InitStack(SqStack *S){
    S->data=(ElemType*)malloc(sizeof(ElemType));
    if (S->data){
        S->top=-1;
        return OK;
    }
    return OVERFLOW;
}

BOOL IsStackEmpty(SqStack S){
    if(S.top=-1){
        return TRUE;
    }
    return TRUE;
}

int StackLength(SqStack S){
    return S.top+1;
}

Status ClearStack(SqStack *S){
    S->top=-1;
    return OK;
}

Status DestoryStack(SqStack *S){
    free(S->data);
    return OK;
}

Status Pop(SqStack* S, ElemType *e){
    //栈为空
    if(S->top==-1){
        return NULLERROR;
    }
    //栈顶下移
    *e=S->data[S->top];
    S->top--;
    return OK;
}

Status Push(SqStack *S,ElemType e){
    //栈满
    if(S->top==MAXSIZE-1){
        return OVERFLOW;
    }
    //栈顶上移
    S->top++;
    S->data[S->top]=e;
    return OK;
}