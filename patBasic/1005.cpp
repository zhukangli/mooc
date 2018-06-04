/*

1005 ����(3n+1)���� (25)��25 �֣�
������(Callatz)�����Ѿ���1001�и������������������Ŀ������΢��Щ���ӡ�

��������֤�����Ȳ����ʱ��Ϊ�˱����ظ����㣬���Լ�¼�µ��ƹ�����������ÿһ�����������n=3������֤��ʱ��
������Ҫ����3��5��8��4��2��1�������Ƕ�n=5��8��4��2������֤��ʱ�򣬾Ϳ���ֱ���ж������Ȳ������α��������Ҫ�ظ����㣬
��Ϊ��4�����Ѿ�����֤3��ʱ���������ˣ����ǳ�5��8��4��2�Ǳ�3�����ǡ����������ǳ�һ�������е�ĳ����nΪ���ؼ�������
���n���ܱ������е��������������ǡ�

���ڸ���һϵ�д���֤�����֣�����ֻ��Ҫ��֤���еļ����ؼ������Ϳ��Բ������ظ���֤���µ����֡������������ҳ���Щ�ؼ����֣�
�����Ӵ�С��˳��������ǡ�

*/


#include <iostream>
#include <cstring>
#include <set>
#include <vector>  
#include <algorithm>//�ṩsort�������Ͳ����Լ�ȥд������
using namespace std;

void find(int n, set<int>& st) {
	while (n != 1) {
		if (n % 2 == 0) {
			n = n / 2;
			st.insert(n);
		}
		else {
			n = (3 * n + 1) / 2;
			st.insert(n);
		}
		
	}

}

int main() {
	int n;
	cin >> n;
	int a[100];
	set<int> st;
	for (int i = 0; i < n;i++) {
		cin >> a[i];
		find(a[i],st);
	}
	vector<int> ans;
	for (int j = 0; j < n;j++) {
		if (st.find(a[j]) == st.end()) {
			ans.push_back(a[j]);
		}
	}

	sort(ans.begin(), ans.end(), greater<int>());
	for (int i = 0; i<ans.size() - 1; i++)
	{
		cout << ans[i] << " ";
	}
	cout << ans[ans.size() - 1];
	return 0;


}