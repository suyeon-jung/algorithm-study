#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100005

int n, m;
int a[MAX];
int d[MAX];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int k = 1; k <= n; k++)
  {
    cin >> a[k];
    d[k] = d[k - 1] + a[k];
  }

  for (int k = 0; k < m; k++)
  {
    int i, j;
    cin >> i >> j;
    cout << d[j] - d[i - 1] << '\n';
  }
}