/*
cstdio���ǽ�stdio.h��������C++��ͷ�ļ���ʽ���ֳ�����
stdio.h����ʽ��C,C++ͷ�ļ���cstdio�Ǳ�׼ C++��STL������cstdio�еĺ������Ƕ�����һ�����ֿռ�std����ģ�
���Ҫ����������ֿռ�ĺ���������ü�std::�������ļ�������use namespace std
*/

#include <cstdio>
using namespace std;
int main()
{
	int m, n;
	int flag = 1;
	//�������������ȷ���һ�����������
	while (scanf_s("%d %d", &m, &n) != EOF) {
		if (n>0) {
			if (flag == 1) {
				printf("%d %d", m*n, n - 1);
				flag = 0;
			}
			else {
				printf(" %d %d", m*n, n - 1);
			}
		}
	}
	/*�����ж������ʽ������˵ֻ������������ϵ�����⣬ָ��Ϊ0*/
	if (flag == 1)
		printf("0 0");

	return 0;
}