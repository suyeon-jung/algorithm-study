#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 105

vector<int> adj[MAX];
bool vis[MAX];
int n;

void bfs(int start)
{
    queue<int> q;
    q.push(start);

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
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ipt;
            cin >> ipt;
            if (ipt)
                adj[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // bfs
        bfs(i);

        // vis 배열 출력
        for (int j = 1; j <= n; j++)
        {
            cout << vis[j] << ' ';
        }
        cout << '\n';

        // vis 초기화
        fill(vis, vis + (n + 1), false);
    }

    return 0;
}