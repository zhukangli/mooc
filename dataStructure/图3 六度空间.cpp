/**
06-图3 六度空间（30 分）
“六度空间”理论又称作“六度分隔（Six Degrees of Separation）”理论。这个理论可以通俗地阐述为：“你和任何一个陌生人之间所间隔的人不会超过六个，也就是说，最多通过五个人你就能够认识任何一个陌生人。”如图1所示。


图1 六度空间示意图
“六度空间”理论虽然得到广泛的认同，并且正在得到越来越多的应用。但是数十年来，试图验证这个理论始终是许多社会学家努力追求的目标。然而由于历史的原因，这样的研究具有太大的局限性和困难。随着当代人的联络主要依赖于电话、短信、微信以及因特网上即时通信等工具，能够体现社交网络关系的一手数据已经逐渐使得“六度空间”理论的验证成为可能。

假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

输入格式:

输入第1行给出两个正整数，分别表示社交网络图的结点数N（1<N≤10
?4
?? ，表示人数）、边数M（≤33×N，表示社交关系数）。随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到N编号）。

输出格式:

对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。

输入样例:

10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
输出样例:

1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%
**/

#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

int G[10005][10005];
bool Visited[10005];
int Nv,Ne;

void CreateGraph()
{
    scanf("%d %d",&Nv,&Ne);
    for(int i=0;i<Nv;i++)
    {
        Visited[i] = false;
        for(int j=0;j<Nv;j++)
        {
            G[i][j] = 0;
        }
    }
    for(int i=0;i<Ne;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x-1][y-1] = G[y-1][x-1] = 1;
    }
}

void BFS(int n)
{
    int level = 0,last = n,rail;
    queue<int> Q;
    Q.push(n);
    Visited[n] = true;
    int count = 1;
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        for(int i=0;i<Nv;i++)
        {
            if(!Visited[i]&&G[temp][i]){
                Q.push(i);
                Visited[i] = true;
                count++;
                rail = i;
            }
        }
        if(temp == last){
            level++;
            last = rail;
        }
        if(level == 6){
            break;
        }
    }
    printf("%d: %.2f%%\n", n+1, (count * 100.00) / Nv); 
}

int main()
{
    CreateGraph();
    for(int i=0;i<Nv;i++)
    {
        for(int j=0;j<Nv;j++)
        {
            Visited[j] = false;
        }
        BFS(i);
    }

    return 0;
}

