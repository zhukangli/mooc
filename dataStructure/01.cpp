#include <iostream>
using namespace std;

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);


int main() {
	List L;
	ElementType X;
	Position P;

	L = ReadInput();
	scanf("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	return 0;
}

List ReadInput() {
	List list = (List)malloc(sizeof(LNode));
	int n;
	scanf("%d",n);
	Position count = 0;
	for (int i = 1; i <= n;i++) {//题目保证存的是有序的，并要求从下表1开始存
		scanf("%d", list->Data[i]);
		count++;
	}
	list->Last = count;
	return list;
}

Position BinarySearch(List L, ElementType X) {
	//二分查找
	int left = 1;
	int right = L->Last;
	while (left <= right) {//注意等号很重要，少了等号会少比较一次
		if (X == L->Data[(left + right) / 2]) {
			return (left + right) / 2;
		}
		else if (X < L->Data[(left + right) / 2]) {
			right = (left + right) / 2 - 1;//-1是因为中间那个已经比较过了
		}
		else if (X > L->Data[(left + right) / 2]) {
			left = (left + right) / 2 + 1;//+1是因为中间那个比较过了
		}
	}
	return NotFound;
}




