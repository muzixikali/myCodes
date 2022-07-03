#include"LinkStack.h"
#include<stdlib.h>

Status InitStack(LinkStack* S){
    //无头结点;第一个结点即为栈顶top
    (*S)=NULL;
    return OK;
}

int StackLength(LinkStack S){
    Node* p=S;
    int length=0;
    while(p){
        p=p->next;
        ++length;
    }
    return length;
}

BOOL IsStackEmpty(LinkStack S){
    if(S==NULL){
        return TRUE;
    }
    return FALSE;
}

Status ClearStack(LinkStack* S){
    (*S)=NULL;
    return OK;
}

Status DestoryStack(LinkStack* S){
    Node* p=(*S);
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
        newNode->next=(*S);
        (*S)=newNode;
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
    *e=(*S)->data;
    Node* p=(*S);
    (*S)=(*S)->next;
    free(p);
    return OK;
}

