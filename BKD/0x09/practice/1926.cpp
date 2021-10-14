#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second  // pair 에서 first, second 를 줄여서 쓰기 위해 사용

int board[502][502];  // 1이 탐색할 칸, 0이 탐색하지 않을 칸
bool vis[502][502];   // 해당 칸을 방문했는지 여부 저장
int n, m;             // 행, 열
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};  // 상하좌우 네방향 의미

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 입력 받기
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  int count = 0, mx = 0;  // 그림의 개수, 크기의 최대값
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {  // (i, j) 가 조건을 만족하면 시작점으로 설정
      if (!board[i][j] || vis[i][j])
        continue;  // 탐색 대상이고 방문하지 않았다면 큐에 삽입, 방문 처리
      count++;  // 그림 개수 1 증가
      queue<pair<int, int>> Q;  // 조사할 위치 넣는 큐(큐는 매 조사때마다 갱신)
      vis[i][j] = 1;  // (i,j)로 BFS를 시작하기 위한 준비
      Q.push({i, j});
      int area = 0;  // 그림 넓이
      while (!Q.empty()) {
        area++;  // 큐에서 원소를 하나 뺄 때마다 넓이를 1증가
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {  // 상하좌우 칸 살펴보기
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];  // 상하좌우 인접 좌표 구하기
          if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;  // 범위를 벗어나는 경우 제외
          if (vis[nx][ny] || board[nx][ny] != 1)
            continue;  // 이미 방문했거나 탐색 대상이 아닌 경우 제외
          vis[nx][ny] = 1;  // (nx, ny)를 방문했다고 명시
          Q.push({nx, ny});
        }
      }
      mx = max(mx, area);  // area 최대 구하기
    }
  }
  cout << count << '\n' << mx;
}