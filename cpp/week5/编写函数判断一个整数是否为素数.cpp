/**
��Ŀ���ݣ�
��д����int isprime(int a);�����ж�����a�Ƿ�Ϊ������������������������1�����򷵻�0�����øú����ҳ����������n�������е������� ע�⣬1����������

�����ʽ:
һϵ�д��жϵ����������Կո��������0��ʾ���������

�����ʽ��
ֻ���������������е�������˳�������һ�¡����ݼ���һ��Ӣ�Ŀո���������һ�����ݺ�û�пո񣡣��� ע�⣬1����������

����������
9 8 7 210 101 0 

���������
7 101
ʱ�����ƣ�500ms�ڴ����ƣ�32000kb
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
    if(mark==1) //��������   
        return 1;  
    else if(mark==0)//����������   
        return 0;  
}   
  
  
  
int main() {    
    int a[100];int mark=0;  
    for(int i=0;;i++,mark++){  
        cin>>a[i];  
        if(a[i]==0) break;  
              
    }  
    int c[mark];// ���������������   
    for(int i=0;i<mark;i++){  
        if(isprime(a[i])==1) {  
            c[i]=1;  
  
        }  
              
    }  
    int num=0;//Ѱ����������λ��   
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
