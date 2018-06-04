#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n = 0;
	scanf_s("%d", &n);//这读法是一定只读第一个的
	int nums;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;
	for (int i = 0; i < n;i++) {
		cin >> nums;
		if (nums % 5 == 0 && nums % 2 == 0) {
			v1.push_back(nums);
		}
		if (nums% 5 == 1) {
			v2.push_back(nums);
		}
		if (nums % 5 == 2) {
			v3.push_back(nums);
		}
		if (nums % 5 == 3) {
			v4.push_back(nums);
		}
		if (nums % 5 == 4) {
			v5.push_back(nums);
		}
	}
	if (v1.size() == 0) {
		cout << "N" << " ";
	}
	else {
		int sum = 0;
		for (int i = 0; i <v1.size(); i ++ ) {
			sum += v1[i];
		}
		cout << sum << " ";
	}

	if (v2.size() == 0) {
		cout << "N" << " ";
	}
	else {
		int sum = 0;
		for (int i = 0; i <v2.size(); i++) {
			if (i % 2 == 1) {
				sum -= v2[i];
			}
			else {
				sum += v2[i];
			}
		}
		cout << sum << " ";
	}

	if (v3.size() == 0) {
		cout << "N" << " ";
	}
	else {
		cout << v3.size() << " ";
	}

	if (v4.size() == 0) {
		cout << "N" << " ";
	}
	else {
		int sum = 0;
		for (int i = 0; i <v4.size(); i++) {
			sum += v4[i];
		}
		//cout <<setprecision(1)<< ((double)sum) / v4.size() << " ";
		printf("%.1lf ", (double)sum / v4.size());
	}

	if (v5.size() == 0) {
		cout << "N" ;
	}
	else {
		int max = 0;
		for (int i = 0; i <v5.size(); i++) {
			if (v5[i] > max) {
				max = v5[i];
			}
		}
		cout <<max;
	}


	system("pause");
	return 0;
}