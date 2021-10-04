#include <cmath>
#include <iostream>
using namespace std;

int func3(int N);
int main() {
  cout << func3(9) << "\n";
  cout << func3(693953651) << "\n";
  cout << func3(756580036) << "\n";
  return 0;
}
int func3(int N) {
  int square = sqrt(N);
  if (square * square == N) return 1;
  return 0;
}