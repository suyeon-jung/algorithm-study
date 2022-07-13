#include <iostream>
using namespace std;
using ll = long long;

// 1. int overflow 가 발생하는 풀이
int func1(int a, int b, int m)
{
  int val = 1;
  while (b--)
    val *= a;
  return val % m;
}
// 2. int overflow를 고려한 풀이(곱할때마다 mod 계산 진행) -> m이 2^32보다 크다면 오버플로 발생(long long 2^64)
ll func2(ll a, ll b, ll m)
{
  ll val = 1;
  while (b--)
    val = val * a % m;
  return val;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
}