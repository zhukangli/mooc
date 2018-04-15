/**
03-树2 List Leaves（25 分）
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N?1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:

8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:

4 1 5
**/

#include <stdio.h>  
#include <ctype.h>  
struct Node {  
    int root;       //记录节点是否是根节点  
    int left;  
    int right;  
};  
int main() {  
//  freopen("test.txt", "r", stdin);  
    int n;  
    struct Node nodes[10];  
    scanf("%d", &n);  
    for (int i = 0; i < n; ++i) {        //初始化树节点  
        nodes[i].root = 1;              //没连接的节点都是根节点  
        nodes[i].left = -1;             //没连接的节点左右儿子都为空  
        nodes[i].right = -1;  
    }  
    for (int i = 0; i < n; ++i) {        //构造树  
        char ch1, ch2;  
        scanf("\n%c %c", &ch1, &ch2);  
        if (isdigit(ch1)) {             //如果左儿子存在，将左儿子连接至该节点  
            nodes[i].left = ch1 - '0';  //指针指向左儿子  
            nodes[ch1 - '0'].root = 0;  //左儿子取消根节点标记  
        }  
        if (isdigit(ch2)) {  
            nodes[i].right = ch2 - '0';  
            nodes[ch2 - '0'].root = 0;  
        }  
    }  
    int root;  
    for (int i = 0; i < n; ++i)          //找到树根  
        if (nodes[i].root == 1) {  
            root = i;  
            break;  
        }  
    //构造完树后，层序遍历树，依次输出叶节点；层序遍历过程：从根节点开始依次将左右儿子入队，直到队列为空  
    int leaves = 0;         //记录输出叶节点个数，方便输出时第一个节点输出前没有空格  
    int queue[10];          //节点队列，只保存节点下标  
    int head = 0, rear = 0;  
    queue[rear++] = root;   //根节点入队  
    while (rear - head) {  
        int node = queue[head++];       //队首节点出队  
        if (nodes[node].left == -1 && nodes[node].right == -1) {    //输出叶节点  
            if (leaves)  
                printf(" ");  
            printf("%d", node);  
            ++leaves;  
        }  
        if (nodes[node].left != -1) {       //如果存在，左儿子入队  
            queue[rear++] = nodes[node].left;  
        }  
        if (nodes[node].right != -1) {      //如果存在，右儿子入队  
            queue[rear++] = nodes[node].right;  
        }  
    }  
    return 0;  
}  
