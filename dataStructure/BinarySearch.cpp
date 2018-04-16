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
/**
这个问题还是比较基础的，已经手写练习过一遍 
**/
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
                	//注意，因为Tbl->Data[(l+r)/2],所以-1，右边就不用再在（l+r）/2这个位置找了 
                    right = (left + right) / 2 - 1;  
                else   
                	//这个也是同样道理 
                    left = (left + right) / 2 + 1;  
            }  
        }  
    }  
    return NotFound;  
}  
