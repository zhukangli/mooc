/*
�����������Ĳ�����
��������
10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3

���
Preorder: 5 2 1 0 4 8 6 7 10 9
6 is found
3 is not found
10 is found
10 is the largest key
0 is found
0 is the smallest key
5 is found
Not Found
Inorder: 1 2 4 6 8 9
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT); /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */
void InorderTraversal(BinTree BT);  /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);//��������������
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");//ǰ�����
	MinP = FindMin(BST);//��������Сֵ
	MaxP = FindMax(BST);//���������ֵ
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);//���ض���ֵX
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);//ɾ���ض���ֵX
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");//�������

	return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
/*����ǰ�����*/
void PreorderTraversal(BinTree BT) {
	//������
	if (BT ->Left) {
		PreorderTraversal(BT->Left);
	}
	printf("d%", BT->Data);
	if (BT->Right) {
		PreorderTraversal(BT->Right);	
	}
}
/*�����������*/
void InorderTraversal(BinTree BT) {
	//������
	printf("d%", BT->Data);
	if (BT->Left) {
		PreorderTraversal(BT->Left);
	}
	if (BT->Right) {
		PreorderTraversal(BT->Right);
	}
}
/*�����������Ĳ��룬������������ < �� < ��**/
BinTree Insert(BinTree BST, ElementType X) {
	if (!BST) {//���������ΪInsert��null���ˣ���Ҫ�����ڵ�
		BinTree btree = (BinTree)malloc(sizeof(TNode));
		btree->Data = X;
		btree->Left = NULL;
		btree->Right = NULL;
	}

	if (X<BST ->Data) {
		Insert(BST->Left);
	}
	if (X>BST->Data) {
		Insert(BST->Right);
	}
}