#include<iostream>
#include<string>
#include<map>
using namespace std;
/**
��Ŀ��˼
N��<=1000������ʾN��ͨ����¼
K��<=1000��:��ʾGang����ֵ�������˾���Gang
Gang�Ķ��壺2�������ϣ����㣨�ˣ�Ȩ��Ϊ�����ͨ����ʱ����֮�䶼�бߣ������������ͨ��ʱ����
��Gangs������������ͨͼ���������Լ�ÿ��Gang�����죬����Ա��������ĸ��˳�򣩡�

˼·��
1���õ���Ȩ��������Map����
2���õ���Ȩ
3������ͼ
*/

const int maxn = 2001;//��Ϊͨ����¼��1000�����������漰2000��
const int INF = 1000000000;

map<int, string> intToString;//���->����
map<string,int> stringToInt;//����->���
map<string,int> Gang;//head->����

int G[maxn][maxn] = { 0 };
int weight[maxn] = { 0 };//��Ȩ
int n, k, numPerson = 0;//����n������k��������numPerson
bool vis[maxn] = { false };



//���ַ���ת��Ϊint
int change(string str) {
	//find()��������һ��������ָ���ֵΪkey��Ԫ�أ����û�ҵ��ͷ���ָ��mapβ���ĵ�������
	if (stringToInt.find(str) != stringToInt.end()) {
		return stringToInt[str];
	}else {
		//�������������˺ţ������˶�����
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}

//nowVisit:��ǰ���
//head����ǰͷĿ�ı��
//numMember:��ǰ��������
//totalValue:��ǰ������Ȩֵ
void DFS(int nowVisit,int &head,int &numMember,int &totalValue) {
	numMember++;//������ʾ���Gang������+1
	vis[nowVisit] = true;//����ѷ���
	//���µ�Ȩ
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson;i++) {
		if (G[nowVisit][i] > 0) {//�ɴ�
			totalValue += G[nowVisit][i];//��ͨ����Ȩֵ����������
			G[nowVisit][i] = G[i][nowVisit] = 0;//ɾ������ߣ���ֹ�ػ�
			if (vis[i] == false) {
				DFS(i,head,numMember,totalValue);
			}
		}
	}
}

void DFSTravel() {
	for (int i = 0; i < numPerson; i++) {
		if (vis[i] == false) {
			int head = i, numMember = 0, totalValue = 0;
			DFS(i,head,numMember,totalValue);
			if (numMember > 2 && totalValue > k) {
				Gang[intToString[head]] = numMember;
			}
		}
	}


}



int main() {
	int w;
	string str1, str2;
	cin >> n >> k;
	for (int i = 0; i < n;i++) {
		cin >> str1 >> str2 >> w;//�����˵�ͱ�Ȩ
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
		//=====�����Ѿ������ͼ��======================
		DFSTravel();//��������ͼ����ͨ�飬��ȡGang����Ϣ
		cout << Gang.size() << endl;
		map<string, int>::iterator it;
		for (it = Gang.begin(); it != Gang.end();it++) {
			cout << it->first << " " << it->second << endl;
		}
		return 0;
	}

}









