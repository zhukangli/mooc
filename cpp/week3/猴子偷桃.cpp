/**
题目内容：
有一天，某只猴子摘了一些桃子，当时吃了一半，又不过瘾，于是就多吃了一个。以后每天如此，到第n天想吃时，发现就只剩下一个桃子。输入n，表示到第n天剩下1个桃子，请计算第一天猴子摘的桃子数。
程序运行结果如下：
10
1534

输入格式:
输入一个整数n,n>0，表示到第n天剩下1个桃子。

输出格式：
一个整数，表示第1天摘的桃子数。

输入样例：
10

输出样例：
1534
时间限制：2000ms内存限制：32000kb

**/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n; 
	cin>>n;
	int sum = 1 ;
	for(int i=1;i<n;i++){
		sum = (sum +1)*2;
	}
	cout<<sum;
	return 0;
	 

	
 }
