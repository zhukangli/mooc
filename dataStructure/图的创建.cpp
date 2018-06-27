#include<iostream>
using namespace std;


/*���ڽӾ�������ʾͼ*/
#define MaxVertexNum = 10;
typedef struct GNode *PtrTpGNode;
typedef int WeightType[MaxVertexNum][MaxVertexNum];
typedef int DataType[MaxVertexNum];
typedef int Vertex;//����
struct GNode {
	int Nv;//������
	int Ne;//����
	WeightType G[][];//����
	DataType Data[];//�����涥������е�����
};
typedef PtrTpGNode MGraph;

//����ͼ��VertexNum��ָ���������
MGraph create(int VertexNum) {
	//��ʼ��һ��ֻ�ж��㣬û�бߵ�ͼ
	MGraph mGraph = (MGraph)malloc(sizeof(GNode));
	mGraph->Nv = VertexNum;
	mGraph->Ne = 0;
	//�Ѿ���������λ����Ϊ0����ʾû�б�
	for (int v = 0; v < VertexNum - 1;v++) {
		for (int w = 0; w < VertexNum - 1;w++) {
			mGraph->G[v][w] = 0;
		}
	}
	return mGraph;
}