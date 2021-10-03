#include <iostream>
using namespace std;

int func1(int N);
int main() {
  int N;
  cin >> N;

  cout << func1(N) << "\n";
  return 0;
}
int func1(int N) {
  int ret = 0;

  for (int i = 1; i <= N; i++) {
    if (i % 3 == 0 || i % 5 == 0) ret += i;
  }
  return ret;
}