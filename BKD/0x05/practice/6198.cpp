#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAX 1000000005

stack<pair<int, int>> tower; // (index, height)
long long ans;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<int> h;
  for (int i = 0; i < N; i++)
  {
    int height;
    cin >> height;
    h.push_back(height);
  }

  tower.push({N, MAX});
  for (int i = N - 1; i >= 0; i--)
  {
    while (tower.top().second < h[i])
      tower.pop();
    ans += tower.top().first - i - 1;
    tower.push({i, h[i]});
  }
  cout << ans;
}