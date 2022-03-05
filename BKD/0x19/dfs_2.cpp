#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * @brief 2) 부모와 depth 배열 채우기, 재귀
 * 스택 메모리가 1MB로 제한되어 있을 때 V가 대략 3만 이상일 때 일자 트리 모양에서 스택메모리 한계가 생김
 * 스택 메모리에 대한 제한이 있을 때 주의해야 함
 */

vector<int> adj[10];
int p[10]; // 각 정점의 부모 번호 저장(루트의 부모는 0)
int depth[10];
void dfs(int cur)
{
    cout << cur << ' ';
    for (int nxt : adj[cur])
    {
        if (p[cur] == nxt)
            continue; // 현재 정점의 부모 정점인 경우 넘어감
        // 부모가 아닌 경우 큐에 삽입
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt);
    }
}