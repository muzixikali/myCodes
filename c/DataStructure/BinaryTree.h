//二叉树的最大节点数数
#define MAXISIZE 100

//操作状态码
typedef int Status;
#define OK 1
#define OVERFLOW 0

//二叉树的元素类型
typedef char ElemType;

//二叉树结点结构
typedef struct Node{
    ElemType data;  //数据域
    struct Node* leftChild; //左子树
    struct Node* rightChild;  //右子树
}Node,*BinaryTree;

//前序创建树，空用'#'表示
Status PreCreateTree(BinaryTree* T);
//中序创建树，空用'#'表示
Status InCreateTree(BinaryTree* T);
//后序创建树，空用'#'表示
Status PostCreateTree(BinaryTree* T);

//前序遍历树
Status PreTraverse(BinaryTree T);
//中序遍历树
Status InTraverse(BinaryTree T);
//后序遍历树
Status PostTraverse(BinaryTree T);




