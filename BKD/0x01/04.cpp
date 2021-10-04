/*
 *  N 이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수
 */
#include <iostream>
using namespace std;

int func4(int N);
int main() {
  cout << func4(5) << "\n";
  cout << func4(97615282) << "\n";
  cout << func4(1024) << "\n";
  return 0;
}
int func4(int N) {
  int val = 1;
  while (2 * val <= N) {
    val *= 2;
  }
  return val;
}