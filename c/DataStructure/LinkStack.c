#include"LinkStack.h"
#include<stdlib.h>

Status InitStack(LinkStack* S){
    //栈顶结点为空
    S->top=NULL;
    S->count=0;
    return OK;
}

int StackLength(LinkStack S){
   return S.count;
}

BOOL IsStackEmpty(LinkStack S){
    if(S.top==NULL){
        return TRUE;
    }
    return FALSE;
}

Status ClearStack(LinkStack* S){
    S->top=NULL;
    return OK;
}

Status DestoryStack(LinkStack* S){
    Node* p=S->top;
    while(p){
        Node* q=p;
        p=p->next;
        free(q);
    }
    return OK;
}

Status Push(LinkStack* S,ElemType e){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode){
        newNode->data=e;
        newNode->next=S->top;
        S->top=newNode;
        return OK;
    }
    return OVERFLOW;
}

Status Pop(LinkStack* S,ElemType* e){
    //栈空
    if(S==NULL){
        return NULLERROR;
    }
    //
    *e=S->top->data;
    Node* p=S->top;
    S->top=S->top->next;
    free(p);
    return OK;
}

