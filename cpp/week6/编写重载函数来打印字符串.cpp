/**
��Ŀ���ݣ�
��д���� print_spaced ����ӡ�ַ�����Ҫ���ӡ�����ַ���ÿ����ĸ֮�䶼��һ���ո�Ҫ���д����ͬ��������һ��֧���ַ��������룬��һ��֧��string�������롣Ȼ���дmain����������������������һ��ʹ���ַ��������룬�ڶ���ʹ��string�������롣

�����ʽ:
�����ַ��������Ȳ�����100��ֻ����Ӣ�Ĵ�Сд��ĸ�����������ַ���

�����ʽ��
������ո����������ַ����������ַ����־����С�ע���ַ��������һ����ĸ����û�пո�

����������
news
final

���������
n e w s
f i n a l

**/
#include<iostream>  
#include<string>   
#include<string.h>   
  
using namespace std;  
void print_spaced(char str[]);  
void print_spaced(string & str);  
  
int main()  
{  
    char str[100];  
    cin.getline(str,100);  
    string str2;  
    getline(cin, str2);  
  
    print_spaced(str2);  
    print_spaced(str);  
  
    cout << str << endl;  
    cout << str2;  
    system("pause");  
    return 0;  
}  
  
void print_spaced(char str[])  
{  
    int length = strlen(str);  
    char temp[100];  
    for (int i = 0; i < length; i++)  
    {  
        temp[i] = str[i];  
    }  
  
    int j = 0;  
    for (int i = 0; i < length; i++)  
    {  
        str[j] = temp[i];  
        j++;  
        if (i != length - 1)  
        {  
            str[j] = 32;  
            j++;  
        }  
    }  
    str[j] = 0;  
}  
  
void print_spaced(string & str)  
{  
    int length = str.length();  
    string temp;  
    for (int i = 0; i < length; i++)  
    {  
        temp = temp + str[i];  
        if (i != length - 1)  
        {  
            temp = temp + " ";  
        }  
    }  
    str = temp;  
}  














