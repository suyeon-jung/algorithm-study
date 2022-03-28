#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 105

vector<int> adj[MAX];
bool vis[MAX];

int infect_num; // 바이러스에 걸리게 되는 컴퓨터의 수

void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = true;

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
            infect_num++;
        }
    }
}
void dfs(int cur)
{
    vis[cur] = true;

    for (auto nxt : adj[cur])
    {
        if (vis[nxt])
            continue;
        dfs(nxt);
        infect_num++;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int computer_num, pair_num;

    cin >> computer_num >> pair_num;

    for (int i = 0; i < pair_num; i++)
    {
        int computer1, computer2;
        cin >> computer1 >> computer2;
        adj[computer1].push_back(computer2);
        adj[computer2].push_back(computer1);
    }

    bfs();

    cout << infect_num;

    return 0;
}