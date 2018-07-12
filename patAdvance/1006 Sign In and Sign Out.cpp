/*
题目意思：最早来的开门，最晚走的关门。给出人的id，和他来的时间，走的时间。问谁开的门，谁关的门
思路：
1：比较大小的时候不用都存起来，循环来比较更省空间
2：这题还是比较简单，用不着map


*/

#include <iostream>
#include <cstdio>
#include <cstring>

int main(void)
{
	//setvbuf函数的意思每次输入输出流的时候，放到缓冲区中去，是c的函数，在cstdio里面
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	//m表示人数
	int m;
	scanf("%d", &m);
	char id_open[16], id_close[16], t_open[] = "23:59:59", t_close[] = "00:00:00";
	//注意，这里用char数组来存的字符串
	char id[16], arrive[9], depart[9];
	for (int i = 0; i < m; i++) {
		scanf("%s %s %s", id, arrive, depart);
		//23：59:59前到达
		if (strcmp(t_open, arrive) > 0) {
			//strcpy把id复制到idOpen中去
			strcpy(id_open, id);
			//t_open = arrive，就是取最大的t_open
			strcpy(t_open, arrive);
		}
		//00:00:00前离开
		if (strcmp(t_close, depart) < 0) {
			strcpy(id_close, id);
			strcpy(t_close, depart);
		}
	}
	printf("%s %s\n", id_open, id_close);
	return 0;
}