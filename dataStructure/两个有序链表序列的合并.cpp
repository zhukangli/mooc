/**
����Ҫ��ʵ��һ�������������������ʾ�ĵ����������кϲ�Ϊһ���ǵݼ����������С�
**/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

/**
L1��L2�Ǹ����Ĵ�ͷ���ĵ���������洢�������ǵ�������ģ�����MergeҪ��L1��L2�ϲ�Ϊһ���ǵݼ����������С�
Ӧֱ��ʹ��ԭ�����еĽ�㣬���ع鲢��Ĵ�ͷ��������ͷָ�롣
**/
List Merge( List L1, List L2 )   ///�ϲ�����  �ص�Ҫд�ĺ�����  
{  
    List pa,pb,pc,L;  
    L = (List)malloc(sizeof(struct Node));  
    pa=L1->Next;  
    pb=L2->Next;  
    pc = L;  
    while(pa && pb)  
    {  
        if(pa->Data <= pb->Data)  
        {  
            pc->Next = pa;  
            pc = pa;  
            pa = pa->Next;  
        }  
        else  
        {  
            pc->Next = pb;  
            pc = pb;  
            pb = pb->Next;  
        }  
    }  
    pc->Next = pa ? pa : pb;  
    L1->Next = NULL;  
    L2->Next = NULL;  
    return L;  
}  


int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}






