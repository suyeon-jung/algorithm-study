#include <cmath>
#include <iostream>
using namespace std;

void solve();
bool isPrime(int n);

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}

void solve() {
  int M, N;
  int min, sum = 0;

  cin >> M >> N;

  for (int i = M; i <= N; i++) {
    // i가 소수인지 검사
    if (isPrime(i)) {
      min = (sum == 0 ? i : min);
      sum += i;
    }
  }

  if (!sum) {
    cout << -1;
  } else {
    cout << sum << "\n" << min << "\n";
  }
}

bool isPrime(int n) {
  if (n == 1) {
    return false;
  }

  int limit = sqrt(n);

  for (int i = 2; i <= limit; i++) {
    // 하나라도 약수인게 있으면 소수가 아님
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}