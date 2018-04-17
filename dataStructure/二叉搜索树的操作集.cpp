/**
做这题要明白，什么是二叉搜索树
就是：
      左子数的值< 根节点 < 右子数的值 
 
**/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); //先序遍历，由裁判实现，细节不表
void InorderTraversal( BinTree BT );  //中序遍历，由裁判实现，细节不表
BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

//BST是一个指针，指向TNode 
BinTree Insert(BinTree BST, ElementType X) {  
    //!BST 表示BST不存在 
    if (!BST) {  
       //创建一个TNode节点，malloc函数返回地址 
        BST = (BinTree)malloc(sizeof(struct TNode));  
        //给该节点赋值为X，即X就为根节点 
        BST->Data = X;  
        BST->Left = NULL;  
        BST->Right = NULL;  
    }  
    else if (X < BST->Data)  
        // X比根节点小的时候，递归往根节点左边插入，好好理解下这个递归 
        BST->Left = Insert(BST->Left, X);  
    else if (X > BST->Data)  
         //X比根节点大的时候，递归往根节点右边插入 
        BST->Right = Insert(BST->Right, X);  
    return BST;  
}  
  
  
BinTree Delete(BinTree BST, ElementType X) {  
    Position Tmp;  
    //BST为空，表示没有找到X来进行删除 
    if (!BST) {  
        printf("Not Found\n");  
    }  
    else if (X < BST->Data)  
        //X 比根节点小，往左子树找 
        BST->Left = Delete(BST->Left, X);  
    else if (X > BST->Data)  
         //X 比根节点大，往右子树找 
        BST->Right = Delete(BST->Right, X);  
    else {//这里表示找到X的位置了  
         //X所在位置，存在左子数和右子树 
        if (BST->Left && BST->Right) {  
            //这里不太好理解          
            Tmp = FindMax(BST->Left);  
            BST->Data = Tmp->Data;  
            BST->Left= Delete(BST->Left, Tmp->Data);  
        }  
        else {  
             //x所在位置，只存在左子节点，或者只存在右子节点，或者X本身为叶子节点 
            Tmp = BST;  
            if (!BST->Left)  
               //左节点不存在，把X所在节点直接用右子节点代替 
                BST = BST->Right;  
            else  
                //右子节点不存在，把x所在节点直接用左子节点代替 
                BST = BST->Left;  
            //把X的内存free掉 
            free(Tmp);  
        }  
    }  
    return BST;  
}  
  
Position Find(BinTree BST, ElementType X) { 
    //这里比较容易理解，就是不停遍历 
    while (BST && (X != BST->Data)) {  
        if (X < BST->Data)  
            BST = BST->Left;  
        else  
            BST = BST->Right;  
    }  
    //明显，这里找不到会返回null 
    return BST;  
}  
  
Position FindMin(BinTree BST) {  
    //一直往左找 
    if (BST) {  
        while (BST->Left)  
            BST = BST->Left;  
    }  
    return BST;  
}  
  
Position FindMax(BinTree BST) {  
    //一直往右找 
    if (BST) {  
        while (BST->Right)  
            BST = BST->Right;  
    }  
    return BST;  
}  


int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    //这里用scanf代替了cin ，建一些数据，构造二叉搜索树 
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    //树中找最大，最小值 
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    //树中查找特定的值 
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    //删除树中特定的值 
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}




/**
04-树7 二叉搜索树的操作集（30 分）
本题要求实现给定二叉搜索树的5种常用操作。

函数接口定义：

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );
其中BinTree结构定义如下：

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
函数FindMin返回二叉搜索树BST中最小元结点的指针；
函数FindMax返回二叉搜索树BST中最大元结点的指针。
裁判测试程序样例：

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); //先序遍历，由裁判实现，细节不表
void InorderTraversal( BinTree BT );  //中序遍历，由裁判实现，细节不表

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 
输入样例：

10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3
输出样例：

Preorder: 5 2 1 0 4 8 6 7 10 9
6 is found
3 is not found
10 is found
10 is the largest key
0 is found
0 is the smallest key
5 is found
Not Found
Inorder: 1 2 4 6 8 9



**/
