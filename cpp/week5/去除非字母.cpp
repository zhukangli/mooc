/**
��д����ȥ���ַ����а����ķ���ĸ�ַ�(�������ո�)������Сд��ĸת���ɴ�д��ĸ��20�֣�
��Ŀ���ݣ�
��д����ȥ���ַ����а����ķ���ĸ�ַ�(�������ո�)������Сд��ĸת���ɴ�д��ĸ��
ע�⣬���ں�����������������Ӧ���������н��С�

�����ʽ:
��ת�����ַ������ַ����������ո񣬳��Ȳ�����200��

�����ʽ��
ת������ַ���

����������
happy new year!

���������
HAPPY NEW YEAR
ʱ�����ƣ�500ms�ڴ����ƣ�32000kb

**/

#include<iostream>
#include <cstring>
using namespace std;
string delNotChar(char str[]){
    int len=strlen(str);
    int j=0;
    char b[200];
    for(int i=0;i<=len;i++){
        if(str[i]>='a'&&str[i]<='z'){//��Сд��ĸ��ɴ�д��ĸ
            b[j]=str[i]-32;
            j++;
        }else if((str[i]>='A'&&str[i]<='Z')||str[i]==' '){//��д��ĸ�Ϳո���
            b[j]=str[i];
            j++;
        }
    }
    b[j]='\0';//�����ַ������ص�main�������
    return b;
}
int main(){
    char a[200];
    cin.getline(a, 200);
    cout<<delNotChar(a);
    return 0;
}
