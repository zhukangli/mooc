#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	//找出所有素数
	vector<int> v;
	for (int i = 1; i <= n;i++) {
		int factor = sqrt(i);
		if(factor == 1){
			v.push_back(i);
		}
		else {
			bool flag = true;
			for (int j = 2; j <= factor;j++) {
				if (i % j == 0) {
					flag = false;
				}
			}
			if (flag)v.push_back(i);
		}
	}
	int count = 0;
	for (int i = 0; i < v.size()-1;i++) {
		if (v[i+1] - v[i] == 2) {
			++ count;
		}
	}
	cout << count;


	system("pause");

}