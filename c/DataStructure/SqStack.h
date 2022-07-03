/*定义状态码*/
typedef int Status;
//内存溢出
#define OVERFLOW 0
//数据未查找到
#define NOTFOUND -1
//栈空错误
#define NULLERROR -2
//操作成功
#define OK 1

/*定义bool数*/
typedef int BOOL;
#define FALSE 0
#define TRUE 1

/*定义顺序栈的初始大小*/
#define MAXSIZE 20

/*定义数据项的类型*/
typedef int ElemType;

/*定义SqStack结构*/
typedef struct SqStack
{
    ElemType* data; //顺序栈的储存数组
    int top;                //栈顶标记
} SqStack;

/*初始化顺序栈*/
/*输入:顺序栈S的地址*/
/*输出:是否初始化成功;空的顺序栈S*/
Status InitStack(SqStack *S);

/*判断顺序栈是否为空*/
/*输入:顺序栈S*/
/*输出:空为TRUE，非空为FALSE*/
BOOL IsStackEmpty(SqStack S);

/*返回顺序栈的长度*/
/*输入:顺序栈S*/
/*输出:顺序栈的长度length*/
int StackLength(SqStack S);

/*置空顺序栈*/
/*输入:顺序栈S(数组名)*/
/*输出:顺序栈是否置空成功;空的顺序栈S*/
Status ClearStack(SqStack *S);

/*销毁顺序栈*/
/*输入:顺序栈S(数组名)*/
/*输出:顺序栈是否销毁成功;未初始化的顺序栈S*/
Status DestoryStack(SqStack *S);

/*栈顶数据出栈*/
/*输入:顺序栈S的地址;接受栈顶数据的变量e的地址*/
/*输出:是否出栈成功;e被赋值栈顶数据*/
Status Pop(SqStack* S, ElemType *e);

/*数据入栈*/
/*输入:顺序栈S的地址;要入栈的数据项e*/
/*输出:是否入栈成功;e变为栈顶数据*/
Status Push(SqStack *S,ElemType e);
