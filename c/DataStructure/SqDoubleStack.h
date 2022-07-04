/*定义状态码*/
typedef int Status;
//内存溢出
#define OVERFLOW 0
//栈空错误
#define NULLERROR -1
//编号错误
#define INPUTERROR -2
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

/*定义SqDoubleStack结构*/
typedef struct SqDoubleStack
{
    ElemType* data; //二顺序栈的储存数组
    int top1;   //栈顶标记1
    int top2;   //栈顶标记2
} SqDoubleStack;

/*初始化二顺序栈*/
/*输入:顺序栈S的地址*/
/*输出:是否初始化成功;空的二顺序栈S*/
Status InitStack(SqDoubleStack *S);

/*判断二顺序栈中某一个栈是否为空*/
/*输入:二顺序栈S;栈编号:1或2*/
/*输出:空为TRUE，非空为FALSE*/
BOOL IsStackEmpty(SqDoubleStack S,int StackNum);

/*返回对应编号的顺序栈的长度*/
/*输入:二顺序栈S;栈编号:1或2*/
/*输出:对应编号栈的长度length*/
int StackLength(SqDoubleStack S,int StackNum);

/*置空对应编号的顺序栈*/
/*输入:二顺序栈S的地址;栈编号:1或2*/
/*输出:顺序栈是否置空成功;空的对应编号的顺序栈*/
Status ClearStack(SqDoubleStack *S,int StackNum);

/*销毁整个二顺序栈*/
/*输入:二顺序栈S的地址;*/
/*输出:顺序栈是否销毁成功;未初始化的顺序栈S*/
Status DestoryStack(SqDoubleStack *S);

/*对应编号的顺序栈的栈顶数据出栈*/
/*输入:顺序栈S的地址;栈编号:1或2;接受栈顶数据的变量e的地址*/
/*输出:是否出栈成功;e被赋值栈顶数据*/
Status Pop(SqDoubleStack* S,int StackNum, ElemType *e);

/*数据入栈*/
/*输入:顺序栈S的地址;要入栈的数据项e*/
/*输出:是否入栈成功;e变为栈顶数据*/
Status Push(SqDoubleStack *S,int StackNum,ElemType e);
