#include<iostream>
#include<string>
using namespace std;

int main() {
	string s[100];
	for (int i = 0; i < 100;i++) {
		cin >> s[i];
	}
	for (int i = 99; i > 0;i--) {
		if (!s[i].empty()) {
			cout << s[i] << " ";
		}
	}
	cout << s[0];


}