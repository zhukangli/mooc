#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main() {
	int a, b,sum;
	cin >> a; cin >> b;
	sum = a + b;
	if (abs(sum)<1000) {
		cout<<sum;
	}
	else {
		int nums[7];
		int count = 0;
		int flag = sum >= 0 ? 1 : 0;
		sum = abs(sum);
		for (int i = 0; i < 7;i++) {
			if (sum  >= 1) {
				nums[i] = sum % 10;
				sum = sum / 10;
				++ count;
			}
		}

		vector<string> v;
		for (int j = 0; j <count; j++) {

			if (j > 0 && j % 3 == 0) {
				v.push_back(",");
			}
			string temp = to_string(nums[j]);
			v.push_back(temp);
		}


		if (!flag) {
			cout << "-";
		}
		for (int k = v.size()-1; k >= 0 ;k--) {
			cout << v[k];
		}
		
	

	}
	system("pause");
	return 0;
}