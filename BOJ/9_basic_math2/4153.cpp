#include <cmath>
#include <iostream>
using namespace std;

void solve();
void swap(int& a, int& b);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
void solve() {
  while (1) {
    int a, b, c;
    int temp;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) {
      break;
    }

    // 제일 큰 수 찾아야 함
    if (a > b) {
      swap(a, b);
    }
    if (b > c) {
      swap(b, c);
    }

    // 피타고라스 정리를 만족한다면
    if (pow(c, 2) == pow(a, 2) + pow(b, 2)) {
      cout << "right"
           << "\n";
    } else {
      cout << "wrong"
           << "\n";
    }
  }
}
void swap(int& a, int& b) {
  int tmp;

  tmp = b;
  b = a;
  a = tmp;
}