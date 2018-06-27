#include<iostream>
using namespace std;


/*用邻接矩阵来表示图*/
#define MaxVertexNum = 10;
typedef struct GNode *PtrTpGNode;
typedef int WeightType[MaxVertexNum][MaxVertexNum];
typedef int DataType[MaxVertexNum];
typedef int Vertex;//顶点
struct GNode {
	int Nv;//顶点数
	int Ne;//边数
	WeightType G[][];//矩阵
	DataType Data[];//用来存顶点可能有的数据
};
typedef PtrTpGNode MGraph;

//创建图，VertexNum是指顶点的数量
MGraph create(int VertexNum) {
	//初始化一个只有顶点，没有边的图
	MGraph mGraph = (MGraph)malloc(sizeof(GNode));
	mGraph->Nv = VertexNum;
	mGraph->Ne = 0;
	//把矩阵中所有位置置为0，表示没有变
	for (int v = 0; v < VertexNum - 1;v++) {
		for (int w = 0; w < VertexNum - 1;w++) {
			mGraph->G[v][w] = 0;
		}
	}
	return mGraph;
}