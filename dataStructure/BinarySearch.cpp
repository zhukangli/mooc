/**
���� ReadInput()����û��ʵ�֣����Բ����� 
**/
#include <stdio.h>  
#include <stdlib.h>  
  
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
Position BinarySearch(List Tbl, ElementType K);  
  
int main()  
{  
    List Tbl;  
    ElementType K;  
    Position P;  
  
    Tbl = ReadInput();  
    scanf("%d", &K);  
    P = BinarySearch(Tbl, K);  
    printf("%d\n", P);  
  
    return 0;  
}  
  
/* ��Ĵ��뽫��Ƕ������ */  
Position BinarySearch(List Tbl, ElementType K) {  
    int left;  
    int right;  
    if (Tbl->Last) {  
        left = 1;  
        right = Tbl->Last;   
        while(left <= right) {  
            if (K == Tbl->Data[(left + right) / 2])  
                return (left + right) / 2;  
            else {  
                if (K < Tbl->Data[(left + right) / 2])  
                    right = (left + right) / 2 - 1;  
                else   
                    left = (left + right) / 2 + 1;  
            }  
        }  
    }  
    return NotFound;  
}  
