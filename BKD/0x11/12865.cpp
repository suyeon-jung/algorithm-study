#include <iostream>
#include <algorithm>
using namespace std;

int n, k;           // 물품 수, 버틸 수 있는 무게
int w[105], v[105]; // 각 물건의 무게, 해당 물건의 가치
int d[105][100005]; // [몇번째 물건, 무게 한도] 일때 optimal profit
/**
 * - wi <= w 일 때
 * d[i][w] = max(d[i-1][w-wi] + vi, d[i-1][w])
 * - wi > w 일 때
 * d[i][w] = d[i-1][w]
 */
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= k; j++)
    {
      if (w[i] <= j)
        d[i][j] = max(d[i - 1][j - w[i]] + v[i], d[i - 1][j]);
      else
        d[i][j] = d[i - 1][j];
    }
  }

  cout << d[n][k];
}