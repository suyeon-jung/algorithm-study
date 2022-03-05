#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * @brief 3) 단순 순회, 재귀
 *
 */

vector<int> adj[10];
void dfs(int cur, int par)
{
    cout << cur << ' ';
    for (int nxt : adj[cur])
    {
        if (par == nxt)
            continue;
        dfs(nxt, cur);
    }
}

// call dfs(1, 0);