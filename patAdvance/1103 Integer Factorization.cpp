/*
题目：A1103 Integer Factoriztion 整数因数分解
把N用K个正整数的P次方之和来表示（N<=400, K<=N, 1<P<=7）
例如：169 = 12^2 + 4^2 + 2^2 + 2^2 + 1^2
多个解时，取K个数的和最大的，和相等时，取字典序大的
输入样例：
169 5 2
输出样例：
169=6^2+6^2+6^2+6^2+5^2

我的思路：
1）可以把小于根号N的数全部列举出来，把他们的平方用数组存起来
	169 就取13。即fac[0]=0,fac[1]=1,fac[2]=4......fac[12]=144,fac[13]=169
2)问题转换为从fac数组里面选5个数，相加等于N
	DFS的思想，选或者不选，然后去递归。递归时候需要计算当前的已选数字nowOK，当前总和sum，当前要选的序号index(可重复),
	因为多个数取底数和最大的，那就还要算底数和facSum,字典序不记录，直接从后向前遍历，就能得到最大的字典序
3）函数应该是DFS(index,nowOK,sum,facSum);
4）边界应该是sum = N && nowOK = K

*/
#include <iostream> 
#include <vector>
using namespace std;
int n,k,p;
int maxSum = -1;
vector<int> fac;
vector<int> ans;//最优解的数组
vector<int> temp;//临时数组

//x的p次方
int power(int x) {
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans *= x;
	}
	return ans;
}

//预处理fac数组
void init() {
	int temp = 0,i=0;
	while (temp <= n) {
		fac.push_back(temp);
		temp = power(++i);
	}
}

//index是fac的下标
//nowK是当前K的数量
//sum是当前的平方和
//fanSum是当前index的和
void DFS(int index,int nowK,int sum,int facSum) {
	//边界
	if (sum == n && nowK == k) {
		if (facSum > maxSum) {//虽然找到边界，也要取最优解
			maxSum = facSum;
			ans = temp;
		}
		return;
	}
	if (sum > n || nowK > k) {
		return;
	}
	//递归
	//选中自己
	if (index >= 1) {//0不用选，没有意义
		temp.push_back(index);//先选中自己，再去DFS，注意顺序
		DFS(index, nowK + 1, sum + fac[index], facSum + index);
		
		//不选中自己，即退回上一级
		temp.pop_back();
		DFS(index - 1, nowK, sum, facSum);
		
	}
}


int main(){	
	scanf_s("%d%d%d",&n,&k,&p);
	init();//fac初始化
	DFS(fac.size() - 1,0,0,0);
	if (maxSum == -1) {
		printf("Impossible\n");
	}
	else {
		printf("%d=%d^%d",n,ans[0],p);
		for (int i = 1; i < ans.size();i++) {
			printf("+%d^%d", ans[i], p);
		}
	}
	system("pause");
	return 0;
}
