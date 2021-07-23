#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  string input;
  int count = 1;

  // 공백이 포함된 문자열 입력 받기
  getline(cin, input);

  // 공백을 만나면 count +1
  for (int i = 0; i < input.length() + 1; i++) {
    if (input[i] == ' ') count++;
  }

  // 예외가 되는 경우
  // 처음에 공백 오는 경우, 맨 뒤에 공백 오는 경우
  if (input[0] == ' ') {
    count--;
  }
  if (input[input.length() - 1] == ' ') {
    count--;
  }

  cout << count;
  return 0;
}
