#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  string input;
  int count = 0;
  // 공백이 포함된 문자열 입력 받기
  getline(cin, input);
  for (int i = 0; i < input.length() + 1; i++) {
    if (input[i] == ' ' || input[i] == '\0') count++;
  }
  cout << count;
  return 0;
}
