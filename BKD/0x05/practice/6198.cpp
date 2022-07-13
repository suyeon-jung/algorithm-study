#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> h;
    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;
        h.push_back({height, i});
    }

    int ans = 0;
    for (int i = 0; i < N; i++) // 벡터를 뒤에서부터 순회
    {
        stack<pair<int, int>> tower;
        for (int j = i + 1; j < N; j++)
        {
            if (h[j].first < h[i].first)
                tower.push(h[j]);
            else
                break;
        }
        // cout << tower.size() << '\n';
        ans += tower.size();
    }
    cout << ans;
}