/**
��Ŀ���ݣ�
��n����ת����25��10��5��1���ֵ�Ӳ���ܹ��ж�����ת��������
���н�����£�
25
13
���n����0~99֮�䣬�����ʾ��Ϣ��the money is invalid!��
���н�����£�
101
the money is invalid!
�����ʽ:
��������ʾ������
������ܲ���[0,99]֮������������벻�ڸ�����ʱ�����Ϊ��the money is invalid!����

�����ʽ��
ת��������������ʾ��Ϣ��the money is invalid!�����������Ű������ʼ�ֻ��һ���ո�

����������
25

���������
13
ʱ�����ƣ�2000ms�ڴ����ƣ�64000kb
**/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int i,j,k,p;
    int n,count=0;
    cin>>n;
    if(n<0 || n>99)
        cout<<"the money is invalid!"<<endl;
    else
    {
        for(i=0;i<=n/25;i++)
        {
            for(j=0;j<=n/10;j++)
            {
                for(k=0;k<=n/5;k++)
                {
                    for(p=0;p<=n;p++)
                    {
                        if(25*i+10*j+5*k+p==n)
                            count++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
