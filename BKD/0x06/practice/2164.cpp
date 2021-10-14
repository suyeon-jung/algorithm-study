#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> Q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) Q.push(i);
  // 1. 카드 버리기
  // 2. 제일 위 카드를 제일 아래로 옮기기
  while (Q.size() > 1) {
    Q.pop();
    int tmp = Q.front();
    Q.pop();
    Q.push(tmp);
  }

  cout << Q.front();
}
