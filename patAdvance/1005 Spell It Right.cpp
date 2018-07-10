#include<iostream>
using namespace std;

/*
数字的各位和相加
Sample Input:
12345
Sample Output:
one five      即1+2+3+4+5=15

难点：
1：取得数字的各个位置
2：相加
3：数字向英文的转换
思路：
1：利用数组来进行翻译，而不用if else
2：字符串读入，直接就相加了
这题还是比较容易理解的
*/


#include <iostream>

using namespace std;

int main()
{
	char* numToEnglish[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char tempNum;
	int sum = 0;
	int firstFlag = 1;
	int oneDigitFlag = 1; // !!! format error
	char* res[105];
	int numOfDigits = 0;

	scanf_s("%c", &tempNum);//把数字当做字符一个个读进来
	//这里很巧妙，一下子就把和求出来了
	while (tempNum != '\n') {
		sum += tempNum - '0';//与字符0的差就为实际的数值
		scanf_s("%c", &tempNum);
	}

	if (sum == 0) {
		//和是0直接打印出来
		printf("%s", numToEnglish[0]);
	}
	else {
		//不是0，把和的每位存到res数组中
		while (sum != 0) {
			res[numOfDigits++] = numToEnglish[sum % 10];
			sum /= 10;
		}
		//从res数组中读出每一位就可以了
		while (numOfDigits--) {
			oneDigitFlag = 0;
			if (firstFlag) {
				printf("%s", res[numOfDigits]);
				firstFlag = 0;
			}
			else {
				printf(" %s", res[numOfDigits]);
			}
		}
	}
	system("pause");
}
