#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool check(int n) {
	int temp = sqrt(n);
	bool flag = true;
	if (temp >= 2) {
		for (int i = 2; i <= temp; i++) {
			if (n % i == 0) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

vector<int> get(vector<int> v) {
	for (int i = 1; i <= 110000; i++) {//��������10^5 ,^��c++ ���������������һֱ��ʱ
		if (check(i)) {
			v.push_back(i);
		}
	}
	return v;
}



int main() {
	int m, n;
	scanf_s("%d %d", &m, &n);
	vector<int> v;
	v = get(v);
	int count = 0;
	for (int i = m; i <= n;i++) {
		++count;
		if (count % 10 == 0 && i != n) {
			cout << v[i] << endl;
		}
		else if (i == n) {
			cout << v[i];
		}
		else {
			cout << v[i] << " ";
		}

	}
	system("pause");
	return 0;
}