#include <algorithm>
#include <iostream>
using namespace std;
int card[21];
int pre, nxt;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // card 초기화
  for (int i = 1; i <= 20; i++) card[i] = i;

  // 사용자 입력
  for (int i = 1; i <= 10; i++) {
    cin >> pre >> nxt;
    reverse(card + pre, card + nxt + 1);
  }
  for (int i = 1; i <= 20; i++) cout << card[i] << ' ';
}