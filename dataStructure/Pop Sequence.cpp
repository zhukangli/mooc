/**
02-线性结构4 Pop Sequence（25 分）
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:

5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:

YES
NO
NO
YES
NO

**/

#include<iostream>  
#include<stack>  
using namespace std;  
  
int main()  
{  
    int M,N,K;  
//  freopen("C:\\Users\\Jimko\\Desktop\\cin.txt","r",stdin);  
    cin>>M>>N>>K;  
    for(int i=0;i<K;i++){  
        stack<int> s;  
        bool flag = true;  
        int t=1;  
        for(int j=0;j<N;j++){        //测试数据逐个输入   
            int num;  
            cin>>num;       
            if(flag){  
                while(s.empty() || s.top() != num){  
                    s.push(t);  
                    if(s.size()>M){  
                        flag = false;  
                        break;  
                    }  
                    t++;            //有序进栈   
                }  
                if(flag && s.size()>=1 && s.top()==num)      //出栈条件   
                    s.pop();  
            }  
        }  
        if(flag)  
            printf("YES\n");  
        else  
            printf("NO\n");  
    }   
    return 0;  
}  
