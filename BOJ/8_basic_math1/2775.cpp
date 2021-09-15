#include <iostream>
using namespace std;

// nCr = n-1Cr + n-1Cr-1
int getNum(int n, int r) {
  // 0층일 경우 b호에는 b명 거주
  if (n == 0) {
    return r;
  }
  // 1호인 경우 1명 거주
  if (r == 1) {
    return 1;
  }
  return (getNum(n - 1, r) + getNum(n, r - 1));
}

int main(int argc, char const *argv[]) {
  int floor, room;  // 층, 호수, 거주민 수
  int T;

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> floor >> room;

    cout << getNum(floor, room) << "\n";
  }

  return 0;
}
