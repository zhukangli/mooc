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

这里全篇都是自己写的。这里学习到了
1：递归思想（就是return 自己）
2：树的前，中，后序遍历
3：二叉搜索树构建，查找特定值，找最大，最小
4：二叉搜索树删除，这个比较难，但是规则基本懂了
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
	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &X);
		BST = Insert(BST, X);//构建二叉搜索树
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");//前序遍历
	MinP = FindMin(BST);//找树中最小值
	//printf("min%d",MinP->Data);
	MaxP = FindMax(BST);//找树中最大值
	//printf("max%d", MaxP->Data);
	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &X);
		Tmp = Find(BST, X);//找特定的值X
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
		BST = Delete(BST, X);//删除特定的值X
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");//中序遍历
	system("pause");
	return 0;
}
/* 你的代码将被嵌在这里 */
/*树的前序遍历*/
void PreorderTraversal(BinTree BT) {
	//根左右
	printf("%d ", BT->Data);
	if (BT->Left) {
		PreorderTraversal(BT->Left);
	}
	if (BT->Right) {
		PreorderTraversal(BT->Right);
	}
}
/*树的中序遍历*/
void InorderTraversal(BinTree BT) {

	//左中右
	if (BT->Left) {
		InorderTraversal(BT->Left);
	}
	printf("%d ", BT->Data);
	if (BT->Right) {
		InorderTraversal(BT->Right);
	}
}
/*二叉搜索树的插入，二叉搜索树左 < 中 < 右**/
BinTree Insert(BinTree BST, ElementType X) {
	if (!BST) {//遍历到最后为Insert（null）了，需要创立节点
		BinTree btree = (BinTree)malloc(sizeof(TNode));
		btree->Data = X;
		btree->Left = NULL;
		btree->Right = NULL;
		BST = btree;
	}

	if (X<BST ->Data) {
		BST->Left = Insert(BST->Left,X);//有的答案没有最后赋值给BST->Left，我觉得这是错误的
	}
	if (X>BST->Data) {
		BST->Right = Insert(BST->Right, X);
	}
	return BST;
}

/*找特定的值*/
Position Find(BinTree BST, ElementType X) {
	if (BST) {
		if (BST->Data == X) {
			return BST;
		}
		if (BST->Data > X) {
			BST = Find(BST->Left, X);
		}else if (BST->Data < X) {//这里一定要else if，不然前面找不到，返回null又会来这里判断造成空指针
			BST = Find(BST->Right, X);
		}
	}
	return BST;
}

/*找最小值*/
Position FindMin(BinTree BST) {
	//逻辑就是一直往左找，直到没有
	if (BST) {
		if (!BST ->Left) {
			return	BST;
		}
		BST = FindMin(BST->Left);
	}
	return BST;
}

/*找最大值*/
Position FindMax(BinTree BST) {
	if (BST) {
		if (!BST->Right) {
			return	BST;
		}
		BST = FindMax(BST->Right);
	}
	return BST;

}

/*删除特定的值，这里有点难理解，要仔细看
规则：删除节点有左右子树，就从右子树找到最小值，放上来，把原来那个最小子数删掉
      删除节点有1个子节点，把子树付给自己，自己free掉
	  删除节点没有子节点，自己free掉
*/
BinTree Delete(BinTree BST, ElementType X) {
	Position Tmp;

	if (!BST)
		printf("Not Found\n");
	else {
		if (X < BST->Data)
			BST->Left = Delete(BST->Left, X);   /* 从左子树递归删除 */
		else if (X > BST->Data)
			BST->Right = Delete(BST->Right, X); /* 从右子树递归删除 */
		else { /* BST就是要删除的结点 */
			   /* 如果被删除结点有左右两个子结点 */
			if (BST->Left && BST->Right) {
				/* 从右子树中找最小的元素填充删除结点 */
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				/* 从右子树中删除最小元素 */
				BST->Right = Delete(BST->Right, BST->Data);
			}
			else { /* 被删除结点有一个或无子结点 */
				Tmp = BST;
				if (!BST->Left)       /* 只有右孩子或无子结点 */
					BST = BST->Right;
				else                   /* 只有左孩子 */
					BST = BST->Left;
				free(Tmp);
			}
		}
	}
	return BST;
}