#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */
List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;//题目认定L1，L2本身是有序递增的
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	system("pause");
	return 0;
}

/* 你的代码将被嵌在这里 */
List Read() {
	int n;
	cin >> n;
	ElementType data;
	List first = (List)malloc(sizeof(Node));
	cin >> data;
	first->Data = data;
	List pre = first;
	for (int i = 0; i < n-1;i++) {
		List list = (List)malloc(sizeof(Node));
		cin >> data;
		list->Data = data;
		first->Next = list;
		first = list;
		if (i == n -2) {
			first->Next = NULL;
		}
	}
	return pre;
}

void Print(List L) {
	while (L->Next) {
		printf("%d ",L->Data);
		L = L->Next;
	}
	printf("%d", L->Data);
}

/*L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；
函数Merge要将L1和L2合并为一个非递减的整数序列。
应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。*/
List Merge(List L1, List L2)   ///合并函数  重点要写的函数！  
{
	List pa, pb, pc, L;
	L = (List)malloc(sizeof(struct Node));
	pa = L1->Next;
	pb = L2->Next;
	pc = L;
	while (pa && pb)
	{
		if (pa->Data <= pb->Data)
		{
			pc->Next = pa;
			pc = pa;
			pa = pa->Next;
		}
		else
		{
			pc->Next = pb;
			pc = pb;
			pb = pb->Next;
		}
	}
	pc->Next = pa ? pa : pb;
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}