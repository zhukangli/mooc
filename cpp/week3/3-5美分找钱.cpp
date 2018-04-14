/**
题目内容：
将n美分转换成25、10、5和1美分的硬币总共有多少种转换方法？
运行结果如下：
25
13
如果n不在0~99之间，输出提示信息“the money is invalid!”
运行结果如下：
101
the money is invalid!
输入格式:
整数，表示美分数
输入可能不是[0,99]之间的整数。输入不在该区间时，输出为“the money is invalid!”。

输出格式：
转换方法数或者提示信息“the money is invalid!”（不带引号啊，单词间只有一个空格）

输入样例：
25

输出样例：
13
时间限制：2000ms内存限制：64000kb
**/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int i,j,k,p;
    int n,count=0;
    cin>>n;
    if(n<0 || n>99)
        cout<<"the money is invalid!"<<endl;
    else
    {
        for(i=0;i<=n/25;i++)
        {
            for(j=0;j<=n/10;j++)
            {
                for(k=0;k<=n/5;k++)
                {
                    for(p=0;p<=n;p++)
                    {
                        if(25*i+10*j+5*k+p==n)
                            count++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
