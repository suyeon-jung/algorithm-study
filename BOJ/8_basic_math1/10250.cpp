#include <iostream>
using namespace std;

int main(int argc, const char** argv) {
  int T;
  int height, width, number;

  cin >> T;
  while (T) {
    cin >> height >> width >> number;

    int h, w;

    w = number / height;
    h = number % height;

    if (h > 0) {
      w++;
    } else {
      h = height;
    }

    cout << h * 100 + w << "\n";
    T--;
  }

  return 0;
}