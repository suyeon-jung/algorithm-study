#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100005

int n; // 거스름돈 액수
int DP[MAX];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  fill(DP, DP + n + 1, -1);

  DP[2] = 1;
  DP[4] = 2;
  DP[5] = 1;

  for (int i = 6; i <= n; i++)
  {

    if (DP[i - 2] == -1 && DP[i - 5] == -1)
      continue;
    else if (DP[i - 2] == -1)
      DP[i] = DP[i - 5] + 1;
    else if (DP[i - 5] == -1)
      DP[i] = DP[i - 2] + 1;
    else
      DP[i] = min(DP[i - 2] + 1, DP[i - 5] + 1);
  }

  cout << DP[n];
  return 0;
}