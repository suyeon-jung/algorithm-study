#include <iostream>
using namespace std;

int main() {
  int A, B;
  int T;

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> A >> B;
    cout << "Case #" << i + 1 << ": " << A + B << "\n";
  }
}