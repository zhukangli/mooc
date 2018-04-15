/**
编写函数重置两个变量的值
题目内容：
编写函数重置两个变量的值，该函数的原型为  void reset(int *a, int *b);
函数内部将两个值重置为两个变量原值的平均数(出现小数则四舍五入)。

输入格式:
两个待重置的值

输出格式：
重置后的两个值

输入样例：
7 14

输出样例：
11 11

**/
#include<iostream>
#include<cmath>
using namespace std;

void reset(int *a, int *b){
	int c = (*a + *b);
	if(c % 2 ==1){
		*a = (c+ 1)/2;
	}else{
		*a =c/2;
	}
	

	*b = *a;
}

int main(){
	int a,b;
	cin>>a;
	cin>>b;
	reset(&a,&b);
	cout<<a<<" "<<b;
	
}
