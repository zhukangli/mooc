/**
07-ͼ6 ���ι滮��25 �֣�
����һ���Լ�����·��ͼ�����֪�����м�ĸ��ٹ�·���ȡ��Լ��ù�·Ҫ��ȡ�Ĺ�·�ѡ�������Ҫ��дһ�����򣬰���ǰ����ѯ���ο���һ�������غ�Ŀ�ĵ�֮������·���������������·��������̵ģ���ô��Ҫ�������˵�һ��·����

�����ʽ:

����˵�����������ݵĵ�1�и���4��������N��M��S��D������N��2��N��500���ǳ��еĸ�����˳�������еı��Ϊ0~(N?1)��M�Ǹ��ٹ�·��������S�ǳ����صĳ��б�ţ�D��Ŀ�ĵصĳ��б�š�����M���У�ÿ�и���һ�����ٹ�·����Ϣ���ֱ��ǣ�����1������2�����ٹ�·���ȡ��շѶ�м��ÿո�ֿ������־�Ϊ�����Ҳ�����500�����뱣֤��Ĵ��ڡ�

�����ʽ:

��һ�������·���ĳ��Ⱥ��շ��ܶ���ּ��Կո�ָ��������β�����ж���ո�

��������:

4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
�������:

3 40
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 505
#define INF 100005

typedef struct ENode* Edge;
struct ENode {
    int v1, v2;
    int w1, w2;
};

typedef struct GNode* Graph;
struct GNode {
    int Nv, Ne;
    int Data1[MAXN][MAXN];
    int Data2[MAXN][MAXN];
};

Graph CreateGraph(int n, int m) {
    int i, j;
    Graph G = (Graph)malloc(sizeof(struct GNode));
    G->Nv = n;
    G->Ne = m;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            G->Data1[i][j] = G->Data2[i][j] = INF;
        }
    }
    return G;
}

void InsertEdge(Graph G, Edge E) {
    G->Data1[E->v1][E->v2] = G->Data1[E->v2][E->v1] = E->w1;
    G->Data2[E->v1][E->v2] = G->Data2[E->v2][E->v1] = E->w2;
}

Graph BuildGraph(int n, int m) {
    int v;
    Graph G;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    G = CreateGraph(n, m);
    for(v = 0; v < G->Ne; v++) {
        scanf("%d%d%d%d", &E->v1, &E->v2, &E->w1, &E->w2);
        InsertEdge(G, E);
    }
    return G;
}
//����δ����㼯�еĵ��о�����С�ĵ�
int FindMinDist(Graph G, int dist[], int vertex[]) {
    int v, MinDist = INF, Minv = 0;
    for(v = 0; v < G->Nv; v++) {
        if(!vertex[v] && dist[v] < MinDist) {
            MinDist = dist[v];
            Minv = v;
        }
    }
    if(MinDist != INF) return Minv;
    else return -1;
}

void Dijkstra(Graph G, int dist[], int path[], int s, int cost[]) {
    int vertex[MAXN];
    int v, w;
    for(v = 0; v < G->Nv; v++) {
        if(G->Data1[s][v]) path[v] = s;
        else path[v] = -1;
        dist[v] = G->Data1[s][v];
        cost[v] = G->Data2[s][v];
        vertex[v] = 0;
    }
    vertex[s] = 1;
    dist[v] = 0;
    for( ; ; ) {
        v = FindMinDist(G, dist, vertex);
        if(v == -1) break;
        vertex[v] = 1;
        for(w = 0; w < G->Nv; w++) {
            if(!vertex[w] && dist[w] > dist[v] + G->Data1[v][w]) {
                dist[w] = dist[v] + G->Data1[v][w];
                path[w] = v;
                cost[w] = cost[v] + G->Data2[v][w];
            }
            else if(!vertex[w] && dist[w] == dist[v] + G->Data1[v][w]) {
                if(cost[w] > cost[v] + G->Data2[v][w]) {
                    path[w] = v;
                    cost[w] = cost[v] + G->Data2[v][w];
                }
            }
        }
    }
}

int main() {
    int n, m, s, d;
    int path[MAXN], dist[MAXN], cost[MAXN];
    Graph G;
    scanf("%d%d%d%d", &n, &m, &s, &d);
    G = BuildGraph(n, m);
    Dijkstra(G, dist, path, s, cost);
    printf("%d %d\n", dist[d], cost[d]);
    return 0;
}

/*
Dijkstra�㷨����ͼʱ��ʼ����ȨINF��
*/
