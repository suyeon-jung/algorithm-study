#include <iostream>
using namespace std;

// 한수인지 검사
bool is_han_su(int n) {
  int prev, next, base = 0, diff;
  if ((n / 100) < 1)
    return true;
  else {
    // 초기 설정
    prev = n % 10;
    n = n / 10;
    next = n % 10;

    base = prev - next;
    cout << "base " << base << endl;

    while (n > 10) {
      prev = n % 10;
      n = n / 10;
      next = n % 10;

      diff = prev - next;
      if (diff != base) return false;
      cout << "2 " << diff << endl;
    }
    cout << base << "\n";
    return true;
  }
}

int main(int argc, char const *argv[]) {
  int n = 998, count = 0;
  cin >> n;
  if (n > 1000) return 0;
  cout << "ddd" << is_han_su(n) << endl;
  // for (int i = 0; i < n; i++) {
  //   int diff = 0;
  //   int prev, next;
  //   while (i > 0) {
  //     prev = (i + 1) / 10;
  //     next = (i + 1) / 10 / 10;
  //     diff = abs(prev - next);
  //     cout << diff << "\n";
  //     i /= 10;
  //   }
  // }
  return 0;
}
