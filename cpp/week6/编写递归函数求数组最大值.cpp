/**
��д�ݹ麯�����������ֵ��20�֣�
��Ŀ���ݣ�
��д������һ������������Ԫ�ص����ֵ��Ҫ������õݹ鷽�������

�����ʽ:
�����е����־�Ϊ������������ĵ�һ����Ϊ���鳤�ȣ�����Ϊ���������Ԫ�ء�

�����ʽ��
����������ֵ

����������
5
92 18 77 6 15 

���������
92
**/

#include<iostream>  
using namespace std;  
int max(int array[],int n)  
{  
    if (n<=1)  
        return(array[0]);            //   ��һ���������ֵ��������  
    int   t=max(array,n-1);   //  ����� n-1���������ֵ  
    if (t>array[n-1])                    //    t �ȵ�n���󣬷������ t   
        return(t);  
    else  
        return(array[n-1]);        //   tС�����ص�n����array[n-1];  
}  
int main()  
{  
  
    int a[10],n;  
    cin>>n;  
    for(int i = 0;i < n;i++)  
        cin>>a[i];  
    cout<<max(a,n)<<endl;  
    return 0;  
} 


