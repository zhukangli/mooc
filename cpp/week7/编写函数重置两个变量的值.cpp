/**
��д������������������ֵ
��Ŀ���ݣ�
��д������������������ֵ���ú�����ԭ��Ϊ  void reset(int *a, int *b);
�����ڲ�������ֵ����Ϊ��������ԭֵ��ƽ����(����С������������)��

�����ʽ:
���������õ�ֵ

�����ʽ��
���ú������ֵ

����������
7 14

���������
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
