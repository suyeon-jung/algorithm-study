#include <cmath>
#include <iostream>
using namespace std;

void solve();
int getPrimeNum(int start, int n);
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}

void solve() {
  int N;
  cin >> N;

  int prime = 2;
  // N이 1이 되는 순간 종료
  while (N > 1) {
    // 2부터 시작해서 더이상 나눠지지 않을때까지 같은 수로 계속 나눠
    if (N % prime == 0) {  // 나눠지는 경우
      cout << prime << "\n";
    } else {  // 안 나눠지는 경우
      prime = getPrimeNum(prime + 1, N);
    }
    N /= prime;
  }
}
int getPrimeNum(int start, int n) {
  for (int i = start; i <= n; i++) {
    if (n % i == 0) {
      cout << i << "\n";
      return i;
    }
  }
  return 0;
}
