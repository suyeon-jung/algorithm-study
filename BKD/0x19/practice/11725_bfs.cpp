#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001 // 노드 개수의 최대값이 100000

int parent[MAX];      // parent
vector<int> adj[MAX]; // adjacent node

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur])
        {
            if (parent[cur] == nxt)
                continue; // 현재 정점의 부모 정점인 경우 넘어감
            // 부모가 아닌 경우 큐에 삽입
            q.push(nxt);
            parent[nxt] = cur;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int node_num;
    int vertex1, vertex2;

    cin >> node_num;

    for (int i = 1; i < node_num; i++)
    {
        cin >> vertex1 >> vertex2;
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);
    }

    bfs(1); // root(1)

    // output
    for (int i = 2; i <= node_num; i++)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}