// 연결그래프가 아닐 때 순회
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[10]; // 인접 리스트
bool vis[10];        // 방문 표시
int v = 9;           // 정점의 수
void bfs()
{
    queue<int> q;

    for (int i = 1; i <= v; i++)
    {
        // 아직 방문하지 않은 정점을 시작점으로 설정
        if (vis[i])
            continue;
        q.push(i);
        vis[i] = true;

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
}