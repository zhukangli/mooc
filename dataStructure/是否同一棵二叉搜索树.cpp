/**
04-��4 �Ƿ�ͬһ�ö�����������25 �֣�
����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������

�����ʽ:

�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L����Ҫ�������С�

����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����

�����ʽ:

��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����

��������:

4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
�������:

Yes
No
No

**/

//��һ�������б����������Ƿ�����һ�� 
#include <stdio.h>
#include <stdlib.h>

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct TreeNode *Tree;
struct TreeNode
{
    ElemType data;
    Tree left,right;
    int flag;    //�����ʹ�Ϊ1 ����0 
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
        if(data == T->data) {    //��Ҫ�ҵĽ�� 
            T->flag = 1;
            return true;
        }
        else return false;            //���� ��һ�� 
    }
}

int Judge(Tree T,int N)
{
    ElemType data;
    int flag = 0;//0����Ŀǰ��һ�� 1�����Ѿ���һ��
    scanf("%d",&data);
    if(data != T->data)    //    �жϸ��ڵ��Ƿ�һ�� 
        flag = 1; 
    else T->flag = 1;
    for(int i = 1; i < N; i++) {    //ȷ��L���� 
        scanf("%d",&data);
        if( (!flag) && (!check(T,data)) )    //��һ�� 
            flag = 1;
    }
    if(flag)     //��һ�� 
        return 0;
    else return 1;
}

void ResetT(Tree T)//���T�и�����flag���
{
    if(T->left)
        ResetT(T->left);
    if(T->right)
        ResetT(T->right);
    T->flag = 0;
} 

void FreeTree(Tree T) //�ͷ�T�Ŀռ�
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
            ResetT(T);        //���T�еı��flag 
        } 
        FreeTree(T);
        scanf("%d",&N);
    }
    
    return 0;
}
