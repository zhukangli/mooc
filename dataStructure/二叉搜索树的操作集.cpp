/**
������Ҫ���ף�ʲô�Ƕ���������
���ǣ�
      ��������ֵ< ���ڵ� < ��������ֵ 
 
**/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); //����������ɲ���ʵ�֣�ϸ�ڲ���
void InorderTraversal( BinTree BT );  //����������ɲ���ʵ�֣�ϸ�ڲ���
BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

//BST��һ��ָ�룬ָ��TNode 
BinTree Insert(BinTree BST, ElementType X) {  
    //!BST ��ʾBST������ 
    if (!BST) {  
       //����һ��TNode�ڵ㣬malloc�������ص�ַ 
        BST = (BinTree)malloc(sizeof(struct TNode));  
        //���ýڵ㸳ֵΪX����X��Ϊ���ڵ� 
        BST->Data = X;  
        BST->Left = NULL;  
        BST->Right = NULL;  
    }  
    else if (X < BST->Data)  
        // X�ȸ��ڵ�С��ʱ�򣬵ݹ������ڵ���߲��룬�ú����������ݹ� 
        BST->Left = Insert(BST->Left, X);  
    else if (X > BST->Data)  
         //X�ȸ��ڵ���ʱ�򣬵ݹ������ڵ��ұ߲��� 
        BST->Right = Insert(BST->Right, X);  
    return BST;  
}  
  
  
BinTree Delete(BinTree BST, ElementType X) {  
    Position Tmp;  
    //BSTΪ�գ���ʾû���ҵ�X������ɾ�� 
    if (!BST) {  
        printf("Not Found\n");  
    }  
    else if (X < BST->Data)  
        //X �ȸ��ڵ�С������������ 
        BST->Left = Delete(BST->Left, X);  
    else if (X > BST->Data)  
         //X �ȸ��ڵ������������ 
        BST->Right = Delete(BST->Right, X);  
    else {//�����ʾ�ҵ�X��λ����  
         //X����λ�ã������������������� 
        if (BST->Left && BST->Right) {  
            //���ﲻ̫�����          
            Tmp = FindMax(BST->Left);  
            BST->Data = Tmp->Data;  
            BST->Left= Delete(BST->Left, Tmp->Data);  
        }  
        else {  
             //x����λ�ã�ֻ�������ӽڵ㣬����ֻ�������ӽڵ㣬����X����ΪҶ�ӽڵ� 
            Tmp = BST;  
            if (!BST->Left)  
               //��ڵ㲻���ڣ���X���ڽڵ�ֱ�������ӽڵ���� 
                BST = BST->Right;  
            else  
                //���ӽڵ㲻���ڣ���x���ڽڵ�ֱ�������ӽڵ���� 
                BST = BST->Left;  
            //��X���ڴ�free�� 
            free(Tmp);  
        }  
    }  
    return BST;  
}  
  
Position Find(BinTree BST, ElementType X) { 
    //����Ƚ�������⣬���ǲ�ͣ���� 
    while (BST && (X != BST->Data)) {  
        if (X < BST->Data)  
            BST = BST->Left;  
        else  
            BST = BST->Right;  
    }  
    //���ԣ������Ҳ����᷵��null 
    return BST;  
}  
  
Position FindMin(BinTree BST) {  
    //һֱ������ 
    if (BST) {  
        while (BST->Left)  
            BST = BST->Left;  
    }  
    return BST;  
}  
  
Position FindMax(BinTree BST) {  
    //һֱ������ 
    if (BST) {  
        while (BST->Right)  
            BST = BST->Right;  
    }  
    return BST;  
}  


int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    //������scanf������cin ����һЩ���ݣ�������������� 
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    //�����������Сֵ 
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    //���в����ض���ֵ 
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    //ɾ�������ض���ֵ 
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}




/**
04-��7 �����������Ĳ�������30 �֣�
����Ҫ��ʵ�ָ���������������5�ֳ��ò�����

�����ӿڶ��壺

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );
����BinTree�ṹ�������£�

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
����Insert��X�������������BST�����ؽ�����ĸ����ָ�룻
����Delete��X�Ӷ���������BST��ɾ���������ؽ�����ĸ����ָ�룻���X�������У����ӡһ��Not Found������ԭ���ĸ����ָ�룻
����Find�ڶ���������BST���ҵ�X�����ظý���ָ�룻����Ҳ����򷵻ؿ�ָ�룻
����FindMin���ض���������BST����СԪ����ָ�룻
����FindMax���ض���������BST�����Ԫ����ָ�롣
���в��Գ���������

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); //����������ɲ���ʵ�֣�ϸ�ڲ���
void InorderTraversal( BinTree BT );  //����������ɲ���ʵ�֣�ϸ�ڲ���

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ 
����������

10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3
���������

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



**/
