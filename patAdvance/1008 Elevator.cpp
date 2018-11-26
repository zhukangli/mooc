/*
这题意思：电梯上行1层要6s，下行要4s，然后停留的话是5s
	给定一个顺序，计算总时间

难点：
没什么难点
*/

#include<cstdio>
int main()
{
	int stay=0,t;
	int N,i,total=0;
	scanf("%d",&N);
	for(i=0;i<N;++i)
	{
		scanf("%d",&t);
		if(t==stay)
		{
			total+=5;
			continue;
			
		}
		if(t>stay)
			total+=(t-stay)*6+5;
		else
			total+=(stay-t)*4+5;
		stay=t;
	}
	printf("%d",total);
	return 0;
} 
