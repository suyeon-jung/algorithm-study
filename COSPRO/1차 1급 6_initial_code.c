// You may use include as below.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int solution(char* pos) {
  int cur_x = pos[0] - 'A';
  int cur_y = 8 - (pos[1] - '0');
  int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
  // Write code here.
  int answer = 0;
  for (int dir = 0; dir < 8; dir++) {  // 후보군이 체스판을 벗어나는지 확인
    int nx = cur_x + dx[dir];
    int ny = cur_y + dy[dir];
    if (nx < 0 || nx >= 7 || ny < 0 || ny >= 7) continue;
    answer++;
  }
  return answer;
}

// The following is main function to output testcase.
int main() {
  char* pos = "A7";
  int ret = solution(pos);

  // Press Run button to receive output.
  printf("Solution: return value of the function is %d .\n", ret);
}