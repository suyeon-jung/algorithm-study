#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100005
int n;
int dp[MAX];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  dp[0] = 0; // 초기값 설정
  for (int i = 1; i <= n; i++)
  {
    dp[i] = dp[i - 1] + 1;
    for (int j = 1; j * j <= i; j++)
      dp[i] = min(dp[i], dp[i - j * j] + 1);
  }
  cout << dp[n];
}