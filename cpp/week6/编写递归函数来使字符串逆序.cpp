/**
��д�ݹ麯����ʹ�ַ�������20�֣�
��Ŀ���ݣ�
��д������ʹһ���ַ������������Ҫ������õݹ麯����

�����ʽ:
һ���ַ��������ᳬ��100���ַ������м���ܰ����ո�

�����ʽ��
���ַ���������

����������
Hello,everyone

���������
enoyreve,olleH
**/
#include<iostream>  
#include<string.h>  
using namespace std;  
void rev(char str[], int n);  
void allrev(char str[]);  
int main()  
{  
    char str[100];  
    cin.getline(str, 100);  
    allrev(str);  
    cout << str;  
    system("pause");  
    return 0;  
  
}  
void rev(char &a, char &b)  
{  
    char temp = a;  
    a = b;  
    b = temp;  
}  
  
void allrev(char str[])  
{  
    int length = strlen(str);  
    for (int i = 0; i < length/2; i++)  
    {  
        rev(str[i], str[length - 1 - i]);  
    }  
}  
