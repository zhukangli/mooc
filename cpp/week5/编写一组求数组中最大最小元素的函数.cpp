/**
��Ŀ���ݣ�
��дһ���������������СԪ�صĺ��������麯����ԭ��Ϊ
int imax(int array[], int count); // ��������������Ԫ��
int imin(int array[], int count); // �������������СԪ��
���в���countΪ�����е�Ԫ�ظ����������ķ���ֵ��Ϊ��õ�������СԪ��ֵ֮��Ҫ��ͬʱ��д��������������֤��

�����ʽ:
��һ����Ϊ����Ԫ�صĸ�����1-100��������Ϊ��������Ԫ�ء�

�����ʽ��
�������������һ��Ϊ���ֵ���ڶ���Ϊ��Сֵ

����������
5
90 89 30 45 55

���������
90
30
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
