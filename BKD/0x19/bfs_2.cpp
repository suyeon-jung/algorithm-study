#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @brief 1) 부모와 depth 배열 채우기
 * 자식의 depth = 부모의 depth + 1 활용
 */

vector<int> adj[10];
int p[10]; // 각 정점의 부모 번호 저장(루트의 부모는 0)
int depth[10];
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur])
        {
            if (p[cur] == nxt)
                continue; // 현재 정점의 부모 정점인 경우 넘어감
            // 부모가 아닌 경우 큐에 삽입
            q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}