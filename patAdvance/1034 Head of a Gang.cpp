#include<iostream>
#include<string>
#include<map>
using namespace std;
/**
题目意思
N（<=1000）：表示N条通话记录
K（<=1000）:表示Gang的阈值，超过了就是Gang
Gang的定义：2个人以上，顶点（人，权重为其个人通话总时长）之间都有边（两个顶点的总通话时长）
求：Gangs的数量，即连通图的数量。以及每个Gang的首领，及成员数量（字母表顺序）。

思路：
1：得到点权，可以用Map来存
2：得到边权
3：构造图
*/

const int maxn = 2001;//因为通话记录有1000条，最多可能涉及2000人
const int INF = 1000000000;

map<int, string> intToString;//编号->姓名
map<string,int> stringToInt;//姓名->编号
map<string,int> Gang;//head->人数

int G[maxn][maxn] = { 0 };
int weight[maxn] = { 0 };//点权
int n, k, numPerson = 0;//边数n，下限k，总人数numPerson
bool vis[maxn] = { false };



//将字符串转换为int
int change(string str) {
	//find()函数返回一个迭代器指向键值为key的元素，如果没找到就返回指向map尾部的迭代器。
	if (stringToInt.find(str) != stringToInt.end()) {
		return stringToInt[str];
	}else {
		//这里很巧妙，即编了号，又数了顶点数
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}

//nowVisit:当前编号
//head：当前头目的编号
//numMember:当前帮会的人数
//totalValue:当前帮会的总权值
void DFS(int nowVisit,int &head,int &numMember,int &totalValue) {
	numMember++;//进来表示这个Gang的人数+1
	vis[nowVisit] = true;//标记已访问
	//更新点权
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson;i++) {
		if (G[nowVisit][i] > 0) {//可达
			totalValue += G[nowVisit][i];//连通块总权值加上这条边
			G[nowVisit][i] = G[i][nowVisit] = 0;//删除这个边，防止回环
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
		cin >> str1 >> str2 >> w;//两个端点和边权
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
		//=====至此已经构造好图了======================
		DFSTravel();//遍历整个图的连通块，获取Gang的信息
		cout << Gang.size() << endl;
		map<string, int>::iterator it;
		for (it = Gang.begin(); it != Gang.end();it++) {
			cout << it->first << " " << it->second << endl;
		}
		return 0;
	}

}









