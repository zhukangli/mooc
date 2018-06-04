#include<iostream>
#include<vector>
using namespace std;

void get(int n, vector<int> &a) {
	while (n != 0) {
		a.push_back(n % 10);
		n = n / 10;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	get(n,v);
	for (int i = v.size(); i > 0;i--) {
		if ( i == 3) {
			for (int j = 0; j < v[2]; j++) {
				cout << 'B';
			}
		}
		if (i == 2) {
			for (int j = 0; j < v[1]; j++) {
				cout << 'S';
			}
		}
		if (i == 1) {
			for (int j = 1; j <= v[0] ; j++) {
				cout << j;
			}
		}
	}

	system("pause");

}