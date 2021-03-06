/**
编写函数去除字符串中包含的非字母字符(不包括空格)，并将小写字母转换成大写字母（20分）
题目内容：
编写函数去除字符串中包含的非字母字符(不包括空格)，并将小写字母转换成大写字母。
注意，不在函数中输出。输入输出应在主函数中进行。

输入格式:
待转换的字符串，字符串间会包含空格，长度不超过200。

输出格式：
转换后的字符串

输入样例：
happy new year!

输出样例：
HAPPY NEW YEAR
时间限制：500ms内存限制：32000kb

**/

#include<iostream>
#include <cstring>
using namespace std;
string delNotChar(char str[]){
    int len=strlen(str);
    int j=0;
    char b[200];
    for(int i=0;i<=len;i++){
        if(str[i]>='a'&&str[i]<='z'){//将小写字母变成大写字母
            b[j]=str[i]-32;
            j++;
        }else if((str[i]>='A'&&str[i]<='Z')||str[i]==' '){//大写字母和空格保留
            b[j]=str[i];
            j++;
        }
    }
    b[j]='\0';//构成字符串返回到main函数输出
    return b;
}
int main(){
    char a[200];
    cin.getline(a, 200);
    cout<<delNotChar(a);
    return 0;
}
