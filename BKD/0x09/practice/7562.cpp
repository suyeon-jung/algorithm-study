#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int testCase;
int l;
int sx, sy, fx, fy;
int dist[303][303];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int bfs(int startX, int startY, int finX, int finY)
{
  queue<pair<int, int>> q;
  q.push({startX, startY});
  dist[startX][startY] = 0;
  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    if (cur.first == finX && cur.second == finY)
      return dist[cur.first][cur.second];

    for (int dir = 0; dir < 8; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= l || ny < 0 || ny >= l)
        continue;
      if (dist[nx][ny] >= 0)
        continue;

      q.push({nx, ny});
      dist[nx][ny] = dist[cur.first][cur.second] + 1;
    }
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> testCase;
  for (int i = 0; i < testCase; i++)
  {
    cin >> l;
    cin >> sx >> sy;
    cin >> fx >> fy;
    for (int j = 0; j < l; j++)
      fill(dist[j], dist[j] + l, -1);

    cout << bfs(sx, sy, fx, fy) << '\n';
  }
}