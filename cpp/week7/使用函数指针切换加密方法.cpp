/**
ʹ�ú���ָ���л����ܷ���
��Ŀ���ݣ�
��д�������ܺ�������һ������ʹ�ÿ������ܷ���������ԭ����Сд��ĸ����ĸ���������ĵ�3����ĸ�Ĵ�д��ʽ���滻����д��ĸ��ͬ��������Сд��ĸ�滻��
�ɽ���ĸ��������ĩ�νӵġ�����"AMDxyzXYZ" ����Ϊ "dpgABCabc"���ڶ�������ʹ�õ�˫�ż��ܷ��������ַ���"abcde",���ݵ�˫������Ϊ�����ַ���"ace"��"bd"��
��������һ���Ϊ����"acebd"��
�û�����һ���ַ�����Ϊ���ģ�����������1��2������1ʹ�õ�һ���������ܲ�������ģ�����2ʹ�õڶ����������ܲ�������ġ�Ҫ��ʹ�ú���ָ�����л����ܺ�����

��ʾ������������ԭ�Ϳ���Ϊ��
void caesar(char s[]);
void oddeven(char s[]);
void cipher(void (*f)(char s[]),char s[]);//�β�Ϊָ������ָ�룬��Ӧʵ�ο�Ϊ��Ӧ��ʽ�ĺ�������


�����ʽ:
һ���ַ�����Ϊ���ģ�����������1��2������1ʹ�õ�һ���������ܲ�������ģ�����2ʹ�õڶ����������ܲ�������ġ�

�����ʽ��
���ܺ������

����������
jacky
2

���������
jcyak
**/


#include<iostream>  
#include<string.h>  
  
using namespace std;  
static int length;  
  
void caesar(char s[])  
{     
    for (int i = 0; i < length; i++)  
    {  
        if (s[i]<='Z' && s[i]>='A')  
        {  
            s[i] = (s[i] - 'A' + 3) % 26 + 'a';  
        }  
        else  
        {  
            s[i] = (s[i] - 'a' + 3) % 26 + 'A';  
        }  
    }  
}  
  
void oddeven(char s[])  
{  
    char s1[100],s2[100];  
    int num_1 =0, num_2 =0;  
    for (int i = 0; i < length; i++)  
    {  
        if (i%2==0)  
        {  
            s1[num_1] = s[i];  
            num_1++;  
        }  
        else  
        {  
            s2[num_2] = s[i];  
            num_2++;  
        }  
    }  
      
  
    for (int i = 0; i < num_1; i++)  
    {  
        s[i] = s1[i];  
    }  
  
    for (int i = 0; i < num_2; i++)  
    {  
        s[i+num_1] = s2[i];  
    }  
}  
void cipher(void(*f)(char s[]), char s[])  
{  
    (*f)(s);  
}  
  
int main()  
{  
    void(*f)(char s[]);  
    char s[100];  
    int choice = 1;  
    cin.getline(s, 100);  
    cin >> choice;  
    length = strlen(s);  
  
    if (choice == 1)  
        f = caesar;  
    else  
        f = oddeven;  
    //����ָ�� 
    cipher(f, s);  
    cout << s;  
    system("pause");  
    return 0;  
}  







