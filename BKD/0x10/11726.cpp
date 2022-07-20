#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1005]; // d[i] = 2*i 크기의 직사각형을 1*2, 2*1 타일로 채우는 방법의 수
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  d[1] = 1;
  d[2] = 2;
  if (n > 2)
  {
    for (int i = 3; i <= n; i++)
    {
      d[i] = (d[i - 1] + d[i - 2]) % 10007;
    }
  }
  cout << d[n];
}