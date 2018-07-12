/*
最大子列和问题，之前做过，需要复习一下
给一个序列K个，求最大子列和是多少？以及这个序列的最开始和最后一个数字（全是负的就定义为0）	
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4

*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int k;
	int a[100000];
	cin >> k;
	bool net = true;
	for (int i = 0; i<k; i++) {
		cin >> a[i];
		//还要注意一下这个=号，就是这个等号害的试了好多次不能睡觉
		if (a[i] >= 0)net = false;
	}
	if (net) {
		cout << 0 << " " << a[0] << " " << a[k - 1];
		return 0;
	}

	//这里maxSum一定要为-1，且要去判断全负的情况
	//如果maxSum = 0，判断不出 -1 0 -1这种情况
	int thisSum = 0, maxSum = -1;
	int begin = a[0], end = a[k - 1];
	int i, j;
	for (i = 0; i<k; i++)
	{
		thisSum = 0;
		for (j = i; j<k; j++)
		{
			thisSum += a[j];
			if (thisSum > maxSum) {
				begin = a[i];
				end = a[j];
				maxSum = thisSum;
			}
		}

	}
	cout << maxSum <<" "<< begin <<" " << end;
	return 0;
}
