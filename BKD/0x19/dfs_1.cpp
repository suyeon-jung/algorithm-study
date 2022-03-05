#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * @brief 1) 부모와 depth 배열 채우기, 비재귀
 *
 */

vector<int> adj[10];
int p[10]; // 각 정점의 부모 번호 저장(루트의 부모는 0)
int depth[10];
void dfs(int root)
{
    stack<int> s;
    s.push(root);
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur])
        {
            if (p[cur] == nxt)
                continue; // 현재 정점의 부모 정점인 경우 넘어감
            // 부모가 아닌 경우 큐에 삽입
            s.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}