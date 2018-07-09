/*
数叶子节点的个数

题目意思：
N是节点个数，M是非叶子节点的个数
下面是M行，每行表明一个非叶子节点
问的是树的每层有多少个叶子节点
Sample Input
2 1
01 1 02
Sample Output
0 1


难点：
1：根据输入建立一颗树
2：树的层次遍历，来数叶子节点的个数（用队列）
思路：
1：这里没有建立一个树，而是用一个二维数组，x维度为父节点，y为其儿子，巧妙
2：这里也没有用真正的队列，而是用一个数组来代替了队列，巧妙，值得学习
关键还是思路得清晰，思路不清晰是做不出来的

*/


#include <iostream>
using namespace std;
int node[100][100] = { 0 };//记住这个二维数组的初始化方式
int arra[100];
int main()
{
	int N, M, ID, K;
	cin >> N >> M;
	int i = 0;
	while (i<M)
	{
		cin >> ID >> K;
		int j = 0;
		while (j<K)
		{
			cin >> node[ID][j];//把ID的k个子节点全部存在node这个二维数组中
			j++;
		}
		i++;
	}
	arra[0] = 1;//题目说了根节点就是1，那队列arr中，一开始就只有一个元素1
	int first = 1;
	int front = 0, rear = 1;//队列头位置为0，尾巴为1
	while (front<rear)//头<尾，即队列中始终有元素
	{
		int tag = rear;
		int cnt = 0;

		while (front<tag)//这里用tag这个临时值，很明显，因为要入队，头指针，尾指针要变化，避免这个while条件变化
		{
			int i = 0;
			if (node[arra[front]][0] == 0)cnt++;//如果队列arr中元素没有子元素了，就cnt++
			else
			{//否则，有子元素就把子元素放到队尾去
				while (node[arra[front]][i])
				{
					arra[rear++] = node[arra[front]][i];
					i++;
				}
			}
			//头指针后移
			front++;
		}
		if (first)first = 0;
		else cout << " ";
		cout << cnt;
	}
	cout << endl;
	return 0;
}
