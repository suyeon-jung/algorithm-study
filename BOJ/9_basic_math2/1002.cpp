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
  int T;
  cin >> T;

  while (T) {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int d, add, sub;
    // 중점 사이 거리
    d = pow(x1 - x2, 2) + pow(y1 - y2, 2);

    // 반지름 합
    add = pow(r1 + r2, 2);
    // 반지름 차
    sub = pow(r1 - r2, 2);

    if (d == 0 && r1 == r2) {  // 동심원인 경우
      if (r1 == r2) {
        cout << -1;
      } else {
        cout << 0;
      }
    } else if ((d > add) || (d < sub)) {
      cout << 0;
    } else if ((d == add) || (d == sub)) {
      cout << 1;
    } else if (sub < d && d < add) {
      cout << 2;
    }
    cout << "\n";

    T--;
  }
}