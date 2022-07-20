#include <iostream>
#include <algorithm>
using namespace std;

int n;
int rope[100005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> rope[i];
  }
  sort(rope, rope + n);

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, rope[i] * (n - i));
  }
  cout << ans;
}