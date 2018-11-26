/*
��Ŀ��A1103 Integer Factoriztion ���������ֽ�
��N��K����������P�η�֮������ʾ��N<=400, K<=N, 1<P<=7��
���磺169 = 12^2 + 4^2 + 2^2 + 2^2 + 1^2
�����ʱ��ȡK�����ĺ����ģ������ʱ��ȡ�ֵ�����
����������
169 5 2
���������
169=6^2+6^2+6^2+6^2+5^2

�ҵ�˼·��
1�����԰�С�ڸ���N����ȫ���оٳ����������ǵ�ƽ�������������
	169 ��ȡ13����fac[0]=0,fac[1]=1,fac[2]=4......fac[12]=144,fac[13]=169
2)����ת��Ϊ��fac��������ѡ5��������ӵ���N
	DFS��˼�룬ѡ���߲�ѡ��Ȼ��ȥ�ݹ顣�ݹ�ʱ����Ҫ���㵱ǰ����ѡ����nowOK����ǰ�ܺ�sum����ǰҪѡ�����index(���ظ�),
	��Ϊ�����ȡ���������ģ��Ǿͻ�Ҫ�������facSum,�ֵ��򲻼�¼��ֱ�ӴӺ���ǰ���������ܵõ������ֵ���
3������Ӧ����DFS(index,nowOK,sum,facSum);
4���߽�Ӧ����sum = N && nowOK = K

*/
#include <iostream> 
#include <vector>
using namespace std;
int n,k,p;
int maxSum = -1;
vector<int> fac;
vector<int> ans;//���Ž������
vector<int> temp;//��ʱ����

//x��p�η�
int power(int x) {
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans *= x;
	}
	return ans;
}

//Ԥ����fac����
void init() {
	int temp = 0,i=0;
	while (temp <= n) {
		fac.push_back(temp);
		temp = power(++i);
	}
}

//index��fac���±�
//nowK�ǵ�ǰK������
//sum�ǵ�ǰ��ƽ����
//fanSum�ǵ�ǰindex�ĺ�
void DFS(int index,int nowK,int sum,int facSum) {
	//�߽�
	if (sum == n && nowK == k) {
		if (facSum > maxSum) {//��Ȼ�ҵ��߽磬ҲҪȡ���Ž�
			maxSum = facSum;
			ans = temp;
		}
		return;
	}
	if (sum > n || nowK > k) {
		return;
	}
	//�ݹ�
	//ѡ���Լ�
	if (index >= 1) {//0����ѡ��û������
		temp.push_back(index);//��ѡ���Լ�����ȥDFS��ע��˳��
		DFS(index, nowK + 1, sum + fac[index], facSum + index);
		
		//��ѡ���Լ������˻���һ��
		temp.pop_back();
		DFS(index - 1, nowK, sum, facSum);
		
	}
}


int main(){	
	scanf_s("%d%d%d",&n,&k,&p);
	init();//fac��ʼ��
	DFS(fac.size() - 1,0,0,0);
	if (maxSum == -1) {
		printf("Impossible\n");
	}
	else {
		printf("%d=%d^%d",n,ans[0],p);
		for (int i = 1; i < ans.size();i++) {
			printf("+%d^%d", ans[i], p);
		}
	}
	system("pause");
	return 0;
}
