#include <iostream>
using namespace std;

// 반복문 사용시 시간 초과 발생
// V-A가 되면 다음날 아침 목표지점 올라옴(거리,속력,시간 개념)

int main(int argc, char const *argv[]) {
  int a, b, v;
  int sum = 0;
  int day = 1;

  cin >> a >> b >> v;

  day += (v - a) / (a - b);

  if ((v - a) % (a - b) != 0) {
    day++;
  }

  // a가 v보다 크거나 같으면 하루안에 올라갈 수 있음
  if (a >= v) {
    day = 1;
  }
  cout << day;

  return 0;
}
