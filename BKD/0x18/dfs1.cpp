// 연결그래프에서의 순회, 비재귀
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> adj[10]; // 인접 리스트
bool vis[10];        // 방문 표시
void dfs()
{
    stack<int> s;
    s.push(1);
    vis[1] = true;
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur])
        {
            if (vis[nxt]) // 이미 방문했다면 넘어가기
                continue;
            s.push(nxt);
            vis[nxt] = true; // 스택에 넣은 직후 방문 여부 기록
        }
    }
}