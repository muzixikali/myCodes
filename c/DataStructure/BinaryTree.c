#include"BinaryTree.h"
#include<stdlib.h>
#include<stdio.h>

Status PreCreateTree(BinaryTree* T){
    ElemType ch;
    scanf("%c",&ch);
    if(ch=='#'){
        *T=NULL;
    }
    else{
        *T=(BinaryTree)malloc(sizeof(Node));
        if(*T==NULL){
            exit(OVERFLOW);
        }
        (*T)->data=ch;
        PreCreateTree(&(*T)->leftChild);
        PreCreateTree(&(*T)->rightChild);
    }
}

Status InCreateTree(BinaryTree* T){
    ElemType ch;
    scanf("%c",&ch);
    if(ch=='#'){
        *T=NULL;
    }
    else{
        *T=(BinaryTree)malloc(sizeof(Node));
        if(*T==NULL){
            exit(OVERFLOW);
        }
        InCreateTree(&(*T)->leftChild);
        (*T)->data=ch;
        InCreateTree(&(*T)->rightChild);
    }
}

Status PostCreateTree(BinaryTree* T){
    ElemType ch;
    scanf("%c",&ch);
    if(ch=='#'){
        *T=NULL;
    }
    else{
        *T=(BinaryTree)malloc(sizeof(Node));
        if(*T==NULL){
            exit(OVERFLOW);
        }
        PostCreateTree(&(*T)->leftChild);
        PostCreateTree(&(*T)->rightChild);
        (*T)->data=ch;
    }
}

Status PreTraverse(BinaryTree T){
    if(T==NULL){
        return OK;
    }
    printf("%c\n",T->data);
    PreTraverse(T->leftChild);
    PreTraverse(T->rightChild);
}

Status InTraverse(BinaryTree T){
    if(T==NULL){
        return OK;
    }
    InTraverse(T->leftChild);
    printf("%c\n",T->data);
    InTraverse(T->rightChild);
}

Status PostTraverse(BinaryTree T){
    if(T==NULL){
        return OK;
    }
    PostTraverse(T->leftChild);
    PostTraverse(T->rightChild);
    printf("%c\n",T->data);
}