/**
��д��������һ��Ӣ�ľ����еĵ��ʸ�����20�֣�
��Ŀ���ݣ�
��д��������һ��Ӣ���ַ����еĵ��ʸ�����

�����ʽ:
һ���500����ĸ��Ӣ���ַ���,���������ֺ������ַ��������ܰ���һЩӢ�ı����ţ����š���㡢�ʺţ��������Ŷ�������ʱ����Ϊһ�����ʡ� ���ʼ���ܰ���һ�������ո�

�����ʽ��
�þ��ӵĵ��ʸ���

����������
We hope everyone watches them with warmth.

���������
7
ʱ�����ƣ�500ms�ڴ����ƣ�32000kb
**/

#include<iostream>  
#include<string.h>  
using namespace std;  
int main()  
{  
    char str1[500];  
    cin.getline(str1, 500);  
    int length = strlen(str1);  
    int num_word = 1;  
    for (int i = 0; i < length-1; i++)  
    {  
        int flag1 = (str1[i] == 32);  
        int flag2 = ((str1[i + 1] <= 90) && (str1[i + 1] >= 65)) || ((str1[i + 1] <= 122) && (str1[i + 1] >= 97));  
        if ((flag1 == 1) && (flag2 == 1))  
        {  
            num_word++;  
        }  
    }  
    cout << num_word;  
    system("pause");  
    return 0;  
} 
