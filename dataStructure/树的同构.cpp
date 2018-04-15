#include<stdio.h>
#define MaxTree 10
#define Null -1     //��Null����Ϊ-1��������0����Ϊ�����±�Ϊ0�ĵط��Ա����нڵ�
typedef char ElementType;
typedef int Tree;
struct TreeNode{    //����������ڵ�
    ElementType Data;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];
int N,check[MaxTree];   //check��������Ѱ�����ĸ��ڵ�

Tree BuildTree(struct TreeNode T[]){
    int Root=Null,i;    //�տ�ʼ���ڵ���Ϊ�գ���Ϊ������ʱ��ɷ���Null
    char cl,cr;
    scanf("%d",&N); 
    if(N){              //�����Ϊ�����Ļ�
        for(i=0;i<N;i++) check[i]=0;    //��check������Ϊ0
        for(i=0;i<N;i++){
            scanf("\n%c %c %c",&T[i].Data,&cl,&cr); //�ѻ��з�����ǰ��Ե�ǰ��scanf��Ļس��������һ��scanf�����лس���һ������
            if(cl!='-'){
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            }
            else                    
                T[i].Left=Null; 

            if(cr!='-'){
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            }
            else 
                T[i].Right=Null;

        }
        for(i=0;i<N;i++)
            if(!check[i])   break;
        Root=i;
    }
    return Root; 
}
int Isomorphic(Tree R1,Tree R2){
    if((R1==Null)&&(R2==Null))      //���Ϊ��������ͬ����
        return 1;
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))//���һ��Ϊ��һ����Ϊ������ͬ����
        return 0;
    if((T1[R1].Data)!=(T2[R2].Data))//������ݲ�ͬ����ͬ����
        return 0;
    //�������Ӷ�Ϊ���ж��Ҷ����Ƿ�ͬ������Ҫ�������������棨1���Ҷ����Ƿ�Ϊ�գ�2���Ƿ�һ�����Ҷ���һ��û�У�3���Ҷ��������Ƿ���ͬ
    if((T1[R1].Left==Null)&&(T2[R2].Left==Null))    
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    /* �������������Ӷ���Ϊ�ղ������ݻ���һ���ģ�������ӽ��еݹ�*/
    if ( ((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Data)==(T2[T2[R2].Left].Data)) )
        return ( Isomorphic( T1[R1].Left, T2[R2].Left )&&Isomorphic( T1[R1].Right, T2[R2].Right ) );
    /* �������������ӣ�һ����һ�����ջ��߶����գ��������ݲ�һ������ô�жϵ�һ���������ң������Ƿ���ڶ��������ң��󣩶���ͬ�� */
    else 
        return ( Isomorphic( T1[R1].Left, T2[R2].Right)&&Isomorphic( T1[R1].Right, T2[R2].Left ) );

}
int main(){
    Tree R1,R2;     //���Ƚ�����������R1��R2Ϊ���ĸ��ڵ�
    R1=BuildTree(T1);
    R2=BuildTree(T2);
    if(Isomorphic(R1,R2))   //Isomorphic�����ж��Ƿ�ͬ��
        printf("Yes\n");
    else printf("No\n");
    return 0;
}



/**
https://pintia.cn/problem-sets/951072707007700992/problems/975887310869037056
03-��1 ����ͬ����25 �֣�
����������T1��T2�����T1����ͨ�����ɴ����Һ��ӻ����ͱ��T2�������ǳ��������ǡ�ͬ�����ġ�����ͼ1����������������ͬ���ģ���Ϊ���ǰ�����һ�����Ľ��A��B��G�����Һ��ӻ����󣬾͵õ�����һ��������ͼ2�Ͳ���ͬ���ġ�


ͼ1



ͼ2

�ָ����������������ж������Ƿ���ͬ���ġ�
�����ʽ:

�������2�ö�����������Ϣ������ÿ������������һ���и���һ���Ǹ�����N (��10)���������Ľ��������ʱ�������0��N?1��ţ������N�У���i�ж�Ӧ��ŵ�i����㣬�����ý���д洢��1��Ӣ�Ĵ�д��ĸ�������ӽ��ı�š��Һ��ӽ��ı�š�������ӽ��Ϊ�գ�������Ӧλ���ϸ�����-�������������ݼ���һ���ո�ָ���ע�⣺��Ŀ��֤ÿ������д洢����ĸ�ǲ�ͬ�ġ�

�����ʽ:

�����������ͬ���ģ������Yes�������������No����

��������1����Ӧͼ1����

8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
�������1:

Yes
��������2����Ӧͼ2����

8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4
�������2:

No

**/
