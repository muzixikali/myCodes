/*定义状态码*/
typedef int Status;
//内存溢出
#define OVERFLOW 0
//数据未查找到
#define NOTFOUND -1
//队空错误
#define NULLERROR -2
//操作成功
#define OK 1

/*定义bool数*/
typedef int BOOL;
#define FALSE 0
#define TRUE 1

/*定义队列的初始大小*/
#define MAXSIZE 20

/*定义数据项的类型*/
typedef int ElemType;

/*定义队列结构*/
typedef struct SqQuene{
    ElemType* data;
    int font; //前端
    int rear;   //后端
}SqQuene;

/*初始化顺序循环队列*/
/*输入:队列Q的地址*/
/*输出:是否初始化成功;已初始化的队列Q*/
Status InitQuene(SqQuene* Q);

/*返回队列长度*/
/*输入:队列Q*/
/*输出:队列长度*/
int QueneLength(SqQuene Q);

/*判断队列是否为空*/
/*输入:队列Q*/
/*输出:空为TRUE，非空为FALSE*/
BOOL IsQueneEmpty(SqQuene Q);

/*置空队列*/
/*输入:队列Q的地址*/
/*输出:队列是否置空成功;空的队列Q*/
Status ClearQuene(SqQuene* Q);

/*销毁队列*/
/*输入:队列Q的地址*/
/*输出:队列是否销毁成功;未初始化的队列Q*/
Status DestoryQuene(SqQuene* Q);

/*数据进入队列*/
/*队列Q的地址;数据e*/
/*输出:是否进队成功;e成为队尾元素*/
Status Enter(SqQuene* Q,ElemType e);

/*数据离开队列*/
/*队列Q的地址;用于接收数据的变量e的地址*/
/*输出:是否出队成功;e获得出队数据的值*/
Status Out(SqQuene* Q,ElemType* e);






