#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int index;
  string dict[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

  string input;
  cin >> input;
  for (int i = 0; i < 8; i++) {
    // 해당 문자가 있다면 다른 문자로 치환
    while (1) {
      index = input.find(dict[i]);
      if (index == string::npos) break;
      input.replace(index, dict[i].length(), "#");
    }
  }
  cout << input.length();
  return 0;
}
