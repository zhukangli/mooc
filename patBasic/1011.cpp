#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		long a = 0, b = 0, c = 0;
		scanf_s("%ld %ld %ld", &a, &b, &c);//long 类型是ld，long long类型是lld
		if ( a +b>c) {
			v.push_back(1);
		}
		else {
			v.push_back(0);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("Case #%d: %s\n",i+1,v[i]==1?"true":"false");
	}
	system("pause");
	


}