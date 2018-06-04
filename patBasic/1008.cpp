#include<iostream>
#include<vector>
using namespace std;
struct Num {
	int data;
	Num* next;
};
typedef struct Num * poi;


poi insert(poi p, int data) {
	poi p2 = (Num *)malloc(sizeof (Num));
	p2->data = data;
	p2->next = NULL;
	p->next = p2;
	return p2;
}

poi findLast(poi p){
	while (p->next) {
		p = p->next;
	}
	return p;
}

int main() {
	int n, m;
	cin >> n >> m;
	int data;
	poi p =(Num *)malloc(sizeof (Num));
	poi front = p;
	//��������
	for (int i = 0; i < n;i++) {
		cin >> data;
		if(i==0){
			p->data = data;
			p-> next = NULL;
		}else {
			p = insert(p,data);
		}
	}
	//������ͷβ����
	p -> next = front;
	//�ҵ�ͷ���,�ؼ������m%n,��������Ű�
	int position = m%n;
	for(int i = 1; i <= n -position;i++){
		if (i == n - position ) {
			p = front;
		}
		front = front->next;
		
	}
	p->next = NULL;
	//����vector����ڵ�����
	vector<int> v;
	while (front->next) {
		v.push_back(front->data);
		front = front->next;
	}
	v.push_back(front->data);

	for (int i = 0; i < v.size()-1; i++) {
		cout<<v[i]<<" ";
	}
	cout << v[v.size() - 1];
	system("pause");
}