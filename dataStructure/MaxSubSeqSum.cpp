/**
���Ҫ�󲻽��������������кͣ���Ҫ��֪�����е�һ�������һ����ֵ 
  ������кͲ�Ψһ��Ҫ������С��i,j
  ��������е�ֵȫ��Ϊ������������кͶ���Ϊ0�������һ�������һ����ֵ���� 
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
