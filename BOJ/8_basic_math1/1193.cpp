#include <iostream>
using namespace std;

// while 방식 시간초과 발생
int main(int argc, char const *argv[]) {
  int input;
  cin >> input;

  int i = 1;
  // 1. input이 몇번째 대각선인지 확인
  while (input > i) {
    input -= i;
    i++;
  }

  // 2. 분수 구하기
  if (i % 2 == 0) {
    cout << input << "/" << i + 1 - input;
  } else {
    cout << i + 1 - input << "/" << input;
  }

  // int sum = 1;
  // int plus = 1;

  // while (1) {
  //   if (sum >= input) {
  //     break;
  //   }
  //   plus++;
  //   sum += plus;
  // }
  // // 분자, 분모
  // int numerator, denominator;
  // if (plus % 2 == 0) {
  //   numerator = plus;
  //   denominator = 1;
  //   for (int i = sum; i > input; i--) {
  //     numerator--;
  //     denominator++;
  //   }
  // } else {
  //   numerator = 1;
  //   denominator = plus;
  //   for (int i = sum; i > input; i--) {
  //     numerator++;
  //     denominator--;
  //   }
  // }

  // cout << numerator << "/" << denominator;

  return 0;
}
