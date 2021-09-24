#include <cmath>
#include <iostream>
using namespace std;

void solve();
bool isPrime(int n);

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
void solve() {
  int N, count = 0;
  cin >> N;

  while (N) {
    int input;
    cin >> input;

    if (isPrime(input)) {
      count++;
    }
    N--;
  }
  cout << count;
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
