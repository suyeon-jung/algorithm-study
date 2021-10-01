#include <cmath>
#include <iostream>
using namespace std;

void solve();
int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
void solve() {
  int n, min, max, cnt;
  while (1) {
    cin >> n;
    if (!n) {  // 0을 입력하면 프로그램 종료
      break;
    }

    min = n + 1;
    max = 2 * n;
    cnt = 0;

    // 에라토스테네스의 체
    bool* primeNum = new bool[max + 1];
    fill_n(primeNum, max + 1, true);

    primeNum[0] = false;
    primeNum[1] = false;

    for (int i = 2; i <= sqrt(max); i++) {
      if (primeNum[i] == false) {
        continue;
      }
      for (int j = i * i; j <= max; j += i) {
        primeNum[j] = false;
      }
    }

    for (int i = min; i <= max; i++) {
      if (primeNum[i]) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}