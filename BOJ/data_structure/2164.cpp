#include <bits/stdc++.h>
using namespace std;

int N;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> Q;
  cin >> N;
  for (int i = 1; i <= N; i++) Q.push(i);

  // 1. 카드 버리기
  // 2. 제일 위 카드를 제일 아래로 옮기기
  while (Q.size() > 1) {
    Q.pop();
    int front = Q.front();
    Q.pop();
    Q.push(front);
  }

  cout << Q.front();
}
