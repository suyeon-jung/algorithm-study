#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int t, m, n, k;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;  // 테스트 케이스 개수

  while (t--) {
    cin >> m >> n >> k;  // 가로, 세로, 배추 심어져있는 위치 개수 입력
    int board[55][55];
    bool vis[55][55];
    for (int i = 0; i < 55; i++) {  // 배열 초기화
      fill(board[i], board[i] + 55, 0);
      fill(vis[i], vis[i] + 55, 0);
    }
    while (k--) {  // 배추 좌표 입력받기
      int x, y;
      cin >> x >> y;
      board[x][y] = 1;
    }
    /*
    1. 배추 심어져 있는 땅 찾기(board값이 1인 칸)
          2. bfs 수행하면서 vis값 1로 남기기
     */
    int ans = 0;              // 배추 흰지렁이 마리수
    queue<pair<int, int>> Q;  // 탐색 노드 담는 큐
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] &&
            !vis[i][j]) {  // board값이 1이거나 방문하지 않은 경우
          ans++;
          vis[i][j] = 1;
          Q.push({i, j});
          while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++) {
              int nx = cur.X + dx[dir];
              int ny = cur.Y + dy[dir];
              if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
              if (vis[nx][ny] || board[nx][ny] != 1) continue;
              vis[nx][ny] = 1;
              Q.push({nx, ny});
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
}