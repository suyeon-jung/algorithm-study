#include <bits/stdc++.h>
using namespace std;
#define X first;
#define Y second;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int board[205][205];  // 격자판(1: 장애물, 0: 평지)
int vis[205][205];    // 방문 여부(1: 방문, 0: 방문 안함)
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k, w, h;  // 이동 횟수, 가로, 세로
  cin >> k;
  cin >> w >> h;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> board[i][j];
    }
  }
  // 맨 왼쪽 위부터 시작
  vis[0][0] = 1;
  queue<pair<int, int>> Q;
  Q.push({0, 0});
  // 1. 말로 갈 수 있는 횟수 안에서 일단 최대로 가봄
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 8; dir++) {
      int nx = cur.X + hx[dir];
      int ny = cur.Y + hy[dir];
      cout << nx << ' ' << ny << '\n';
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (board[nx][ny] == 1 || vis[nx][ny] == 1) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << vis[i][j] << ' ';
    }
    cout << '\n';
  }
}
