#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int t, r;
  string s;
  cin >> t;
  for (int k = 0; k < t; k++) {
    cin >> r >> s;
    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < r; j++) {
        cout << s[i];
      }
    }
    cout << "\n";
  }
  return 0;
}
