#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int A, B;
  while (true) {
    cin >> A >> B;
    if (A != 0 || B != 0)
      cout << A + B << "\n";
    else
      break;
  }
  return 0;
}
