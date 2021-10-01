#include <cmath>
#include <iostream>
using namespace std;

// 소수는 n의 배수가 아니어야 한다는 조건
void primeNumberSieve(int number) {
  // 소수인지 기록(값이 0이 아니어야 소수임)
  int* primeNum = new int[number + 1];
  // 배열 초기화
  for (int i = 2; i <= number; i++) {
    primeNum[i] = i;
  }
  // 배수들 제외시키기
  for (int i = 2; i <= sqrt(number); i++) {
    if (primeNum[i] == 0) {  // primeNum[i]가 이미 0이면 소수가 아님
      continue;
    }
    for (int j = i * i; j <= number; j += i) {
      primeNum[j] = 0;
    }
  }

  for (int i = 2; i <= number; i++) {
    if (primeNum[i] != 0) {
      cout << primeNum[i] << "\n";
    }
  }
}
int main() { primeNumberSieve(120); }