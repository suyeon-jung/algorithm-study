#include <bits/stdc++.h>
using namespace std;
#define X first;
#define Y second;
int dist[100002];
int n, k;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;                  // 수빈 위치, 동생 위치
  fill(dist, dist + 100002, -1);  // -1로 초기화
  dist[n] = 0;
  queue<int> Q;
  Q.push(n);
  while (dist[k] == -1) {  // k 위치를 찾으면 while 빠져나가기
    int cur = Q.front();
    Q.pop();
    for (int nxt : {cur - 1, cur + 1, cur * 2}) {
      if (nxt < 0 || nxt > 100000) continue;
      if (dist[nxt] != -1) continue;  // 이미 방문
      dist[nxt] = dist[cur] + 1;
      Q.push(nxt);
    }
  }

  cout << dist[k];
}