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

����ȫƪ�����Լ�д�ġ�����ѧϰ����
1���ݹ�˼�루����return �Լ���
2������ǰ���У��������
3�����������������������ض�ֵ���������С
4������������ɾ��������Ƚ��ѣ����ǹ����������
*/

#include<iostream>
using namespace std;

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
	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &X);
		BST = Insert(BST, X);//��������������
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");//ǰ�����
	MinP = FindMin(BST);//��������Сֵ
	//printf("min%d",MinP->Data);
	MaxP = FindMax(BST);//���������ֵ
	//printf("max%d", MaxP->Data);
	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &X);
		Tmp = Find(BST, X);//���ض���ֵX
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &X);
		BST = Delete(BST, X);//ɾ���ض���ֵX
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");//�������
	system("pause");
	return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
/*����ǰ�����*/
void PreorderTraversal(BinTree BT) {
	//������
	printf("%d ", BT->Data);
	if (BT->Left) {
		PreorderTraversal(BT->Left);
	}
	if (BT->Right) {
		PreorderTraversal(BT->Right);
	}
}
/*�����������*/
void InorderTraversal(BinTree BT) {

	//������
	if (BT->Left) {
		InorderTraversal(BT->Left);
	}
	printf("%d ", BT->Data);
	if (BT->Right) {
		InorderTraversal(BT->Right);
	}
}
/*�����������Ĳ��룬������������ < �� < ��**/
BinTree Insert(BinTree BST, ElementType X) {
	if (!BST) {//���������ΪInsert��null���ˣ���Ҫ�����ڵ�
		BinTree btree = (BinTree)malloc(sizeof(TNode));
		btree->Data = X;
		btree->Left = NULL;
		btree->Right = NULL;
		BST = btree;
	}

	if (X<BST ->Data) {
		BST->Left = Insert(BST->Left,X);//�еĴ�û�����ֵ��BST->Left���Ҿ������Ǵ����
	}
	if (X>BST->Data) {
		BST->Right = Insert(BST->Right, X);
	}
	return BST;
}

/*���ض���ֵ*/
Position Find(BinTree BST, ElementType X) {
	if (BST) {
		if (BST->Data == X) {
			return BST;
		}
		if (BST->Data > X) {
			BST = Find(BST->Left, X);
		}else if (BST->Data < X) {//����һ��Ҫelse if����Ȼǰ���Ҳ���������null�ֻ��������ж���ɿ�ָ��
			BST = Find(BST->Right, X);
		}
	}
	return BST;
}

/*����Сֵ*/
Position FindMin(BinTree BST) {
	//�߼�����һֱ�����ң�ֱ��û��
	if (BST) {
		if (!BST ->Left) {
			return	BST;
		}
		BST = FindMin(BST->Left);
	}
	return BST;
}

/*�����ֵ*/
Position FindMax(BinTree BST) {
	if (BST) {
		if (!BST->Right) {
			return	BST;
		}
		BST = FindMax(BST->Right);
	}
	return BST;

}

/*ɾ���ض���ֵ�������е�����⣬Ҫ��ϸ��
����ɾ���ڵ��������������ʹ��������ҵ���Сֵ������������ԭ���Ǹ���С����ɾ��
      ɾ���ڵ���1���ӽڵ㣬�����������Լ����Լ�free��
	  ɾ���ڵ�û���ӽڵ㣬�Լ�free��
*/
BinTree Delete(BinTree BST, ElementType X) {
	Position Tmp;

	if (!BST)
		printf("Not Found\n");
	else {
		if (X < BST->Data)
			BST->Left = Delete(BST->Left, X);   /* ���������ݹ�ɾ�� */
		else if (X > BST->Data)
			BST->Right = Delete(BST->Right, X); /* ���������ݹ�ɾ�� */
		else { /* BST����Ҫɾ���Ľ�� */
			   /* �����ɾ����������������ӽ�� */
			if (BST->Left && BST->Right) {
				/* ��������������С��Ԫ�����ɾ����� */
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				/* ����������ɾ����СԪ�� */
				BST->Right = Delete(BST->Right, BST->Data);
			}
			else { /* ��ɾ�������һ�������ӽ�� */
				Tmp = BST;
				if (!BST->Left)       /* ֻ���Һ��ӻ����ӽ�� */
					BST = BST->Right;
				else                   /* ֻ������ */
					BST = BST->Left;
				free(Tmp);
			}
		}
	}
	return BST;
}