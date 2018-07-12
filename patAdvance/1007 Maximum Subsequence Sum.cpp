/*
������к����⣬֮ǰ��������Ҫ��ϰһ��
��һ������K������������к��Ƕ��٣��Լ�������е��ʼ�����һ�����֣�ȫ�Ǹ��ľͶ���Ϊ0��	
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
		//��Ҫע��һ�����=�ţ���������Ⱥź������˺ö�β���˯��
		if (a[i] >= 0)net = false;
	}
	if (net) {
		cout << 0 << " " << a[0] << " " << a[k - 1];
		return 0;
	}

	//����maxSumһ��ҪΪ-1����Ҫȥ�ж�ȫ�������
	//���maxSum = 0���жϲ��� -1 0 -1�������
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
