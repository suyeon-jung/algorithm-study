#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 10005

vector<int> adj[MAX];
bool vis[MAX];
vector<int> ans;
int max_num;

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    vis[start] = true;

    int connect_num = 0;

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
            connect_num++;
        }
    }
    return connect_num;
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
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {

        int result = bfs(i);
        if (result > max_num)
        {
            ans.clear();
            ans.push_back(i);
            max_num = result;
        }
        else if (result == max_num)
        {
            ans.push_back(i);
        }
        fill(vis, vis + (n + 1), false);
    }

    sort(ans.begin(), ans.end());

    for (auto i : ans)
    {
        cout << i << ' ';
    }
}