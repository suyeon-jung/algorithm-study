#include <iostream>
using namespace std;

// 한수인지 검사
bool is_han_su(int n) {
  if (n < 100) return true;
  int a1, a2, a3;
  a1 = n / 100;
  a2 = n % 100 / 10;
  a3 = n % 10;

  if (a1 - a2 == a2 - a3) {
    return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int n, count = 0;
  cin >> n;

  if (n > 1000) return 0;

  // 1000은 한수가 아님
  for (int i = 0; i < n; i++) {
    if (is_han_su(i + 1)) {
      count++;
    }
  }
  cout << count;
  return 0;
}
