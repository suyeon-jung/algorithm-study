#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int m, n, h;
int board[105][105][105];
int dist[105][105][105];
int ans;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
/**
 * 1 - 익은 토마토
 * 0 - 익지 않은 토마토
 * -1 - 토마토가 들어있지 않은 칸
 */

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> h;

  queue<pair<int, pair<int, int>>> q;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int s = 0; s < m; s++)
      {
        cin >> board[i][j][s];
        if (board[i][j][s] == 1)
          q.push({i, {j, s}});
        if (board[i][j][s] == 0)
          dist[i][j][s] = -1;
      }
    }
  }

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (int dir = 0; dir < 6; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y.Y + dy[dir];
      int nz = cur.Y.X + dz[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) // 범위를 벗어나는 경우 제외
        continue;
      if (board[nz][nx][ny] == -1) // 토마토가 들어있지 않은 경우 제외
        continue;
      if (dist[nz][nx][ny] >= 0) // 이미 방문한 곳 제외
        continue;

      dist[nz][nx][ny] = dist[cur.X][cur.Y.X][cur.Y.Y] + 1;
      q.push({nz, {nx, ny}});
    }
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int s = 0; s < m; s++)
      {
        if (dist[i][j][s] == -1) // 익지 못한 토마토
        {
          cout << -1;
          return 0;
        }
        ans = max(ans, dist[i][j][s]);
      }
    }
  }

  cout << ans;
}