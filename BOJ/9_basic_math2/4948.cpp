#include <cmath>
#include <iostream>
using namespace std;

void solve();
int countPrimeNum(int n);
bool isPrime(int n);
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
void solve() {
  int n;
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    cout << countPrimeNum(n) << "\n";
  }
}
int countPrimeNum(int n) {
  int count = 0;

  // n~2n 까지 소수인지 검사
  for (int i = n + 1; i <= 2 * n; i++) {
    if (isPrime(i)) {
      count++;
    }
  }
  return count;
}
bool isPrime(int n) {
  int limit = sqrt(n);

  if (n == 1) {
    return false;
  }
  for (int i = 2; i <= limit; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}