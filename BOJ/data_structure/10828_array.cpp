#include <iostream>
using namespace std;

const int MX = 10005;
int arr[MX];  // 스택
int cur;      // top 의 인덱스(아무것도 없는 상태 : 0)

// (1) 배열로 구현
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  int N;
  cin >> N;

  string comm;
  for (int i = 0; i < N; i++) {
    cin >> comm;
    if (comm == "push") {
      cin >> num;
      arr[cur++] = num;
    } else if (comm == "pop") {
      if (!cur) {
        cout << -1 << '\n';
      } else {
        cur--;
        cout << arr[cur] << '\n';
      }

    } else if (comm == "size") {
      cout << cur << '\n';
    } else if (comm == "empty") {
      if (!cur)
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (comm == "top") {
      if (!cur) {
        cout << -1 << '\n';
      } else {
        cout << arr[cur - 1] << '\n';
      }
    }
  }
}