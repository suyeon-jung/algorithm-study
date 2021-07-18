#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  // 입력 값
  int input;
  int remainder[42] = {0};
  // 서로 다른 나머지 개수
  int count = 0;
  for (int i = 0; i < 10; i++) {
    cin >> input;
    // 초기에 0->1로 가는 경우에만 count 증가시킴
    if (!remainder[input % 42]++) {
      count++;
    }
  }
  cout << count;
  return 0;
}
