#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20005
#define RED 1
#define BLUE 2

vector<int> adj[MAX];
int vis[MAX]; // 0-방문 안함, 1-1번 집합, 2-2번 집합
int vertex_num, edge_num;

bool isBipartite()
{
    queue<int> q;

    for (int i = 1; i <= vertex_num; i++) // 비연결 그래프인 경우 고려
    {
        if (vis[i])
            continue;
        q.push(i);
        vis[i] = RED;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj[cur])
            {
                if (vis[nxt]) // 이미 방문 한 곳
                {
                    if (vis[nxt] == vis[cur])
                        return false;
                    continue;
                }
                q.push(nxt);
                if (vis[cur] == RED)
                    vis[nxt] = BLUE;
                else if (vis[cur] == BLUE)
                    vis[nxt] = RED;
            }
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;

    while (test_case--)
    {
        cin >> vertex_num >> edge_num;
        for (int i = 0; i < edge_num; i++) // 간선 정보 입력
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 이분 그래프인지 출력(YES, NO)
        bool result = isBipartite();

        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";

        // 초기화
        fill(vis, vis + (vertex_num + 1), 0);
        for (int i = 1; i <= vertex_num; i++)
        {
            adj[i].clear();
        }
    }
}