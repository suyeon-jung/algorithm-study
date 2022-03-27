// 연결그래프에서의 순회, 비재귀2(스택 메모리 제한 있을때)
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
        if (vis[cur])
            continue;
        vis[cur] = true;
        cout << cur << ' ';
        for (auto nxt : adj[cur])
        {
            if (vis[nxt]) // 이미 방문했다면 넘어가기
                continue;
            s.push(nxt);
        }
    }
}