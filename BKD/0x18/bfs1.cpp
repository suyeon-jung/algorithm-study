// 연결그래프에서의 순회
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[10]; // 인접 리스트
bool vis[10];        // 방문 표시
void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur])
        {
            if (vis[nxt]) // 이미 방문했다면 넘어가기
                continue;
            q.push(nxt);
            vis[nxt] = true; // 큐에 넣은 직후 방문 여부 기록
        }
    }
}