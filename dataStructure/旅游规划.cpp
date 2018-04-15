/**
07-图6 旅游规划（25 分）
有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。现在需要你写一个程序，帮助前来咨询的游客找一条出发地和目的地之间的最短路径。如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

输入格式:

输入说明：输入数据的第1行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0~(N?1)；M是高速公路的条数；S是出发地的城市编号；D是目的地的城市编号。随后的M行中，每行给出一条高速公路的信息，分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。输入保证解的存在。

输出格式:

在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

输入样例:

4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
输出样例:

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
//查找未收入点集中的点中距离最小的点
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
Dijkstra算法。建图时初始化边权INF。
*/
