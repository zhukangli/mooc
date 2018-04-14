/**
题目内容：
编写字符串反转函数mystrrev，该函数的功能是将指定字符串中的字符顺序颠倒（前变后，后变前）。然后再编写主函数验证之。注意，输入输出应在主函数中进行。
函数原型为 void mystrrev(char str[]) 
输入格式:
一个字符串，不会超过100个字符长，中间可能包含空格

输出格式：
输入字符串的反转后的字符串

输入样例：
Hello,everyone

输出样例：
enoyreve,olleH
时间限制：500ms内存限制：32000kb
**/


#include<iostream>
using namespace std;
void mystrtev(char str[])
{
    int i;
    int len=0;
    while(str[i]!='\0'){
        len++;//统计字符串的长度
        i=i+1;    
    }
    //cout<<"该字符串的长度为"<<len<<endl;
    //进行顺序颠倒的思想是将字符串整体后移，然后往前移动
    for(i=0;i<len;i++)//整体后移
    {
        str[2*(len-1)-i]=str[i];
    }
     for(i=len-1;i<=2*(len-1);i++)//往前平移
    {
         str[i-(len-1)]=str[i];    
    }
    for(i=0;i<len;i++){
        cout<<str[i];
    }

 }
 int main()
 {
     const int N=101;
     char a[N];
     //cout<<"请输入字符串：";
     cin.getline(a,N);//输入也是对的
     //cout<<"反转后的字符串为："<<endl;
     mystrtev(a);
     cout<<endl;
  } 






