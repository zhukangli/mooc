/*
1002 写出这个数 (20)（20 分）
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100^。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
**/

#include <iostream>
using namespace std;

void int_pinyin(int a) {
	switch (a) {
	case 0:cout << "ling"; break;
	case 1:cout << "yi"; break;
	case 2:cout << "er"; break;
	case 3:cout << "san"; break;
	case 4:cout << "si"; break;
	case 5:cout << "wu"; break;
	case 6:cout << "liu"; break;
	case 7:cout << "qi"; break;
	case 8:cout << "ba"; break;
	case 9:cout << "jiu"; break;
	}
}


int main() {
	char a[101];
	cin >> a;
	int sum = 0, i = 0;
	while (a[i] != '\0') {
		sum += a[i] - '0';
		++i;
	}
	if (sum == 0) {
		int_pinyin(0);
		return 0;
	}
	int b[11], j = 0;
	while(sum != 0){
		b[j] = sum % 10;
		sum = sum / 10;
		++j;
	}

	for (int i = j - 1; i > 0; i--) {
		int_pinyin(b[i]);
		cout << " ";
	}
	int_pinyin(b[0]);
	return 0;
}