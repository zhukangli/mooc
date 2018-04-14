#include<iostream>
#include<cmath>
using namespace std;
int MaxSubSeqSum2(int A[],int N)
{
	int thisSum,maxSum=0;
	int i,j;
	for(i =0;i<N;i++)
	{
		thisSum = 0;
		for(j=i;j<N;j++)
		{
			thisSum += A[j];
			if(thisSum > maxSum){
				maxSum = thisSum;
			}
		}
		
	}
	return maxSum;
}
int main()
{
	int k;
	int a[100000];
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	cout<<MaxSubSeqSum2(a,k);
	return 0;
}


