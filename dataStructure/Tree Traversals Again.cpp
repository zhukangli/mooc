#include <cstdio>
#include <cstring>
#include <cstdlib>

#define STR_LEN 5
#define MAX_SIZE 30

typedef struct Node
{
    int data;
    struct Node *left, *right;
}* treeNode;

treeNode Stack[MAX_SIZE];
int values[MAX_SIZE];

int num = 0;
int top = -1;

void Push(treeNode tn);
treeNode Pop();
treeNode Top();
bool isEmpty();

void PostOrderTraversal(treeNode root);

int main()
{
    int n;
    char operation[STR_LEN];
    treeNode father, root;
    bool findRoot = 0, Poped = 0;

    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%s", operation);
        if (strcmp(operation, "Push") == 0)
        {
            int value;
            scanf("%d", &value);
            treeNode newNode;
            newNode = (treeNode)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            if (!findRoot)
            {
                root = newNode;     //根节点
                Push(newNode);
                findRoot = 1;
            }
            else
            {
                if (!Poped)     //如果前一个操作不是pop，则父节点为栈顶元素
                    father = Top();
                if (father->left == NULL)
                    father->left = newNode;
                else
                    father->right = newNode;
                //printf("%d\n", newNode->data);
                Push(newNode);
            }
            Poped = 0;
        }
        else
        {
            father = Pop();
            Poped = 1;
        }
    }
    PostOrderTraversal(root);

    for (int i = 0; i < num-1; i++)
        printf("%d ", values[i]);
    printf("%d\n", values[num-1]);

    return 0;
}

void PostOrderTraversal(treeNode root)
{
    treeNode tn = root;
    if(tn)
    {
        PostOrderTraversal(tn->left);
        PostOrderTraversal(tn->right);
        values[num++] = tn->data;       //将后序遍历出的节点值存入数组便于格式化打印
    }
}

void Push(treeNode tn)
{
    Stack[++top] = tn;
}

treeNode Pop()
{
    return Stack[top--];
}

bool isEmpty()
{
    return top == -1;
}

treeNode Top()
{
    return Stack[top];
}


/**
https://pintia.cn/problem-sets/951072707007700992/problems/975887458772324352
03-树3 Tree Traversals Again（25 分）
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:

3 4 2 6 5 1

**/







