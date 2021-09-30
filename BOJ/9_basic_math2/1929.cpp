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
  cin >> M >> N;

  for (int i = M; i <= N; i++) {
    if (isPrime(i) == true) {
      cout << i << "\n";
    }
  }
}

bool isPrime(int n) {
  if (n == 1) {
    return false;
  }

  int limit = sqrt(n);
  for (int i = 2; i <= limit; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}