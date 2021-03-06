/**
编写函数计算一个英文句子中的单词个数（20分）
题目内容：
编写函数计算一个英文字符串中的单词个数。

输入格式:
一个最长500个字母的英文字符串,不包含数字和特殊字符，但可能包含一些英文标点符号（逗号、句点、问号）。标点符号独立出现时不视为一个单词。 单词间可能包含一个或多个空格。

输出格式：
该句子的单词个数

输入样例：
We hope everyone watches them with warmth.

输出样例：
7
时间限制：500ms内存限制：32000kb
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
