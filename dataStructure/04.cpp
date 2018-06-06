/*
二叉搜索树的操作集
输入样例
10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3

输出
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

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

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
		BST = Insert(BST, X);//构建二叉搜索树
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");//前序遍历
	MinP = FindMin(BST);//找树中最小值
	MaxP = FindMax(BST);//找树中最大值
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);//找特定的值X
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
		BST = Delete(BST, X);//删除特定的值X
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");//中序遍历

	return 0;
}
/* 你的代码将被嵌在这里 */
/*树的前序遍历*/
void PreorderTraversal(BinTree BT) {
	//左中右
	if (BT ->Left) {
		PreorderTraversal(BT->Left);
	}
	printf("d%", BT->Data);
	if (BT->Right) {
		PreorderTraversal(BT->Right);	
	}
}
/*树的中序遍历*/
void InorderTraversal(BinTree BT) {
	//根左右
	printf("d%", BT->Data);
	if (BT->Left) {
		PreorderTraversal(BT->Left);
	}
	if (BT->Right) {
		PreorderTraversal(BT->Right);
	}
}
/*二叉搜索树的插入，二叉搜索树左 < 中 < 右**/
BinTree Insert(BinTree BST, ElementType X) {
	if (!BST) {//遍历到最后为Insert（null）了，需要创立节点
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