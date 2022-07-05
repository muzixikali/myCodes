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

/*定义结点结构*/
typedef struct Node{
    ElemType data;
    struct Node* next;
} Node;

/*定义链队结构*/
typedef struct LinkQuene{
    Node* font; //队头指针
    Node* rear; //队尾指针
    int count;  //结点数
}LinkQuene;

/*初始化*/
/*输入:链队Q的地址*/
/*输出:是否初始化成功;空的链队Q*/
Status InitQuene(LinkQuene* S);

/*返回队列长度*/
/*输入:队列Q*/
/*输出:队列长度*/
int QueneLength(LinkQuene Q);

/*判断队列是否为空*/
/*输入:队列Q*/
/*输出:空为TRUE，非空为FALSE*/
BOOL IsQueneEmpty(LinkQuene Q);

/*置空队列*/
/*输入:队列Q的地址*/
/*输出:队列是否置空成功;空的队列Q*/
Status ClearQuene(LinkQuene* Q);

/*销毁队列*/
/*输入:队列Q的地址*/
/*输出:队列是否销毁成功;未初始化的队列Q*/
Status DestoryQuene(LinkQuene* Q);

/*数据进入队列*/
/*队列Q的地址;数据e*/
/*输出:是否进队成功;e成为队尾元素*/
Status Enter(LinkQuene* Q,ElemType e);

/*数据离开队列*/
/*队列Q的地址;用于接收数据的变量e的地址*/
/*输出:是否出队成功;e获得出队数据的值*/
Status Out(LinkQuene* Q,ElemType* e);




