#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second
int board[25][25];
int dist[25][25];           // 현재 위치에서 각 좌표까지의 거리
int sizes[25][25];          // 각 좌표별 사이즈 기록
int dx[4] = {0, -1, 1, 0};  // 우선순위에 따라 dx, dy 설정
int dy[4] = {-1, 0, 0, 1};
int cur_x, cur_y;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, fish_count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] > 0 && board[i][j] < 9)
        fish_count++;  // 물고기 마리수 저장
      else if (board[i][j] == 9) {
        cur_x = i;
        cur_y = j;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    fill(dist[i], dist[i] + 25, -1);
  }
  // 물고기가 없는 경우에는 종료 -> fish_count가 0이될때까지 수행
  if (fish_count == 0) {
    cout << 0;
    return 0;
  }

  // 각 좌표까지의 거리 구하기
  queue<pair<int, int>> Q;
  dist[cur_x][cur_y] = 0;
  sizes[cur_x][cur_y] = 2;
  Q.push({cur_x, cur_y});
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      // 움직일 칸이 현재 사이즈보다 작거나 같으면 이동 가능
      if (board[nx][ny] <= sizes[cur.X][cur.Y] && dist[nx][ny] == -1) {
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;  // 거리 이동
        sizes[nx][ny] +=
            (sizes[cur.X][cur.Y] + (board[nx][ny] / sizes[cur.X][cur.Y]));
        Q.push({nx, ny});
      }
    }
  }
  // 거리가 같은 물고기가 여러마리일때 1) 가장 위에 있는 물고기
  // 2) 가장 왼쪽에 있는 물고기 선택
  cout << "---각 좌표 거리---" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "---물고기 크기---" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << sizes[i][j] << ' ';
    }
    cout << '\n';
  }
}
