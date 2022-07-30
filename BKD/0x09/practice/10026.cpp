#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N;
char board[105][105];
bool visited[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs()
{
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (visited[i][j] == false)
      {
        cnt++;
        queue<pair<int, int>> Q;
        visited[i][j] = true;
        Q.push({i, j});

        while (!Q.empty())
        {
          auto cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < 4; dir++)
          {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
              continue;
            if (visited[nx][ny] == true) // 이미 방문한 경우
              continue;
            if (board[cur.first][cur.second] != board[nx][ny]) // 같은 구역이 아니면 탐색 안함
              continue;
            visited[nx][ny] = true;
            Q.push({nx, ny});
          }
        }
      }
    }
  }
  return cnt;
}

int main()
{
  string ans = "";
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cin >> board[i][j];
  }

  int normalCnt = 0;    // 적록색약이 아닌 사람이 봤을 때 구역의 수
  int blindnessCnt = 0; // 적록색약인 사람이 봤을 때 구역의 수

  ans += to_string(bfs());
  ans += " ";

  // 방문 배열 초기화
  for (int i = 0; i < N; i++)
    fill(visited[i], visited[i] + N, false);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (board[i][j] == 'G')
        board[i][j] = 'R';
    }
  }

  ans += to_string(bfs());

  cout << ans;
}