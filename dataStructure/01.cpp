#include <iostream>
using namespace std;

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
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
	for (int i = 1; i <= n;i++) {//��Ŀ��֤���������ģ���Ҫ����±�1��ʼ��
		scanf("%d", list->Data[i]);
		count++;
	}
	list->Last = count;
	return list;
}

Position BinarySearch(List L, ElementType X) {
	//���ֲ���
	int left = 1;
	int right = L->Last;
	while (left <= right) {//ע��Ⱥź���Ҫ�����˵ȺŻ��ٱȽ�һ��
		if (X == L->Data[(left + right) / 2]) {
			return (left + right) / 2;
		}
		else if (X < L->Data[(left + right) / 2]) {
			right = (left + right) / 2 - 1;//-1����Ϊ�м��Ǹ��Ѿ��ȽϹ���
		}
		else if (X > L->Data[(left + right) / 2]) {
			left = (left + right) / 2 + 1;//+1����Ϊ�м��Ǹ��ȽϹ���
		}
	}
	return NotFound;
}




