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

/*定义静态链表的最大长度*/
#define MAXSIZE 100

/*定义数据项的类型*/
typedef int ElemType;

/*定义静态链表(结点数组)与结点结构*/
typedef struct component{
    ElemType data;  //数据
    int cursor;     //游标
}component,StaticLinkList[MAXSIZE];

/*初始化静态链表*/
/*输入:静态链表L(数组名)*/
/*输出:是否初始化成功;数组的最后一个位置记录第一个数据项的位置,数组的0号位置记录备用链表的起始位置*/
Status InitList(StaticLinkList L);

/*准备空闲结点的位置*/
/*输入:静态链表L(数组名)*/
/*输出:备用链表非空则返回备用链表中一个的空闲位置;否则返回0;备用链表位置更新*/
int Prepare_Component(StaticLinkList L);

/*返回静态链表的长度*/
/*输入:静态链表L(数组名)*/
/*输出:静态链表的长度length*/
int ListLength(StaticLinkList L);

/*用变量获取静态链表特定位置的值*/
/*输入:静态链表L(数组名);位置i;接受数据的变量e的地址*/
/*输出:是否取值成功;e被赋值i号位置上的数据*/
Status GetElem(StaticLinkList L,int i,ElemType* e);

/*在静态链表指定位置插入数据项*/
/*输入:静态链表L(数组名);位置i;要插入的数据项e*/
/*输出:是否插入成功;e插入到i号位置,i号位置及以后数据后移*/
Status ListInsert(StaticLinkList L,int i,ElemType e);

/*释放空闲结点*/
/*输入:静态链表L(数组名);下标k*/
/*输出:将数组k下标结点加入备用链表*/
void Free_Component(StaticLinkList L,int k);

/*删除静态链表指定位置的数据项*/
/*输入:静态链表L(数组名);位置i;接收数据的变量e的地址*/
/*输出:是否插入成功;e插入到i号位置,i号位置及以后数据后移*/
Status ListDelete(StaticLinkList L,int i,ElemType* e);


