/**
��Ŀ���ݣ�
��д����ѧ��������ƽ��ֵ��ͨ�ú��������Լ������ָ�������ں�����ƽ��ֵ(ȡ������)��
��������ƽ��ֵ������������ԭ��Ϊ��
int  func1(int x);
int  func2(int x)
ֻ���ǲ���Ϊ������������ɡ�
func1����ѧ���ʽΪ��y=a*x^2+b*x+c��a,b,c���û����룻
func2����ѧ���ʽΪ��y=x^m��m���û����룻
ͨ�ú����Ĳ���Ϊ��������ƽ��ֵ������ָ�룬�Լ������������½����Ͻ硣
���� func1 = 3*x^2+2*x+1, �����½����Ͻ�ֱ�Ϊ0��3����
func1(0)=1
func1(1)=6
func1(2)=17
func1(3)=34
��ƽ��ֵΪ����1+6+17+34��/4=14 ��ֱ��ȡ������������)
��ʾ����1�����ں���ԭ�͵����ƣ�a,b,c��m��������ʹ��ȫ�ֱ������ݡ�
��2��ͨ�ú���ԭ�Ϳ���Ϊ��int avg( int (*f)(int),int x1,int x2);


�����ʽ:
�û��������룺
func1�Ĳ��� a,b,c
func2�Ĳ��� m
�����������½����Ͻ�

�����ʽ��
func1��������ƽ��ֵ
func2��������ƽ��ֵ

����������
3 2 1
1
0 3

���������
14
1
**/

#include<iostream>  
using namespace std;  
int a, b, c, m;  
#include<math.h>  
int func1(int x)  
{  
    return( a*x*x + b*x + c);  
}  
  
int func2(int x)  
{  
    return(int(pow(x,m)));  
}  

//����ָ�룬�����ʵ����̫����� 
int avg(int(*f)(int x), int x1, int x2)  
{  
    int sum = 0;  
    for (int i = x1; i <= x2; i++)  
    {  
        sum = (*f)(i)+sum;  
    }  
    return int(sum / (x2 - x1 + 1));  
}  
int main()  
{  
    int up=0 , down=0;  
    cin >> a >> b >> c;  
    cin >> m;  
    cin >> down >> up;  
    cout << avg(func1, down, up) << endl;  
    cout << avg(func2, down, up);  
    system("pause");  
    return 0;  
} 













