#include <cmath>
#include <iostream>
using namespace std;

void solve();
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}

void solve() {
  int T;
  int x, y;

  cin >> T;

  while (T) {
    cin >> x >> y;

    // x, y 사이 거리
    int distance = y - x;
    int remain = 0;

    // distance안에 최대로 들어갈 수 있는 제곱수 찾기
    int base;
    for (base = 1;; base++) {
      if (distance < pow(base, 2)) {
        break;
      }
    }

    base -= 1;

    // 전체 거리 중 남은 거리
    remain = distance - pow(base, 2);

    int answer = 2 * base - 1 + ceil(double(remain) / base);
    cout << answer << "\n";

    T--;
  }
}