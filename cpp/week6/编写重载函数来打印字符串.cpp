/**
题目内容：
编写函数 print_spaced 来打印字符串，要求打印出的字符串每个字母之间都有一个空格。要求编写两个同名函数，一个支持字符数组输入，另一个支持string类型输入。然后编写main函数测试这两个函数，第一个使用字符数组输入，第二个使用string类型输入。

输入格式:
两个字符串，长度不超过100，只包含英文大小写字母，不含其他字符。

输出格式：
经间隔空格处理后的两个字符串，两个字符串分居两行。注意字符串的最后一个字母后面没有空格。

输入样例：
news
final

输出样例：
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














