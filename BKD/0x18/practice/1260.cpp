#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_VERTEX 1005

bool vis[MAX_VERTEX];        // 방문 여부 기록
vector<int> adj[MAX_VERTEX]; // 인접리스트

/**
 * @brief 그래프
 * - 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다.
 * - 입력으로 주어지는 간선은 양방향이다.
 */
void dfs(int cur)
{
    vis[cur] = true;
    cout << cur << ' ';

    for (auto nxt : adj[cur])
    {
        if (vis[nxt])
            continue;
        dfs(nxt);
    }
}
void bfs(int start)
{
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur])
        {
            if (vis[nxt])
                continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int vertex_num, edge_num, start_vertex;

    cin >> vertex_num >> edge_num >> start_vertex;
    for (int i = 0; i < edge_num; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < MAX_VERTEX; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(start_vertex);
    cout << '\n';

    fill(vis, vis + MAX_VERTEX, false);

    bfs(start_vertex);

    return 0;
}