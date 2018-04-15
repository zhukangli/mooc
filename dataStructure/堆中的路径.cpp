/**
05-树7 堆中的路径（25 分）
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

输入格式:

每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:

对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:

5 3
46 23 26 24 10
5 4 3
输出样例:

24 23 10
46 23 10
26 10
**/
#include <stdio.h>
 
#define MaxN 1001
#define MinH -10001
 
int H[MaxN],size;

//创建最小堆 
void Creat()
{
    size = 0;
    H[0] = MinH;//设置岗哨，根结点H[0]最小 
} 

//将X插入H。这里省略检查对是否已满的代码 
void Insert(int X)
{
    int i;
    for(i = ++size; H[i/2] > X; i/=2) //将大的元素下移，找到X的位置i 
        H[i] = H[i/2];
    H[i] = X;
}

int main()
{
    int N,M,x;
    scanf("%d %d", &N, &M);
    Creat();
    for(int i = 0; i < N; i++) {
        scanf("%d",&x);
        Insert(x);
    }
    int j;
    for(int i = 0; i < M; i++) {
        scanf("%d",&j);
        printf("%d",H[j]);
        while(j > 1) {
            j /= 2;
            printf(" %d",H[j]);//控制格式 
        }
        printf("\n");
    }
    return 0;
}
