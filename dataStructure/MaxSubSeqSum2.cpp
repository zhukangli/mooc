/**
这个要求以分治的方法来处理，T（N）=O（NlgN） 

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
	int i,j;
	for(i =0;i<k;i++)
	{
		thisSum = 0;
		for(j=i;j<k;j++)
		{
			thisSum += a[j];
			if(thisSum > maxSum){
				maxSum = thisSum;
			}
		}
		
	}
	cout<<maxSum;
	return 0;
}
