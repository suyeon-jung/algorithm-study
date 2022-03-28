#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 505

vector<int> adj[MAX];
int vis[MAX];
int ans;

void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur])
        {
            if (vis[nxt] || vis[cur] >= 3)
                continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
            ans++;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m; // 동기의 수, 리스트의 길이
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();
    cout << ans;
    return 0;
}