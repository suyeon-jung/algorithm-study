#include <algorithm>
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
  int x, y, w, h;
  int tmp1, tmp2;

  cin >> x >> y >> w >> h;

  tmp1 = min(x, w - x);
  tmp2 = min(y, h - y);

  cout << min(tmp1, tmp2) << "\n";
}