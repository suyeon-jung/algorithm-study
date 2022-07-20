#include <iostream>
using namespace std;

int n, k;
int a[15]; // 동전의 가치 배열

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = 0; // 동전의 최소 개수
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = n - 1; i >= 0; i--)
  {
    ans += k / a[i];
    k %= a[i];
  }
  cout << ans;
}