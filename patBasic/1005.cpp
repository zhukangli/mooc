/*

1005 继续(3n+1)猜想 (25)（25 分）
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，
我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，
因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，
如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，
并按从大到小的顺序输出它们。

*/


#include <iostream>
#include <cstring>
#include <set>
#include <vector>  
#include <algorithm>//提供sort函数，就不用自己去写排序了
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