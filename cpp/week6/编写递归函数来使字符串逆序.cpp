/**
编写递归函数来使字符串逆序（20分）
题目内容：
编写函数来使一个字符串逆序输出，要求必须用递归函数。

输入格式:
一个字符串，不会超过100个字符长，中间可能包含空格

输出格式：
该字符串的逆序

输入样例：
Hello,everyone

输出样例：
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
