/**
题目内容：
编写一组求数组中最大最小元素的函数。该组函数的原型为
int imax(int array[], int count); // 求整型数组的最大元素
int imin(int array[], int count); // 求整型数组的最小元素
其中参数count为数组中的元素个数，函数的返回值即为求得的最大或最小元素之值。要求同时编写出主函数进行验证。

输入格式:
第一个数为数组元素的个数（1-100），后面为所有数组元素。

输出格式：
分两行输出，第一行为最大值，第二行为最小值

输入样例：
5
90 89 30 45 55

输出样例：
90
30
时间限制：500ms内存限制：32000kb
**/
#include<iostream>
using namespace std;
int imax(int array[],int count){
    int max = array[0];
    for(int i=1;i<count;i++)
    {
        if(array[i]>max){
            max = array[i];
        }
    }
    return max;
} 
int imin(int array[],int count){
    int min = array[0];
    for(int i=1;i<count;i++)
    {
        if(array[i]<min){
            min = array[i];
        }
    }
    return min;
} 
int main(){
    int count;
    int a[100];
    cin>>count;
    for(int i=0;i<count;i++)
    {
        cin>>a[i];
    }
    int max = imax(a,count);
    int min = imin(a,count);
    cout<<max<<endl;
    cout<<min<<endl;
    return 0;
}
