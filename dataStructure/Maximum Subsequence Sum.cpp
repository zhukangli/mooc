/*
01-复杂度2 Maximum Subsequence Sum（25 分）
Given a sequence of K integers { N1, N2, ..., NK}. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj} where 1≤i≤j≤K. 
The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example,
 given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:

10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:

10 1 4
*/
/**
这个要求不仅仅计算出最大子列和，还要求知道子列第一个和最后一个数值 
  如果子列和不唯一，要求打出最小的i,j
  如果序列中的值全部为负数，最大子列和定义为0，打出第一个和最后一个数值即可 
**/ 
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int k;
	int a[100000];
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	
	
	int thisSum,maxSum=0;
	int first=0;
	int last=0; 
	int i,j;
	for(i =0;i<k;i++)
	{
		thisSum = 0;
		for(j=i;j<k;j++)
		{
			thisSum += a[j];
			if(thisSum > maxSum){
				first = a[i];
				last = a[j];
				maxSum = thisSum;
			}
		}
		
	}
	bool flag = false;
	for(i =0;i<k;i++){
		if(a[i]>=0){
			flag = true;
			break;
		}
	}
	if(!flag){
		cout<<0<<" "<<a[0]<<" "<<a[k-1];
		return 0; 
	}
	
	
	cout<<maxSum<<" "<<first<<" "<<last;
	return 0;
}
