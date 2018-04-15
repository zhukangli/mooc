#include <iostream>  
#include <stdio.h>  
using namespace std;  
  
int s[10005];  
int N;  
void input_connect();  
void check_connect();  
void stop_connect();  
int finds(int k);  
void unions(int root1,int root2);  
  
int main()  
{  
    scanf("%d",&N);  
    for(int i=0; i<N; i++)  
    {  
        s[i] = -1;  
    }  
    char cp;  
    do  
    {  
        scanf("%s",&cp);  
        switch(cp)  
        {  
  
        case 'I':  
            input_connect();  
            break;  
        case 'C':  
            check_connect();  
            break;  
        case 'S':  
            stop_connect();  
            break;  
        }  
    }  
    while(cp!='S');  
    return 0;  
}  
  
void input_connect()  
{  
    int a,b;  
    scanf("%d%d",&a,&b);  
    int root1 = finds(a-1);  
    int root2 = finds(b-1);  
    if(root1!=root2)  
    {  
        unions(root1,root2);  
    }  
}  
  
void check_connect()  
{  
    int a,b;  
    scanf("%d%d",&a,&b);  
    int root1 = finds(a-1);  
    int root2 = finds(b-1);  
    if(root1==root2)  
    {  
        printf("yes\n");  
    }  
    else  
    {  
        printf("no\n");  
    }  
}  
  
void stop_connect()  
{  
    int cnt = 0;  
    for(int i=0; i<N; i++)  
    {  
        if(s[i]<0)  
        {  
            cnt++;  
        }  
    }  
    if(cnt==1)  
    {  
        printf("The network is connected.\n");  
    }  
    else  
    {  
        printf("There are %d components.\n",cnt);  
    }  
}  
  
//用到了路径压缩  
int finds(int k)  
{  
    if(s[k]<0)  
    {  
        return k;  
    }  
    return s[k] = finds(s[k]);  
}  
  
//用到了按秩归并  
void unions(int root1,int root2)  
{  
    if(s[root1]<s[root2])  
    {  
        s[root2] = root1;  
    }  
    else if(s[root1]>s[root2])  
    {  
        s[root1] = root2;  
    }  
    else  
    {  
        s[root1] = root2;  
        s[root2]--;  
    }  
}

/**
05-树8 File Transfer（25 分）
We have a network of computers and a list of bi-directional connections. Each of these connections allows a file transfer from one computer to another. Is it possible to send a file from any computer on the network to any other?

Input Specification:

Each input file contains one test case. For each test case, the first line contains N (2≤N≤10
?4
?? ), the total number of computers in a network. Each computer in the network is then represented by a positive integer between 1 and N. Then in the following lines, the input is given in the format:

I c1 c2
where I stands for inputting a connection between c1 and c2; or

C c1 c2
where C stands for checking if it is possible to transfer files between c1 and c2; or

S
where S stands for stopping this case.

Output Specification:

For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2, respectively. At the end of each case, print in one line "The network is connected." if there is a path between any pair of computers; or "There are k components." where k is the number of connected components in this network.

Sample Input 1:

5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
Sample Output 1:

no
no
yes
There are 2 components.
Sample Input 2:

5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S
Sample Output 2:

no
no
yes
yes
The network is connected.
**/
