#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second
#define MAX 25

typedef pair<int, int> pii;
typedef pair<int, pii> ppii;

// pq -> dis, x, y
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n;               // 공간의 크기
int cur_size = 2;    // 아기 상어 크기
int buf = 0;         // 현재 먹은 상어 마리수
int board[MAX][MAX]; // 공간
bool vis[MAX][MAX];  // 방문 여부
queue<ppii> q;       // 탐색 시작 위치

ppii start; // 시작점

// 거리가 가까운, 가장 위, 가장 왼쪽
struct compare
{
  bool operator()(ppii a, ppii b)
  {
    if (a.X == b.X)
    {
      if (a.Y.X == b.Y.X)
        return a.Y.Y > b.Y.Y;
      return a.Y.X > b.Y.X;
    }
    return a.X > b.X;
  }
};

/**
 * 매개변수로 주어진 시작점에서 먹을 수 있는 상어 찾기
 * 1. 찾은 경우 : 찾을 때 까지 걸린 시간 반환
 * 2. 못 찾은 경우 : 0 반환
 */
bool bfs(ppii pos)
{
  priority_queue<ppii, vector<ppii>, compare> pq; // 거리, (x, y)

  pq.push({pos.X, {pos.Y.X, pos.Y.Y}});

  cout << "pos: " << pos.X << ":" << pos.Y.X << "," << pos.Y.Y << '\n';

  while (!pq.empty())
  {
    ppii cur = pq.top();
    pq.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.Y.X + dx[dir];
      int ny = cur.Y.Y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n) // 범위 밖인 경우
        continue;
      if (vis[nx][ny] || board[nx][ny] > cur_size) // 이미 방문했거나 상어의 현재 크기보다 더 큰 경우(지나갈 수 없는 경우)
        continue;
      if (board[nx][ny] < cur_size && board[nx][ny] > 0) // 먹을 수 있는 경우
      {
        board[nx][ny] = 0; // 먹은 처리

        buf++;
        // 현재 크기만큼의 마리수를 먹은 경우(크기 + 1)
        if (buf == cur_size)
        {
          buf = 0;
          cur_size++;
        }

        start = {cur.X + 1, {nx, ny}};

        return true;
      }
      vis[nx][ny] = true;
      pq.push({cur.X + 1, {nx, ny}}); // 다음 탐색 위치 push
    }
  }
  // 먹을 수 있는 상어가 없는 경우
  return false;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 9) // 상어 위치
      {
        // q.push({0, {i, j}});
        board[i][j] = 0;
        start = {0, {i, j}};
        vis[i][j] = true;
      }
    }
  }

  int ans = 0;

  while (bfs(start))
  {
    for (int i = 0; i < n + 1; i++) // 방문여부 초기화
      fill(vis[i], vis[i] + n + 1, false);
    cout << "cur_size: " << cur_size << '\n';
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << board[i][j] << " ";
      }
      cout << "\n";
    }
  }

  cout << start.X;
}
