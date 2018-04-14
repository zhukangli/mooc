/**
题目内容：
现有n块砖，要由n人一次搬完，假定男人一次可以搬4块，女人一次可以搬3块，两个小孩搬1块，计算这n人中男人、女人和小孩的人数。输入人数和砖数n，输出可能的解决方案。
程序运行结果如下：
50
men0
women10
children40
men5
women3
children42
如果没有满足的情况，显示提示信息“no result!”
程序运行结果如下：
1
no result!
输入格式:
表示人数的整型数

输出格式：
所有满足条件的男人、女人和孩子的人数或者提示信息“no result!”
输出格式见样例。有多组方案时，按男人数量从少到多的顺序输出。男人数量相同时，女人数量从少到多。

输入样例：
50

输出样例：
men0
women10
children40
men5
women3
children42

时间限制：2000ms内存限制：32000kb
**/ 

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int men,women,children;
    int n;
    int x,y,z;
    cin>>n;
    for(men=0;men<=n/4;men++)
    {
        for(women=0;women<=n/3;women++)
        {
            children=2*(n-4*men-3*women);
            if(children>0&&children==n-men-women)
            {
                x=men;y=women;z=children;
                cout<<"men"<<men<<endl;
                cout<<"women"<<women<<endl;
                cout<<"children"<<children<<endl;
            }

        }
    }
    if(x==0||y==0||z==0)
        cout<<"no result!"<<endl;
return 0;
}
