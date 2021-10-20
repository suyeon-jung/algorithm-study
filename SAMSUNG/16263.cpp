#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second
int board[25][25];          // 지도
int vis[25][25];            // 해당 좌표 위치 방문했었는지
int dx[4] = {-1, 0, 1, 0};  // 우선순위에 따라 dx, dy 설정
int dy[4] = {0, -1, 0, 1};

void calc() {}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, fish_count = 0;
  cin >> n;
  pair<int, int> start;
  // input 입력
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 9) start = make_pair(i, j);
    }
  }
  cout << start.first << start.second;

  queue<pari<int, int>> Q;
  Q.push(start);
  vis[start.X][start.Y] = 1;  // 방문 표시해주기

  /*
  1. bfs를 돌면서 이동이 가능하고 먹을 수 있는 곳으로 움직이기(이전에 방문하지
  않은 경우에만 큐에 넣음) -> 물고기가 있는 경우(크기가 아기상어보다 작은
  경우)에는 bfs 종료
  2. 움직이고 다시 1번 반복 -> 물고기 찾으면 그 위치에서 다시 bfs 수행
  3. 다시 1~2 반복
  */
  int size = 2;
  int cnt = 0;
  int rst = 0;
  while (1) {
    int ret = cacl();
    if (ret == 0) {  // 더이상 없으면 반환
      cout << rst;
      return 0;
    }
    cnt += 1;
    if (cnt == size) {
      size += 1;
      cnt = 0;
    }
    rst += ret;
  }
}
