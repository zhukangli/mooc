#include<iostream>
//����
#include<set>
#include<vector>
#include<list>
#include<string>
#include<sstream>
#include<map>
//�㷨
#include<algorithm>
//������
#include<iterator>
//�º���
#include<functional>
//������
#include<stack>
#include<queue>
//������
#include<allocators>
/*
����ֻ��˳��ѧϰһ��stl
����������Ľ�����ϵ��
container�������� ͨ�� allocator���������� ȡ�����ݴ���ռ䣬
algorithm���㷨��ͨ�� iterator������������ȡ container�������� ���ݣ�
functor���º����� ����Э�� algorithm���㷨�� ��ɲ�ͬ�Ĳ��Ա仯��
adapter��������� �������λ��׽� functor���º�������
*/

using namespace std;

/*
Polynomials������ʽ
����Ķ���ʽ���

���⻹�ǱȽϼ�
˼·:
1������һ���㹻������飬��ϵ��Ϊ����λ��i��ֵΪa[i],
2��Ȼ����ͬλ�õ���ӾͿ�����
3����Ҫ�����
ע�⣺
����Ҫ�����������飬�����ʱ��ֱ����Ӽ���



*/
int main() {
	float a[1001];
	int i, k;
	float temp;
	// ��ʼ������
	for (i = 0; i <= 1000; i++) {
		a[i] = 0.0f;
	}
	// �ֱ�������������ʽ
	scanf("%d", &k);
	while (k--) {
		scanf("%d%f", &i, &temp);
		a[i] += temp;
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d%f", &i, &temp);
		a[i] += temp;
	}
	// �жϵ�ǰ����ʽ������
	k = 0;
	for (i = 0; i <= 1000; i++) {
		if (a[i] != 0.0) {
			k++;
		}
	}
	printf("%d", k);
	// ����Ϊ0��ֻ���k���Ҳ����ո�
	if (k != 0)
		printf(" ");
	for (i = 1000; i >= 0; i--) {
		if (a[i] != 0.0) {
			printf("%d ", i);
			printf("%0.1f", a[i]);
			k--;
			// ������һ��󲻴��ո�
			if (k != 0)
				printf(" ");
		}
	}
	return 0;
}
