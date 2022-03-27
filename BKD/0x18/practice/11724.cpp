// bfs, dfs - 재귀, dfs - 비재귀
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VERTEX 1001

int n, m;      // 정점, 간선이 개수
int component; // 연결 요소의 개수

vector<int> adj[MAX_VERTEX]; // 인접 리스트
bool vis[MAX_VERTEX];        // 방문 여부

void bfs()
{

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        // 시작점 삽입
        queue<int> q;
        q.push(i);
        vis[i] = true;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj[cur])
            {
                if (vis[nxt])
                    continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
        component++;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    // 그래프 입력 처리
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();

    cout << component;

    return 0;
}