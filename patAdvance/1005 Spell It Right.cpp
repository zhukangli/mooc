#include<iostream>
using namespace std;

/*
���ֵĸ�λ�����
Sample Input:
12345
Sample Output:
one five      ��1+2+3+4+5=15

�ѵ㣺
1��ȡ�����ֵĸ���λ��
2�����
3��������Ӣ�ĵ�ת��
˼·��
1���������������з��룬������if else
2���ַ������룬ֱ�Ӿ������
���⻹�ǱȽ���������
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

	scanf_s("%c", &tempNum);//�����ֵ����ַ�һ����������
	//��������һ���ӾͰѺ��������
	while (tempNum != '\n') {
		sum += tempNum - '0';//���ַ�0�Ĳ��Ϊʵ�ʵ���ֵ
		scanf_s("%c", &tempNum);
	}

	if (sum == 0) {
		//����0ֱ�Ӵ�ӡ����
		printf("%s", numToEnglish[0]);
	}
	else {
		//����0���Ѻ͵�ÿλ�浽res������
		while (sum != 0) {
			res[numOfDigits++] = numToEnglish[sum % 10];
			sum /= 10;
		}
		//��res�����ж���ÿһλ�Ϳ�����
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
