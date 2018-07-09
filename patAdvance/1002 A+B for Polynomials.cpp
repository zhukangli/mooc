#include<iostream>
//容器
#include<set>
#include<vector>
#include<list>
#include<string>
#include<sstream>
#include<map>
//算法
#include<algorithm>
//迭代器
#include<iterator>
//仿函数
#include<functional>
//适配器
#include<stack>
#include<queue>
//分配器
#include<allocators>
/*
这里只是顺便学习一下stl
这六大组件的交互关系：
container（容器） 通过 allocator（配置器） 取得数据储存空间，
algorithm（算法）通过 iterator（迭代器）存取 container（容器） 内容，
functor（仿函数） 可以协助 algorithm（算法） 完成不同的策略变化，
adapter（配接器） 可以修饰或套接 functor（仿函数）。
*/

using namespace std;

/*
Polynomials：多项式
经典的多项式相加

这题还是比较简单
思路:
1、建立一个足够大的数组，以系数为数组位置i，值为a[i],
2、然后相同位置的相加就可以了
3、按要求输出
注意：
不需要建立两个数组，读入的时候直接相加即可



*/
int main() {
	float a[1001];
	int i, k;
	float temp;
	// 初始化数组
	for (i = 0; i <= 1000; i++) {
		a[i] = 0.0f;
	}
	// 分别输入两个多项式
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
	// 判断当前多项式的项数
	k = 0;
	for (i = 0; i <= 1000; i++) {
		if (a[i] != 0.0) {
			k++;
		}
	}
	printf("%d", k);
	// 项数为0则只输出k，且不带空格
	if (k != 0)
		printf(" ");
	for (i = 1000; i >= 0; i--) {
		if (a[i] != 0.0) {
			printf("%d ", i);
			printf("%0.1f", a[i]);
			k--;
			// 输出最后一项后不带空格
			if (k != 0)
				printf(" ");
		}
	}
	return 0;
}
