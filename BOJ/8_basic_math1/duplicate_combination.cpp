// 순서 X, 중복 O
#include <iostream>
using namespace std;

#define n 4
#define r 3

int dcArr[r] = {
    0,
};

void duplicateCombination(int depth, int next) {
  if (depth == r) {
    for (int i = 0; i < r; i++) {
      cout << dcArr[i] << " ";
    }
    return;
  }

  for (int i = next; i <= n; i++) {
    dcArr[depth] = i;
    duplicateCombination(depth + 1, i);
  }
}

int main(int argc, const char** argv) {
  duplicateCombination(0, 1);
  return 0;
}