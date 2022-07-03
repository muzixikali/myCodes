#include"SqDoubleStack.h"
#include<stdlib.h>

Status InitStack(SqDoubleStack *S){
    //分配空间
    S->data=(ElemType*)malloc(sizeof(ElemType));
    if(S->data){
        //栈空条件
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
    }
    return OVERFLOW;
}

BOOL IsStackEmpty(SqDoubleStack S,int StackNum){
    if (StackNum==1){
        //1号栈
        if(S.top1==-1){
            return TRUE;
        }
        return FALSE;
    }
    else if(StackNum==2){
        //2号栈
        if(S.top2=MAXSIZE){
            return TRUE;
        }
        return FALSE;
    }
    else{
        //编号输入错误
        return INPUTERROR;
    }
}

int StackLength(SqDoubleStack S,int StackNum){
    if (StackNum==1){
        return S.top1+1;
    }
    else if (StackNum==2){
        return MAXSIZE-S.top2;
    }
    else{
        return INPUTERROR;
    }
}

Status ClearStack(SqDoubleStack *S,int StackNum){
    S->top1=-1;
    S->top2=MAXSIZE;
    return OK;
}

Status DestoryStack(SqDoubleStack *S){
    free(S->data);
    return OK;
}

Status Pop(SqDoubleStack* S,int StackNum, ElemType *e){
    if(StackNum==1){
        if(S->top1==-1){
            return NULLERROR;
        }
        *e=S->data[S->top1];
        S->top1--;
    }
    else if (StackNum==2){
        if(S->top2==MAXSIZE){
            return NULLERROR;
        }
        *e=S->data[S->top2];
        S->top2++;
    }
    else{
        return INPUTERROR;
    }
    return OK;
}

Status Push(SqDoubleStack* S,int StackNum, ElemType e){
    //栈满。空间不够。
    if(S->top1+1==S->top2){
        return OVERFLOW;
    }
    if (StackNum==1){
        S->top1++;
        S->data[S->top1]=e;
       
    }
    else if(StackNum==2){
        S->top2--;
        S->data[S->top2]=e;
    }
    else{
        return INPUTERROR;
    }
    return OK;
}