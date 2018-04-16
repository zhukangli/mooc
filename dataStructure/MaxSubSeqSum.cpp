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
	//为什么cin慢？这里不用cin，用什么好？ 
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
		thisSum = 0;//这里置0，表示一轮循环已经找出最大子列了，可以下一轮循环再找了 
		//理解这个循环很关键 
		for(j=i;j<k;j++)
		{
			thisSum += a[j];//累加 
			if(thisSum > maxSum){
				first = a[i];
				last = a[j];
				maxSum = thisSum;//这里就是取出最大子列了 
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
