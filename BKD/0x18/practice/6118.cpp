#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 20005

vector<int> adj[MAX];
int vis[MAX];
vector<int> ans;

void bfs()
{
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur])
        {
            if (vis[nxt] || nxt == 1)
                continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();

    int max_dis = -1;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] > max_dis)
        {
            ans.clear();
            ans.push_back(i);
            max_dis = vis[i];
        }
        else if (vis[i] == max_dis)
        {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[0] << ' ' << vis[ans[0]] << ' ' << ans.size();

    return 0;
}