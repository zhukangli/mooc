/**
题目内容：
编写函数int isprime(int a);用来判断整数a是否为素数，若是素数，函数返回1，否则返回0。调用该函数找出任意给定的n个整数中的素数。 注意，1不是素数。

输入格式:
一系列待判断的正整数，以空格隔开，以0表示输入结束。

输出格式：
只输出输入的正整数中的素数，顺序和输入一致。数据间以一个英文空格隔开，最后一个数据后没有空格！！！ 注意，1不是素数。

输入样例：
9 8 7 210 101 0 

输出样例：
7 101
时间限制：500ms内存限制：32000kb
**/

#include <iostream>   
#include <cstring>  
using namespace std;    
#include <cmath>  
int isprime(int a){  
    int mark=1;  
    if(a==1)  {  
        mark=0;  
      
    }  
    for(int i=2;i<=a/2;i++){  
        if(a%i==0) {  
            mark=0;break;   
        }  
    }   
    if(mark==1) //是素数；   
        return 1;  
    else if(mark==0)//不是素数；   
        return 0;  
}   
  
  
  
int main() {    
    int a[100];int mark=0;  
    for(int i=0;;i++,mark++){  
        cin>>a[i];  
        if(a[i]==0) break;  
              
    }  
    int c[mark];// 标记数组是素数的   
    for(int i=0;i<mark;i++){  
        if(isprime(a[i])==1) {  
            c[i]=1;  
  
        }  
              
    }  
    int num=0;//寻找最后的素数位置   
    for(int i=0;i<mark;i++){  
        if(c[i]==1)   
        num=i;  
    }   
  
    for(int i=0;i<mark;i++){  
        if(c[i]==1){  
        cout<<a[i];  
        if(i!=num){  
            cout<<" ";  
        }  
                      
        }  
          
    }  
      
}   
