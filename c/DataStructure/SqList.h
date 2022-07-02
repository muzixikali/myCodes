#pragma once  //防止头文件重复包含

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


/*定义顺序表的初始大小*/
#define MAXSIZE 20

/*定义数据项的类型*/
typedef int ElemType;

/*定义SqList结构*/
typedef struct {
    ElemType* data;  //顺序表的储存数组
    int length;  //顺序表的长度属性
} SqList;

/*初始化顺序表*/
/*输入:顺序表L的地址*/
/*输出:是否初始化成功;空的顺序表L*/
Status InitList(SqList* L);

/*判断顺序表是否为空*/
/*输入:顺序表L*/
/*输出:空为TRUE，非空为FALSE*/
BOOL IsListEmpty(SqList L);

/*返回顺序表的长度*/
/*输入:顺序表L*/
/*输出:顺序表的长度length*/
int ListLength(SqList L);

/*置空顺序表*/
/*输入:顺序表L的地址*/
/*输出:顺序表是否置空成功;空的顺序表L*/
Status ClearList(SqList* L);

/*销毁顺序表*/
/*输入:顺序表L的地址*/
/*输出:顺序表是否销毁成功;未初始化的顺序表L*/
Status DestoryList(SqList* L);

/*用变量获取顺序表特定位置的值*/
/*输入:顺序表L;位置i;接受数据的变量e的地址*/
/*输出:是否取值成功;e被赋值i号位置上的数据*/
Status GetElem(SqList L,int i,ElemType* e);

/*查找数据在顺序表中的位置*/
/*输入:顺序表L;数据项e*/
/*输出:数据项e在顺序表中的位置。不存在返回NOTFOUND*/
int LocateElem(SqList L,ElemType e);

/*向顺序表指定位置插入数据*/
/*输入:顺序表L的地址;位置i;要插入的数据项e*/
/*输出:是否插入成功;e插入到i号位置,i号位置及以后数据后移*/
Status ListInsert(SqList* L,int i,ElemType e);

/*删除顺序表特定位置的数据*/
/*输入:顺序表L的地址;位置i;接受被删除的数据的变量e的地址*/
/*输出:是否删除成功;i号位置数据被删除;i以后的数据前移;e获得被删除的数据*/
Status ListDelete(SqList* L,int i,ElemType* e);











