#include <cmath>
#include <iostream>
using namespace std;

void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
void solve() {
  int r;
  double pi = M_PI;

  cin >> r;

  // 소수점 아래 자리수를 6자리로 고정
  cout << fixed;
  cout.precision(6);
  cout << pi * r * r << "\n";
  cout << 2.0 * r * r << "\n";
}