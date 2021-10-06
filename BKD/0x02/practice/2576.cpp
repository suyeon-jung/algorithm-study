#include <algorithm>
#include <iostream>
using namespace std;
// 최소값 문제에서 입력하는 수의 최대 범위에 주목해야 함

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // count : 홀수 개수
  // sum : 홀수 합
  int input, sum = 0, min = 100;
  for (int i = 0; i < 7; i++) {
    cin >> input;

    if (input & 1) {
      sum += input;
      min = input < min ? input : min;
    }
  }
  if (!sum)
    cout << -1;
  else
    cout << sum << '\n' << min;
}