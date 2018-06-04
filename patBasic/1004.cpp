#include <iostream>
#include <cstring>
using namespace std;


int main() {
	int n;
	cin >> n;
	string name, no;
	int score;
	string maxName, maxNo;
	int maxScore = 0;
	string minName, minNo;
	int minScore = 100;
	for (int i = 0; i < n;i++) {
		cin >> name >> no >> score;
		if (score > maxScore) {
			maxScore = score;
			maxName = name;
			maxNo = no;
		}
		if (score < minScore) {
			minScore = score;
			minName = name;
			minNo = no;
		}
	}
	cout << maxName << " " << maxNo<<endl;
	cout << minName << " " << minNo;


}