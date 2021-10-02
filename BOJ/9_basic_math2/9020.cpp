#include <cmath>
#include <iostream>
using namespace std;

void solve();
bool is_prime(int num);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
void solve() {
  int T;
  // 테스트케이스 개수 입력
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int input;
    cin >> input;

    // 가장 차가 적게되는 경우부터 탐색
    for (int i = (input / 2); i >= 2; i--) {
      if (is_prime(i) && is_prime(input - i)) {
        cout << i << " " << input - i << "\n";
        break;
      }
    }
  }
}

bool is_prime(int num) {
  int rt = sqrt(num);

  // 2, 3 인 경우
  if (rt == 1 && num != 1) {
    return true;
  }

  // 짝수인 경우는 2의 배수이기 때문에 소수가 될 수 없음
  if (num % 2) {
    for (int i = 2; i <= rt; i++) {
      if (!(num % i)) return false;
      if (i == rt) return true;
    }
  }
  return false;
}