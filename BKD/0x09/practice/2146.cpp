#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second
int board[105][105];  // 지도(0: 바다, 1: 육지)
int vis[105][105];    // 섬(0: 방문 안함, 1: 방문)
int dist[105][105];   // 거리
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {  // 지도 입력 받기
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  // 1.  영역 구분하기
  int gid = 0;  // 영역(대륙) ID
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 1 && vis[i][j] == 0) {
        queue<pair<int, int>> Q;
        vis[i][j] = ++gid;
        Q.push({i, j});
        while (!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == 1 &&
                vis[nx][ny] == 0) {  // 육지이거나 방문안했을때
              Q.push({nx, ny});
              vis[nx][ny] = gid;  // 번호 매기기
            }
          }
        }
      }
    }
  }

  // 2. 큐에 일단 다 넣어놓고 시작 -> 그래야 각 기준에서 최소임(out-bfs)
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = -1;
      if (board[i][j] == 1) {  // 대륙인곳은 dist 0으로 설정
        Q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }

  // 다른 대륙을 만날때까지 거리 측정
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (dist[nx][ny] == -1) {
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        vis[nx][ny] =
            vis[cur.X][cur.Y];  // 확장되는 영역이 어떤 그룹일때 최소인지 저장
        Q.push({nx, ny});
      }
    }
  }

  // 3. 최소값 찾기(두섬이 만나는 경우 만나는 두점에 해당하는 길이를 더함)
  int ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (vis[nx][ny] != vis[i][j]) {
          if (ans == -1 || ans > dist[nx][ny] + dist[i][j]) {
            ans = dist[nx][ny] + dist[i][j];
          }
        }
      }
    }
  }

  cout << ans;
}