#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, n1, n2, n3;
  int count = 1;
  cin >> n;
  int check = n;

  if (n < 0 || n > 99) {
    return 0;
  }

  while (1) {
    n1 = n / 10;
    n2 = n % 10;
    // n3 은 각 자릿수의 합
    n3 = n1 + n2;
    // 새로운 수
    n = n2 * 10 + n3 % 10;
    // 처음 입력값과 새로운 수가 같다면 사이클 종료
    if (n == check) break;
    count++;
  }
  cout << count;
  return 0;
}
