/**
题目内容：
编写函数 add_array 对数组中的元素求和，函数原型为：
void add_array(int a, int *sum);
该函数可以重复调用多次，每次只使用参数a传入数组中的一个元素，函数内部可以累计历次传入的值进行求和，每次执行后均把当前的和通过参数sum写入主函数中的某个变量中。
提示：使用静态变量。

输入格式:
一个最多100个元素的整型数组，以-1为结尾(表示结束，不是数据)。

输出格式：
该数组所有元素的和

输入样例：
3 9 27 4 5 -1

输出样例：
48

**/
#include<iostream>
using namespace std;
void add_array(int a,int *sum){
    *sum+=a;
}

int main(){
    int a[100];
    int sum = 0;
    for(int i=0;;i++){
        cin>>a[i];
        if(a[i]!=-1){
            add_array(a[i],&sum);
        }else{
            break;
        }
    }
    cout<<sum<<endl;
    return 0;
}

