/*
��Ŀ��˼���������Ŀ��ţ������ߵĹ��š������˵�id����������ʱ�䣬�ߵ�ʱ�䡣��˭�����ţ�˭�ص���
˼·��
1���Ƚϴ�С��ʱ���ö���������ѭ�����Ƚϸ�ʡ�ռ�
2�����⻹�ǱȽϼ򵥣��ò���map


*/

#include <iostream>
#include <cstdio>
#include <cstring>

int main(void)
{
	//setvbuf��������˼ÿ�������������ʱ�򣬷ŵ���������ȥ����c�ĺ�������cstdio����
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	//m��ʾ����
	int m;
	scanf("%d", &m);
	char id_open[16], id_close[16], t_open[] = "23:59:59", t_close[] = "00:00:00";
	//ע�⣬������char����������ַ���
	char id[16], arrive[9], depart[9];
	for (int i = 0; i < m; i++) {
		scanf("%s %s %s", id, arrive, depart);
		//23��59:59ǰ����
		if (strcmp(t_open, arrive) > 0) {
			//strcpy��id���Ƶ�idOpen��ȥ
			strcpy(id_open, id);
			//t_open = arrive������ȡ����t_open
			strcpy(t_open, arrive);
		}
		//00:00:00ǰ�뿪
		if (strcmp(t_close, depart) < 0) {
			strcpy(id_close, id);
			strcpy(t_close, depart);
		}
	}
	printf("%s %s\n", id_open, id_close);
	return 0;
}