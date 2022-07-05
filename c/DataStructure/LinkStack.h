/*定义状态码*/
typedef int Status;
//内存溢出
#define OVERFLOW 0
//栈空错误
#define NULLERROR -1
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
} Node;

typedef struct LinkStack{
    Node* top; //栈顶指针
    int count;  //结点数
} LinkStack;


/*初始化链栈*/
/*输入:链栈S的头指针的地址*/
/*输出:是否初始化成功;空的链栈S*/
Status InitStack(LinkStack* S);

/*判断链栈是否为空*/
/*输入:链栈L的头指针*/
/*输出:空为TRUE，非空为FALSE*/
BOOL IsStackEmpty(LinkStack S);

/*返回链栈的长度*/
/*输入:链栈L的头指针*/
/*输出:链栈的长度length*/
int StackLength(LinkStack S);

/*置空链栈*/
/*输入:链栈L的头指针的地址*/
/*输出:链栈是否置空成功;空的链栈L*/
Status ClearStack(LinkStack* S);

/*销毁链栈*/
/*输入:链栈L的头指针的地址*/
/*输出:链栈是否销毁成功;未初始化的顺序表L*/
Status DestoryStack(LinkStack* S);

/*数据入栈*/
/*输入:顺序栈S的地址;要入栈的数据项e*/
/*输出:是否入栈成功;e变为栈顶数据*/
Status Push(LinkStack* S,ElemType e);

/*栈顶数据出栈*/
/*输入:顺序栈S的地址;接受栈顶数据的变量e的地址*/
/*输出:是否出栈成功;e被赋值栈顶数据*/
Status Pop(LinkStack* S,ElemType* e);

