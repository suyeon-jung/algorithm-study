// You may use include as below.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int solution(int n) {  // 격자 크기
  int board[101][101] = {
      0,
  };  // 1~ n*n까지의 수를 맵에 채우기
  int answer = 0;
  int x = 0;
  int y = -1;
  int num = 0;
  int check = -1;  // 0 (아래, 왼쪽), 1(위, 오른쪽)

  for (int i = 0; i < n; i++) {
    num++;
    y++;
    board[x][y] = num;
  }

  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (check == -1) {  // 아래
        x++;
      } else {  // 위
        x--;
      }
      num++;
      board[x][y] = num;
    }
    for (int j = 0; j < i; j++) {
      if (check == -1) {  // 왼쪽
        y--;
      } else {  // 오른쪽
        y++;
      }
      num++;
      board[x][y] = num;
    }
    check *= -1;
  }
  // 대각선 합 구하기
  for (int i = 0; i < n; i++) answer += board[i][i];
  return answer;
}

// The following is main function to output testcase.
int main() {
  int n1 = 3;
  int ret1 = solution(n1);

  // Press Run button to receive output.
  printf("Solution: return value of the function is %d .\n", ret1);

  int n2 = 2;
  int ret2 = solution(n2);

  // Press Run button to receive output.
  printf("Solution: return value of the function is %d .\n", ret2);
}