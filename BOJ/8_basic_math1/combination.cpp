// 순서 X, 중복 X
#include <iostream>
using namespace std;

#define n 4
#define r 3

// 선택 배열
int cArr[r] = {
    0,
};

// next: 이미 선택한 것은 다시 선택하지 않도록
void combination(int depth, int next) {
  if (depth == r) {
    for (int i = 0; i < r; i++) {
      cout << cArr[i] << " ";
    }
  }
  for (int i = next; i <= n; i++) {
    cArr[depth] = i;
    combination(depth + 1, i + 1);
  }
}

int main(int argc, char const *argv[]) {
  combination(0, 1);
  return 0;
}
