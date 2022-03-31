#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 105

vector<int> ans_user; // 케빈 케이컨의 수가 가장 작은 사람들
vector<int> adj[MAX];
int vis[MAX];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    vis[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur])
        {
            if (vis[nxt] || nxt == start)
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

    int user_num, relation_num;

    cin >> user_num >> relation_num;
    for (int i = 0; i < relation_num; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int min = MAX;
    for (int i = 1; i <= user_num; i++)
    {
        bfs(i);

        // 케빈 베이컨 수 출력
        int ans = 0;
        for (int j = 1; j <= user_num; j++)
        {
            ans += vis[j];
        }
        if (ans < min)
        {
            ans_user.clear();
            min = ans;
            ans_user.push_back(i);
        }
        else if (ans == min)
        {
            ans_user.push_back(i);
        }

        fill(vis, vis + (user_num + 1), 0);
    }

    sort(ans_user.begin(), ans_user.end());
    cout << ans_user[0];

    return 0;
}