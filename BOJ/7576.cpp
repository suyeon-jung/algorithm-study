#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int m, n;
int board[1002][1002];
int dist[1002][1002];
int ans;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
/**
 * 1 - 익은 토마토
 * 0 - 익지 않은 토마토
 * -1 - 토마토가 들어있지 않은 칸
 */

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 1) // 시작점
        q.push({i, j});
      if (board[i][j] == 0) // 방문 필요
        dist[i][j] = -1;
    }
  }

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위를 벗어나는 경우 제외
        continue;
      if (board[nx][ny] == -1) // 토마토가 들어있지 않은 경우 제외
        continue;
      if (dist[nx][ny] >= 0) // 이미 방문한 곳 제외
        continue;

      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (dist[i][j] == -1) // 익지 못한 토마토
      {
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans;
}