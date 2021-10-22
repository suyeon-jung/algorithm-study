/*
  오름차순 priority_queue<int, vector<int>, greater<int>> q;
  내림차순 default
  배열로 구현해야 함
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  priority_queue<int, vector<int>> q;
  while (n--) {
    int val;
    cin >> val;
    if (val == 0) {
      if (q.empty()) {
        cout << 0 << '\n';
      } else {
        // 배열에서 큰 값 출력
        cout << q.top() << '\n';
        // 그 값 배열에서 제거
        q.pop();
      }
    }
    q.push(val);
  }
}