#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  for (int i = 97; i < 123; i++) {
    if (s.find((char)i) != string::npos) {
      cout << s.find((char)i) << "\n";
    } else {
      cout << -1 << "\n";
    }
    // cout << (int)s.find((char)i) << " ";
  }
  return 0;
}
