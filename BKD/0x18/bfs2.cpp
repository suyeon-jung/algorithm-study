// 연결그래프에서의 1번 정점과의 거리
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[10]; // 인접 리스트
int dist[10];        // 방문 표시
void bfs()
{
    fill(dist, dist + 10, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[i])
        {
            if (dist[nxt] != -1) // 이미 방문했다면 넘어가기
                continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}