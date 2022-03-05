#include <iostream>
#include <queue>
using namespace std;

// 현재 정점이 인덱스 번호라고 생각(root = 0)
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0}; // left child
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0}; // right child

void bfs()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        if (lc[cur])
            q.push(lc[cur]);
        if (rc[cur])
            q.push(rc[cur]);
    }
}