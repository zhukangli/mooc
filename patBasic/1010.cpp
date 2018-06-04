/*
cstdio就是将stdio.h的内容用C++的头文件形式表现出来。
stdio.h是老式的C,C++头文件，cstdio是标准 C++（STL），且cstdio中的函数都是定义在一个名字空间std里面的，
如果要调用这个名字空间的函数，必须得加std::或者在文件中声明use namespace std
*/

#include <cstdio>
using namespace std;
int main()
{
	int m, n;
	int flag = 1;
	//两个两个处理，比放在一个数组里面快
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
	/*这里判断零多项式，就是说只输入两个数，系数任意，指数为0*/
	if (flag == 1)
		printf("0 0");

	return 0;
}