#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001 // 노드 개수의 최대값이 100000

int node_num;
int parent[MAX];      // parent(각 정점의 부모 노드)
vector<int> adj[MAX]; // adjacent node(각 정점에서 연결된 노드)

void dfs(int cur)
{
    for (int nxt : adj[cur])
    {
        if (parent[cur] == nxt)
            continue; // 현재 정점의 부모 정점인 경우 넘어감
        parent[nxt] = cur;
        dfs(nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int vertex1, vertex2;

    cin >> node_num;
    for (int i = 1; i < node_num; i++)
    {
        cin >> vertex1 >> vertex2;
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);
    }

    dfs(1); // root(1)

    // output
    for (int i = 2; i <= node_num; i++)
        cout << parent[i] << '\n';

    return 0;
}