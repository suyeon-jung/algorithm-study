#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char board[1005][1005];
int dist[1005][1005];
int n, m;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> Q;
  dist[0][0] = 1;
  Q.push({0, 0});
  bool use = false;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;  // 범위를 넘어서는 경우

      if (board[nx][ny] == '0' &&
          dist[nx][ny] == -1) {  // 주변에 0이 있는 경우 이동
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      } else if (board[nx][ny] == '1' &&
                 dist[nx][ny] == -1) {  // 주변에 0이 없는 경우
        if (!use) {  // 아직 벽은 한번도 안부순 경우
          use = true;
          dist[nx][ny] = dist[cur.X][cur.Y] + 1;
          Q.push({nx, ny});
        } else {
          continue;
        }
      }
    }
  }

  (dist[n - 1][m - 1] != -1) ? (cout << dist[n - 1][m - 1]) : (cout << -1);
}