/**
��Ŀ���ݣ�
��д���� add_array �������е�Ԫ����ͣ�����ԭ��Ϊ��
void add_array(int a, int *sum);
�ú��������ظ����ö�Σ�ÿ��ֻʹ�ò���a���������е�һ��Ԫ�أ������ڲ������ۼ����δ����ֵ������ͣ�ÿ��ִ�к���ѵ�ǰ�ĺ�ͨ������sumд���������е�ĳ�������С�
��ʾ��ʹ�þ�̬������

�����ʽ:
һ�����100��Ԫ�ص��������飬��-1Ϊ��β(��ʾ��������������)��

�����ʽ��
����������Ԫ�صĺ�

����������
3 9 27 4 5 -1

���������
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

