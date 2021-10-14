#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int j_dist[1002][1002];  // 지훈이의 이동 시간
int f_dist[1002][1002];  // 불의 전파 시간 기록
int r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    fill(j_dist[i], j_dist[i] + c, -1);
    fill(f_dist[i], f_dist[i] + c, -1);
  }

  for (int i = 0; i < r; i++) {
    cin >> board[i];
  }
  queue<pair<int, int>> J;  // 지훈 큐
  queue<pair<int, int>> F;  // 불 큐
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[i][j] == 'J') {
        j_dist[i][j] = 0;
        J.push({i, j});
      } else if (board[i][j] == 'F') {
        f_dist[i][j] = 0;
        F.push({i, j});
      }
    }
  }

  // 1. 불에 대한 BFS 수행
  while (!F.empty()) {
    auto cur = F.front();
    F.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (board[nx][ny] == '#' || f_dist[nx][ny] >= 0)
        continue;  // 벽이거나 이미 방문
      f_dist[nx][ny] = f_dist[cur.X][cur.Y] + 1;
      F.push({nx, ny});
    }
  }
  // 2. 지훈이에 대한 BFS 수행
  while (!J.empty()) {
    auto cur = J.front();
    J.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= r || ny < 0 || ny >= c) {  // 범위를 벗어난 것 = 탈출
        cout << j_dist[cur.X][cur.Y] + 1;
        return 0;
      }
      if (board[nx][ny] == '#' || j_dist[nx][ny] >= 0)
        continue;  // 벽이거나 이미 방문
      if (f_dist[nx][ny] != -1 && f_dist[nx][ny] <= j_dist[cur.X][cur.Y] + 1)
        continue;  // 불이 방문을 한 곳인데 먼저 방문한 경우
      j_dist[nx][ny] = j_dist[cur.X][cur.Y] + 1;
      J.push({nx, ny});
    }
  }

  cout << "IMPOSSIBLE";
}