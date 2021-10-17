#include <bits/stdc++.h>
using namespace std;

int n, m;  // n: 큐에 처음에 포함되어 있던 수, m: 뽑아내려고 하는 수

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  deque<int> DQ;
  for (int i = 1; i <= n; i++) DQ.push_back(i);
  int min = 0;
  while (m--) {
    int val;
    cin >> val;
    int idx;
    // 덱의 첫번째 숫자와 입력값이 같아질때까지 반복
    while (DQ.front() != val) {
      for (int i = 0; i < DQ.size();
           i++) {  // 입력한 수가 어디 위치에 있는지 찾기
        if (DQ[i] == val) {
          idx = i;
          break;
        }
      }
      if (idx <= (DQ.size() / 2)) {  // idx 범위가 0~4라면 2번 연산
        DQ.push_back(DQ.front());
        DQ.pop_front();
      } else {  // idx 범위가 5~9라면 3번 연산
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }
      min++;
    }
    // 현재 front()가 입력한 수랑 같은 상태이므로 추출
    DQ.pop_front();
  }
  cout << min;
}