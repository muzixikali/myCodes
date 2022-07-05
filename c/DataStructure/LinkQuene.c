#include"LinkQuene.h"
#include"stdlib.h"

Status InitQuene(LinkQuene* Q){
    //头尾指针都指向头结点
    Q->font=Q->rear=(Node*)malloc(sizeof(Node));
    Q->font->next=NULL;
    Q->count=0;
    return OK;
}

int QueneLength(LinkQuene Q){
    return Q.count;
}

BOOL IsQueneEmpty(LinkQuene Q){
    if(Q.font==Q.rear){
        return TRUE;
    }
    return FALSE;
}

Status ClearQuene(LinkQuene* Q){
    Q->rear=Q->font;
    Q->count=0;
    return OK;
}

Status DestoryQuene(LinkQuene* Q){
    Node*p=Q->font;
    while(p){
        Node* q=p;
        p=p->next;
        free(q);
    }
    return OK;
}

Status Enter(LinkQuene* Q,ElemType e){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode){
        newNode->data=e;
        newNode->next=NULL;

        Q->rear->next=newNode;
        Q->rear=newNode;
        Q->count++;
        return OK;
    }
    return OVERFLOW;
}

Status Out(LinkQuene* Q,ElemType* e){
    if(Q->font==Q->rear){
        return NULLERROR;
    }
    Node* deleted=Q->font->next;
    *e=deleted->data;
    Q->font->next=deleted->next;
    Q->count--;
    //如果是最后一个元素出队，置空
    if(Q->rear==deleted){
        Q->rear=Q->font;
    }
    return OK;
}