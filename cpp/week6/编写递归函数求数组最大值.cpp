/**
编写递归函数求数组最大值（20分）
题目内容：
编写函数求一个数组中数组元素的最大值，要求必须用递归方法解决。

输入格式:
数组中的数字均为整型数，输入的第一个数为数组长度，后续为数组的所有元素。

输出格式：
该数组的最大值

输入样例：
5
92 18 77 6 15 

输出样例：
92
**/

#include<iostream>  
using namespace std;  
int max(int array[],int n)  
{  
    if (n<=1)  
        return(array[0]);            //   就一个数，最大值就是自已  
    int   t=max(array,n-1);   //  求后面 n-1个数的最大值  
    if (t>array[n-1])                    //    t 比第n个大，返回最大 t   
        return(t);  
    else  
        return(array[n-1]);        //   t小，返回第n个，array[n-1];  
}  
int main()  
{  
  
    int a[10],n;  
    cin>>n;  
    for(int i = 0;i < n;i++)  
        cin>>a[i];  
    cout<<max(a,n)<<endl;  
    return 0;  
} 


