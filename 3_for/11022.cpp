#include <iostream>
using namespace std;

int main() {
  int A, B;
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> A >> B;
    printf("Case #%d: %d + %d = %d\n", i + 1, A, B, A + B);
  }
}