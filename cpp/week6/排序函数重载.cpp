/**
���������أ�20�֣�
��Ŀ���ݣ�
��дһ�����ص������������Զ����������������������ĸ���������������Ӵ�С����,������Ϊsort,������������Ӧʹ�õݹ�ķ���������print��������һ����ʾ����������Ԫ�ء�
���������£�
int main()
{
int a,b,c,d;
int data[100];
int k,n,i;
  cin>>k;
  switch(k)
  {
    case 1:
        cin>>a>>b;
        sort(a,b);
        cout<<a<<" "<<b<<endl;
        break;
    case 2:
        cin>>a>>b>>c;
        sort(a,b,c);
        cout<<a<<" "<<b<<" "<<c<<endl;          
        break;      
    case 3:
        cin>>a>>b>>c>>d;
        sort(a,b,c,d);
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        break;  
    case 4:
        cin>>n;
        for(i=0;i<n;i++)
           {
            cin>>data[i];
        } 
        sort(data,n);
        print(data,n);
        break;      
  }
  return 0;
}
�����ʽ:
������������Լ�������
 
�����ʽ��
���������ݣ�һ�У��Ӵ�С��ĩβû�пո�
 
����������
4
10
22 15 20 16 3 27 14 64 108 10
 
���������
108 64 27 22 20 16 15 14 10 3
 
���ύ�������򣬰���������main()
**/
#include<iostream>  
using namespace std;  
  
void sort(int &a, int &b);  
void sort(int &a, int &b, int &c);  
void sort(int &a, int &b, int &c, int &d);  
void sort(int data[], int n);  
  
void print(int data[],int n);  
  
int main()  
{  
    int a, b, c, d;  
    int data[100];  
    int k, n, i;  
    cin >> k;  
    switch (k)  
    {  
    case 1:  
        cin >> a >> b;  
        sort(a, b);  
        cout << a << " " << b << endl;  
        break;  
    case 2:  
        cin >> a >> b >> c;  
        sort(a, b, c);  
        cout << a << " " << b << " " << c << endl;  
        break;  
    case 3:  
        cin >> a >> b >> c >> d;  
        sort(a, b, c, d);  
        cout << a << " " << b << " " << c << " " << d << endl;  
        break;  
    case 4:  
        cin >> n;  
        for (i = 0; i<n; i++)  
        {  
            cin >> data[i];  
        }  
        sort(data, n);  
        print(data, n);  
        break;  
    }  
    system("pause");  
    return 0;  
}  
  
void sort(int &a, int &b)  
{  
    if (a<b)  
    {  
        int temp = a;  
        a = b;  
        b = temp;  
    }  
}  
void sort(int &a, int &b, int &c)  
{  
    sort(a, b);  
    sort(a, c);  
    sort(b, c);  
}  
void sort(int &a, int &b, int &c, int &d)  
{  
    sort(a, b, c);  
    sort(a, d);  
    sort(b, c, d);  
}  
  
void sort(int data[], int n)  
{  
    for (int i = 0; i < n - 1; i++)  
    {  
        for (int j = 0; j < n - 1 - i; j++)  
        {  
            sort(data[j], data[j + 1]);  
        }  
    }  
}  
void print(int data[], int n)  
{  
    for (int i = 0; i < n; i++)  
    {  
        cout << data[i];  
        if (i != n-1)  
        {  
            cout << " ";  
        }  
    }  
}  








