#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define INF 987654321  // 충분히 큰 값 설정(최소 찾기 위해)
int board[20][20];     // 지도
int dist[20][20];      // 거리 저장
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n;
int shark_size = 2, cnt = 2;
int min_dist, min_x, min_y, result;

struct Point {
  int r, c;
};

// 먹을 수 있는 물고기 찾는 함수
void bfs(int x, int y) {
  // bfs에서 사용할 큐
  queue<Point> q;
  q.push({x, y});

  while (!q.empty()) {
    Point cur = q.front();
    q.pop();
    // 4방향 탐색
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.r + dx[dir];
      int ny = cur.c + dy[dir];
      // 범위 벗어난 경우 탐색 안함
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      // 이미 방문했거나 크기가 아기상어보다 큰경우
      if (dist[nx][ny] != -1 || board[nx][ny] > shark_size) continue;
      // 물고기 이동거리 갱신
      dist[nx][ny] = dist[cur.r][cur.c] + 1;

      // 먹을 수 있는 물고기라면
      if (board[nx][ny] != 0 && board[nx][ny] < shark_size) {
        if (min_dist > dist[nx][ny]) {  // 먹을 수 있는 물고기 거리가 현재
                                        // 최소거리보다 작다면
          min_dist = dist[nx][ny];
          min_x = nx;
          min_y = ny;
        } else if (min_dist == dist[nx][ny]) {  // dist는 갱신할 필요 없음
          if (min_x == nx) {                    // 가장 위, 가장 왼쪽
            if (min_y > ny) {
              min_x = nx;
              min_y = ny;
            } else if (min_x > nx) {
              min_x = nx;
              min_y = ny;
            }
          }
        }
      }
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;              // 공간의 크기
  int shark_x, shark_y;  // 처음 아기상어 위치의 (행, 열) 저장
  // 지도 입력 받기
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      // 아기 상어라면
      if (board[i][j] == 9) {
        shark_x = i;
        shark_y = j;
        board[i][j] = 0;  // 지도상에서 0으로 비워줌
        dist[i][j] = 0;
      }
    }
  }

  // 거리배열 초기화
  while (1) {
    // 좌표 옮기고 나면 처음 상태에서 시작해야 하므로
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + 20, -1);
    min_dist = 401;
    min_x = 21;
    min_y = 21;
    // 먹을 수 있는 물고기 찾기
    bfs(shark_x, shark_y);

    // 찾은 경우
    if (min_x != 21 && min_y != 21) {
      // 시간 계산
      result += dist[min_x][min_y];

      // 아기상어 크기 조정
      cnt--;
      if (cnt == 0) {
        shark_size++;
        cnt = shark_size;
      }
      board[min_x][min_y] = 0;
      // 새로운 시작점으로 설정
      shark_x = min_x;
      shark_y = min_y;
    } else {  // 먹을 수 있는 물고기 없으면 종료
      break;
    }
  }

  cout << result;
}