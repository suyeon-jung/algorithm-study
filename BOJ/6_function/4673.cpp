#include <iostream>
#define N 10001

using namespace std;
bool arr[N];

int d(int n) {
  // n 과 각 자리수의 합
  int result = n;
  // n의 자리수에 따라서 result 계산 다르게 해줘야 함
  while (n > 0) {
    result += n % 10;
    n /= 10;
  }
  return result;
}
int main(int argc, char const *argv[]) {
  for (int i = 1; i < N; i++) {
    int self_number = d(i);
    if (self_number <= N) {
      arr[self_number] = true;
    }
  }

  for (int i = 1; i < N; i++) {
    if (!arr[i]) cout << i << "\n";
  }

  return 0;
}
