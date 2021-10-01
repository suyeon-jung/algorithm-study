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
  int M, N;
  bool* primeNum;
  cin >> M >> N;

  // 소수 판별
  primeNum = new bool[N + 1];
  // 배열 초기화(memset(primeNum, true, N+1)  해도 됨)
  fill_n(primeNum, N + 1, true);

  primeNum[0] = false;
  primeNum[1] = false;

  for (int i = 2; i <= sqrt(N); i++) {
    if (primeNum[i] == false) {
      continue;
    }

    for (int j = i * i; j <= N; j += i) {
      primeNum[j] = false;
    }
  }
  // 소수 판별

  for (int i = M; i <= N; i++) {
    if (primeNum[i]) {
      cout << i << "\n";
    }
  }
}
