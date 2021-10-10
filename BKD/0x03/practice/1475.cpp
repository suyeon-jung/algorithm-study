#include <algorithm>
#include <iostream>
using namespace std;

int num[10];
int ans = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  // 자리수 추출
  for (char c : s) num[c - '0']++;

  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9) continue;
    ans = max(ans, num[i]);
  }

  // (num[6] + num[9]) / 2의 올림 값이 6, 9 표현하는데 필요한 세트수
  ans = max(ans, (num[6] + num[9] + 1) / 2);

  cout << ans;
}