/**
这里 ReadInput()方法没有实现，所以不能跑 
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
    Position Last; /* 保存线性表中最后一个元素的位置 */  
};  
  
List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */  
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
  
/* 你的代码将被嵌在这里 */  
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
