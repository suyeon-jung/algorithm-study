#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int A, B;
  do {
    cin >> A >> B;
    if (A != 0 && B != 0) {
      cout << A + B << "\n";
    }
  } while (A != 0 && B != 0);
  return 0;
}
