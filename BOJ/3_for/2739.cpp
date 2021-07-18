#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N < 1 || N > 9) return 0;

  for (int i = 1; i < 10; i++) {
    cout << N << " * " << i << " = " << N * i << "\n";
  }
}