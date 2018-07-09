#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define INF 0x3f3f3f3f
#define MX 501

int mp[MX][MX];
int v[MX];
int dist[MX];
int amount[MX];
int teams[MX];
int pathcount[MX];
int N, M, start, en;
/*
��ʱ��dijkstra�㷨��ⲻ�Ǻ�͸����
�����ȸ��ã���������ϸ�о�

*/
void dijkstra(int s) {
	amount[s] = teams[s];
	dist[s] = 0;
	pathcount[s] = 1;

	while (1) {
		int u, dmin = INF;
		for (int i = 0; i<N; i++) {
			if (v[i] == 0 && dist[i]<dmin) {
				dmin = dist[i];
				u = i;
			}
		}
		if (dmin == INF || u == en) break;
		v[u] = 1;
		for (int i = 0; i<N; i++) {
			if (v[i] == 0) {
				if (dist[i] > dist[u] + mp[u][i]) {
					dist[i] = dist[u] + mp[u][i];
					amount[i] = amount[u] + teams[i];
					pathcount[i] = pathcount[u];
				}
				else if (dist[i] == dist[u] + mp[u][i]) {
					pathcount[i] += pathcount[u];
					if (amount[i] < amount[u] + teams[i])
						amount[i] = amount[u] + teams[i];
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &N, &M, &start, &en);
	for (int i = 0; i<N; i++)
	{
		scanf("%d", &teams[i]);
	}
	for (int i = 0; i<N; i++)
	{
		dist[i] = INF;
		for (int j = 0; j<N; j++)
			mp[i][j] = INF;
	}
	for (int i = 0; i<M; i++)
	{
		int c1, c2, L;
		scanf("%d%d%d", &c1, &c2, &L);
		mp[c1][c2] = mp[c2][c1] = L;
	}

	dijkstra(start);
	printf("%d %d", pathcount[en], amount[en]);

	return 0;
}