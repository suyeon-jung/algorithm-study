// 연결그래프에서의 순회, 재귀
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[10]; // 인접 리스트
bool vis[10];        // 방문 표시
void dfs(int cur)
{
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adj[cur])
    {
        if (vis[nxt]) // 이미 방문했다면 넘어가기
            continue;
        dfs(nxt);
    }
}