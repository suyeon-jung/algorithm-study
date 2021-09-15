// 순서 O, 중복 X
#include <iostream>
using namespace std;

#define n 4
#define r 3

// 선택 배열
int pArr[r] = {
    0,
};
// 중복 검사를 위함
bool check[n + 1] = {
    false,
};

// nCr
void permutation(int depth) {
  // 1. 레벨이 r과 같으면 출력
  if (depth == r) {
    for (int i = 0; i < r; i++) {
      cout << pArr[i] << " ";
    }
    return;
  }
  // 2. 같지 않다면 재귀
  for (int j = 1; j <= n; j++) {
    if (!check[j]) {
      check[j] = true;
      pArr[depth] = j;
      permutation(depth + 1);
      // 순열은 순서가 중요하므로 앞에서 선택한 후에도 선택할 수  있음(다시
      // false로)
      check[j] = false;
    }
  }
}

int main(int argc, char const *argv[]) {
  permutation(0);
  return 0;
}
