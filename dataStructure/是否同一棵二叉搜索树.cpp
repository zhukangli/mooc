/**
04-树4 是否同一棵二叉搜索树（25 分）
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:

输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:

对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:

4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:

Yes
No
No

**/

//建一颗树，判别其他序列是否与其一致 
#include <stdio.h>
#include <stdlib.h>

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct TreeNode *Tree;
struct TreeNode
{
    ElemType data;
    Tree left,right;
    int flag;    //被访问过为1 否则0 
}; 

Tree NewNode(ElemType data);
Tree Insert(Tree T,ElemType data);
Tree MakeTree(int N);
bool check (Tree T,ElemType data);
int Judge(Tree T,int N);
void ResetT(Tree T);
void FreeTree(Tree T);

Tree NewNode(ElemType data)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->data = data;
    T->left = T->right = NULL;
    T->flag = 0;
    return T;
}

Tree Insert(Tree T,ElemType data)
{
    if( !T )
        T = NewNode(data);
    else {
        if(data > T->data)
            T->right = Insert(T->right, data);
        else
            T->left = Insert(T->left, data);
    }
    return T;
}

Tree MakeTree(int N)
{
    Tree T;
    ElemType data;
    scanf("%d",&data);
    T = NewNode(data);
    for(int i = 1; i < N; i++) {
        scanf("%d",&data);
        T = Insert(T,data);
    }
    return T;
}

bool check (Tree T,ElemType data)
{
    if(T->flag) {
        if(data < T->data)
            return check(T->left,data);
        else if(data > T->data)
            return check(T->right,data);
    }else {
        if(data == T->data) {    //是要找的结点 
            T->flag = 1;
            return true;
        }
        else return false;            //不是 不一致 
    }
}

int Judge(Tree T,int N)
{
    ElemType data;
    int flag = 0;//0代表目前仍一致 1代表已经不一致
    scanf("%d",&data);
    if(data != T->data)    //    判断根节点是否一致 
        flag = 1; 
    else T->flag = 1;
    for(int i = 1; i < N; i++) {    //确保L读完 
        scanf("%d",&data);
        if( (!flag) && (!check(T,data)) )    //不一致 
            flag = 1;
    }
    if(flag)     //不一致 
        return 0;
    else return 1;
}

void ResetT(Tree T)//清除T中各结点的flag标记
{
    if(T->left)
        ResetT(T->left);
    if(T->right)
        ResetT(T->right);
    T->flag = 0;
} 

void FreeTree(Tree T) //释放T的空间
{
    if(T->left)
        FreeTree(T->left);
    if(T->right)
        FreeTree(T->right);
    free(T);
} 

int main()
{
    int N, L;
    Tree T;
    scanf("%d",&N);
    while(N) {
        scanf("%d",&L);
        T = MakeTree(N);
        for(int i = 0; i < L; i++) {
            if(Judge(T, N))
                printf("Yes\n");
            else
                printf("No\n");
            ResetT(T);        //清除T中的标记flag 
        } 
        FreeTree(T);
        scanf("%d",&N);
    }
    
    return 0;
}
