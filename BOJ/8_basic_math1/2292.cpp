#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;

  int first = 1, last = 1, count = 1;
  while (last < N) {
    last += count * 6;
    count += 1;
  }
  cout << count;
  return 0;
}
