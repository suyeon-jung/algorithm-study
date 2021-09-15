// 순서 O, 중복 O
#include <iostream>
using namespace std;

#define n 4
#define r 3

int dpArr[r] = {
    0,
};

void duplicatePermutation(int depth) {
  if (depth == r) {
    for (int i = 0; i < r; i++) {
      cout << dpArr[i] << " ";
    }
    return;
  }
  for (int j = 1; j <= n; j++) {
    dpArr[depth] = j;
    duplicatePermutation(depth + 1);
  }
}

int main(int argc, const char** argv) {
  duplicatePermutation(0);
  return 0;
}