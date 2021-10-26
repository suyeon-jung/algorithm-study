// You may use include as below.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long long solution(long long num) {
  long long answer = num + 1;
  num++;  // num에 1 더하기
  int multiple = 1;
  while (num > 0) {
    int tmp = num % 10;
    num /= 10;
    if (tmp == 0) answer += multiple * 1;
    multiple *= 10;
  }
  return answer;
}

// The following is main function to output testcase.
int main() {
  long long num = 9949999;
  long long ret = solution(num);

  // Press Run button to receive output.
  printf("Solution: return value of the function is %lld .\n", ret);
}