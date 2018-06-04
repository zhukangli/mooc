/*
1003 我要通过！(20)（20 分）
“答案正确”是自动判题系统给出的最令人欢喜的回复。
本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；\
	1.任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；\
	2.如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 
每个测试输入包含1个测试用例。第1行给出一个自然数n (&lt10)，是需要检测的字符串个数。
接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。


解题思路:
首先对三个要求进行分析
1:字符串中只能有P,A,T三种字符，扫一遍来判断一下就好了，若不符合条件直接输出NO。
2:xPATx是正确的，x代表空串或者全是A字母的串，注意到前后x是一样的，所以APATA是对的而AAPATA是错误的。
	只要在第一次扫描数组的时候记录下P和T的位置，然后判断总长度len−Tindexlen是否等于Pindex就可以了。
3:对比两个字符串，可知后者与前者相差中间的大A和最后的小a，实际上可以理解成要去掉一个中间的大A则需要同时去掉后边的小a，
	这里A指一个字符，而a指的是在PP前边的字符串。

*/

#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int num;
	cin >> num;
	int countP = 0, countA = 0, countT = 0;
	for (int i = 0; i < num;i++) {
		char c[100];
		cin >> c;
		int posT = 0, posP = 0;
		for (int k = 0; k < 100;k++) {
			if (c[k] == 'P') {
				countP++;
				posP = k;
			}
			else if (c[k] == 'A') {
				countA ++;
			}
			else if (c[k] == 'T') {
				countT++;
				posT = k;
			}
			
		}
		if (countP > 1 || countP > 1 || countP == 0|| countT ==0  ||
			 strlen(c)+ 1 - posP != posT  //xPATx,说明对称，可知posP + posT = 长度 + 1
			){//如果 aPbTc 是正确的，那么 aPbATca 也是正确的; 中间加个A，尾巴就要加a
			cout << "NO" << endl;
		}else {
			cout << "YES" << endl;

		}
		
	}
}
	
