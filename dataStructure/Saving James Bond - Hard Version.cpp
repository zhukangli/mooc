/**

07-ͼ5 Saving James Bond - Hard Version��30 �֣�
This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. He was sent to a small piece of land at the center of a lake filled with crocodiles. There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile! Before the animal realized what was happening, James jumped again onto the next big head... Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).

Assume that the lake is a 100 by 100 square one. Assume that the center of the lake is at (0,0) and the northeast corner at (50,50). The central island is a disk centered at (0,0) with the diameter of 15. A number of crocodiles are in the lake at various positions. Given the coordinates of each crocodile and the distance that James could jump, you must tell him a shortest path to reach one of the banks. The length of a path is the number of jumps that James has to make.

Input Specification:

Each input file contains one test case. Each case starts with a line containing two positive integers N (��100), the number of crocodiles, and D, the maximum distance that James could jump. Then N lines follow, each containing the (x,y) location of a crocodile. Note that no two crocodiles are staying at the same position.

Output Specification:

For each test case, if James can escape, output in one line the minimum number of jumps he must make. Then starting from the next line, output the position (x,y) of each crocodile on the path, each pair in one line, from the island to the bank. If it is impossible for James to escape that way, simply give him 0 as the number of jumps. If there are many shortest paths, just output the one with the minimum first jump, which is guaranteed to be unique.

Sample Input 1:

17 15
10 -21
10 21
-40 10
30 -50
20 40
35 10
0 -10
-25 22
40 -40
-30 30
-10 22
0 11
25 21
25 10
10 10
10 35
-30 10
Sample Output 1:

4
0 11
10 21
10 35
Sample Input 2:

4 13
-12 12
12 12
-12 -12
12 -12
Sample Output 2:

0
**/


#include "iostream"
#include "math.h"
#include "queue"
#include "stack"
#include "algorithm"
using namespace std;
int n, m;
#define MINLEN 42.5
struct Pointer {
    int x;
    int y;
}point[101];
bool answer = false; /* ��¼007�ܷ�ȫ����~~ */
bool visited[101] = { false }; /* �жϵ�ǰ���Ƿ񱻷��ʹ� */
int path[101] = {-1}; /* ��¼��Ծ�����вȹ������� */
bool isSave(int x) { /* �жϴӵ�ǰ���ܷ��������� */
    if ((point[x].x - m <= -50) || (point[x].x + m >= 50) || (point[x].y - m <= -50) || (point[x].y + m >= 50))
        return true;
    return false;
}

bool jump(int x, int y) { /* �ж�2��������Ƿ�����Ծ������ */
    int p1 = pow(point[x].x - point[y].x, 2);
    int p2 = pow(point[x].y - point[y].y, 2);
    int r = m * m;
    if (p1 + p2 <= r)
        return true;
    return false;
}

int firstJump(int x) {  /* ��007���ڹµ�ʱ ��һ�ο���ѡ���������� ��Ϊ��һ���ж��ܷ���Ծ�ļ��㷽�������dfs����ͬ ����Ҫ����д */
    int p1 = pow(point[x].x, 2);
    int p2 = pow(point[x].y, 2);
    int r = (m + 7.5) * (m + 7.5);
    if (p1 + p2 <= r) {
        return p1+p2;
    }
    return 0;
}
bool cmp(int a,int b) {
    return firstJump(a) < firstJump(b);
}
void bfs() { /* ��bfs���ж�����Ҫ�ȼ���С��������ϰ� */
    int b[101];
    queue<int>q; 
    /* ����һ���ܲȵ������㰴�����С�����˳�������~ ��Ϊ������Ҫ��֤�ڲȵ�����������ȵ������ �����һ��������̵�~~*/
    for (int i = 0; i < n; i++) {
        b[i] = i;
    }
    sort(b, b + n, cmp); /* ���յ�һ���ľ�������~~~ */
    int last;
    for (int i = 0; i < n; i++) {
        if (firstJump(b[i])) { /* ������ȥ�� */
            q.push(b[i]);
            visited[b[i]] = true; /* ָ��ǰ�������һ����~ */
            last = b[i];
        }
    }
    int step = 2;  /* ��¼����Ҫ��Ծ�Ĵ��� */
    int tail; 
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (isSave(p)) {
            int k = 1;
            stack<int> s;
            cout << step << endl;
            while (k < step) {
                //cout << point[p].x << " " << point[p].y << endl;
                s.push(p);
                p = path[p];
                k++;
            }
            while (!s.empty()) {
                p = s.top();
                s.pop();
                cout << point[p].x << " " << point[p].y << endl;
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i] && jump(p, i)) { /* û�ȹ����������� */
                q.push(i);
                path[i] = p; /* �ǵõ�ǰ���ӽڵ�ĸ��ڵ�~ */
                visited[i] = true;
                tail = i; /* ָ����һ������һ��Ԫ�� */
            }
        }
        if (last == p) { /* ����������һ��~ */
            step += 1;
            last = tail;
        }
    }
    if (q.empty()) { /* �������Ϊ��  ˵��û����ȥ��~ */
        cout << "0" << endl;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    if (m >= MINLEN) { /* ����ֱ�Ӵӹµ����ᵽ���� ֱ����� */
        cout << "1" << endl;
        return 0;
    }
    bfs();
    return 0;
}
