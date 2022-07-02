/*定义状态码*/
typedef int Status;
//内存溢出
#define OVERFLOW 0
//数据未查找到
#define NOTFOUND -1
//索引出错
#define INDEXOUT -2
//操作成功    
#define OK 1 

/*定义bool数*/
typedef int BOOL;
#define FALSE 0
#define TRUE 1 

/*定义数据项的类型*/
typedef int ElemType;

/*定义数据结点结构*/
typedef struct Node{
    ElemType data;   //数据域
    struct Node* next;   //指针域
} Node,*LinkList;



/*初始化单链表*/
/*输入:单链表L的头指针的地址*/
/*输出:是否初始化成功;空的、只有头结点的单链表L*/
Status InitList(LinkList* L);

/*判断单链表是否为空*/
/*输入:单链表L的头指针*/
/*输出:空为TRUE，非空为FALSE*/
BOOL IsListEmpty(LinkList L);

/*返回单链表的长度*/
/*输入:单链表L的头指针*/
/*输出:单链表的长度length*/
int ListLength(LinkList L);

/*置空单链表*/
/*输入:单链表L的头指针的地址*/
/*输出:单链表是否置空成功;空的只有头结点的单链表L*/
Status ClearList(LinkList* L);

/*销毁单链表*/
/*输入:单链表L的头指针的地址*/
/*输出:单链表是否销毁成功;未初始化的顺序表L*/
Status DestoryList(LinkList* L);

/*用变量获取单链表特定位置的值*/
/*输入:单链表L的头指针;位置i;接受数据的变量e的地址*/
/*输出:是否取值成功;e被赋值i号位置上的数据*/
Status GetElem(LinkList L,int i,ElemType* e);

/*查找数据在单链表中的位置*/
/*输入:单链表L的头指针;数据项e*/
/*输出:数据项e在单链表中的位置。不存在返回NOTFOUND*/
int LocateElem(LinkList L,ElemType e);

/*向单链表指定位置插入数据*/
/*输入:单链表L的头指针的地址;位置i;要插入的数据项e*/
/*输出:是否插入成功;e插入到i号位置,i号位置及以后数据后移*/
Status ListInsert(LinkList* L,int i,ElemType e);

/*删除单链表特定位置的数据*/
/*输入:单链表L的头指针的地址;位置i;接受被删除的数据的变量e的地址*/
/*输出:是否删除成功;i号位置数据被删除;i以后的数据前移;e获得被删除的数据*/
Status ListDelete(LinkList* L,int i,ElemType* e);

