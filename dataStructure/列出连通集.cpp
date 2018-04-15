/**
06-图1 列出连通集（25 分）
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N?1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:

输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:

按照"{ v
?1
??  v
?2
??  ... v
?k
??  }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:

8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:

{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
**/



#include<stdio.h>
#include<stdlib.h>

#define MAXN 15
int visited[MAXN] = {0};

//建立邻接矩阵 //Create Graph
int G[MAXN][MAXN]={0},NV,NE;

void BuildGraph()
{
	//freopen("test1.txt","r",stdin); 
	int i,j,v1,v2;
	
	scanf("%d%d",&NV,&NE);
	
	for( i=0; i<NE; i++)
	{
		scanf("%d%d",&v1,&v2);
		//InsertEdge
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
}
//DFS
void DFS(int v)
{
	visited[v] = 1;
	printf("%d ",v);//输出这个点 
	for(int i=0; i<NV; i++)
	{
		if(G[v][i] && !visited[i])//如果联通这个点且没有访问过 
		{
			DFS(i);
		}
	}
} 

void ListComponentsDFS()
{
	int i;	
	for(i=0; i<NV; i++)
	{
		if(!visited[i])
		{ 
			printf("{ "); 
			DFS(i);
			printf("}\n");
		}
	}
}
//初始化visited
void isvisited()
{
	for(int i=0; i<MAXN; i++)
	{
		visited[i] = 0;
	}
} 
 
//BFS
void BFS(int v)
{
	//队列
	const int MAXSIZE=100;
	int quene[MAXSIZE];
	int first = -1, rear = -1; 
	quene[++rear] = v;//入队 
	visited[v] = 1;
	
	while(first < rear)//队列不为空
	{
		int de = quene[++first];//出队
		printf("%d ",de);
		for(int i=0; i<NV; i++)
		{
			if(!visited[i]&&G[de][i])
			{
				visited[i] = 1;
				quene[++rear] = i;
			}
		} 
	} 
	
}


void ListComponentsBFS()
{
	int i;	
	for(i=0; i<NV; i++)
	{
		if(!visited[i])
		{
			printf("{ "); 
			BFS(i);
			printf("}\n");
		}
	}
}

int main()
{

	//建图
	BuildGraph();
	//DFS遍历连通集
	ListComponentsDFS();
	isvisited();
	//BFS遍历连通集 
	ListComponentsBFS();
	
	return 0;
}
