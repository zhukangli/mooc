/*
��Ҷ�ӽڵ�ĸ���

��Ŀ��˼��
N�ǽڵ������M�Ƿ�Ҷ�ӽڵ�ĸ���
������M�У�ÿ�б���һ����Ҷ�ӽڵ�
�ʵ�������ÿ���ж��ٸ�Ҷ�ӽڵ�
Sample Input
2 1
01 1 02
Sample Output
0 1


�ѵ㣺
1���������뽨��һ����
2�����Ĳ�α���������Ҷ�ӽڵ�ĸ������ö��У�
˼·��
1������û�н���һ������������һ����ά���飬xά��Ϊ���ڵ㣬yΪ����ӣ�����
2������Ҳû���������Ķ��У�������һ�������������˶��У����ֵ��ѧϰ
�ؼ�����˼·��������˼·������������������

*/


#include <iostream>
using namespace std;
int node[100][100] = { 0 };//��ס�����ά����ĳ�ʼ����ʽ
int arra[100];
int main()
{
	int N, M, ID, K;
	cin >> N >> M;
	int i = 0;
	while (i<M)
	{
		cin >> ID >> K;
		int j = 0;
		while (j<K)
		{
			cin >> node[ID][j];//��ID��k���ӽڵ�ȫ������node�����ά������
			j++;
		}
		i++;
	}
	arra[0] = 1;//��Ŀ˵�˸��ڵ����1���Ƕ���arr�У�һ��ʼ��ֻ��һ��Ԫ��1
	int first = 1;
	int front = 0, rear = 1;//����ͷλ��Ϊ0��β��Ϊ1
	while (front<rear)//ͷ<β����������ʼ����Ԫ��
	{
		int tag = rear;
		int cnt = 0;

		while (front<tag)//������tag�����ʱֵ�������ԣ���ΪҪ��ӣ�ͷָ�룬βָ��Ҫ�仯���������while�����仯
		{
			int i = 0;
			if (node[arra[front]][0] == 0)cnt++;//�������arr��Ԫ��û����Ԫ���ˣ���cnt++
			else
			{//��������Ԫ�ؾͰ���Ԫ�طŵ���βȥ
				while (node[arra[front]][i])
				{
					arra[rear++] = node[arra[front]][i];
					i++;
				}
			}
			//ͷָ�����
			front++;
		}
		if (first)first = 0;
		else cout << " ";
		cout << cnt;
	}
	cout << endl;
	return 0;
}
