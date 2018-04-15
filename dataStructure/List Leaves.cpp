/**
03-��2 List Leaves��25 �֣�
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (��10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N?1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

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
    int root;       //��¼�ڵ��Ƿ��Ǹ��ڵ�  
    int left;  
    int right;  
};  
int main() {  
//  freopen("test.txt", "r", stdin);  
    int n;  
    struct Node nodes[10];  
    scanf("%d", &n);  
    for (int i = 0; i < n; ++i) {        //��ʼ�����ڵ�  
        nodes[i].root = 1;              //û���ӵĽڵ㶼�Ǹ��ڵ�  
        nodes[i].left = -1;             //û���ӵĽڵ����Ҷ��Ӷ�Ϊ��  
        nodes[i].right = -1;  
    }  
    for (int i = 0; i < n; ++i) {        //������  
        char ch1, ch2;  
        scanf("\n%c %c", &ch1, &ch2);  
        if (isdigit(ch1)) {             //�������Ӵ��ڣ���������������ýڵ�  
            nodes[i].left = ch1 - '0';  //ָ��ָ�������  
            nodes[ch1 - '0'].root = 0;  //�����ȡ�����ڵ���  
        }  
        if (isdigit(ch2)) {  
            nodes[i].right = ch2 - '0';  
            nodes[ch2 - '0'].root = 0;  
        }  
    }  
    int root;  
    for (int i = 0; i < n; ++i)          //�ҵ�����  
        if (nodes[i].root == 1) {  
            root = i;  
            break;  
        }  
    //���������󣬲�����������������Ҷ�ڵ㣻����������̣��Ӹ��ڵ㿪ʼ���ν����Ҷ�����ӣ�ֱ������Ϊ��  
    int leaves = 0;         //��¼���Ҷ�ڵ�������������ʱ��һ���ڵ����ǰû�пո�  
    int queue[10];          //�ڵ���У�ֻ����ڵ��±�  
    int head = 0, rear = 0;  
    queue[rear++] = root;   //���ڵ����  
    while (rear - head) {  
        int node = queue[head++];       //���׽ڵ����  
        if (nodes[node].left == -1 && nodes[node].right == -1) {    //���Ҷ�ڵ�  
            if (leaves)  
                printf(" ");  
            printf("%d", node);  
            ++leaves;  
        }  
        if (nodes[node].left != -1) {       //������ڣ���������  
            queue[rear++] = nodes[node].left;  
        }  
        if (nodes[node].right != -1) {      //������ڣ��Ҷ������  
            queue[rear++] = nodes[node].right;  
        }  
    }  
    return 0;  
}  
