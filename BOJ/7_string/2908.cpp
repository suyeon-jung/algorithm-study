// 숫자 뒤집기 check!!!
#include <iostream>
#include <string>
using namespace std;
int rev(int n) {
  string s = to_string(n);
  reverse(s.begin(), s.end());
  return atoi(s.c_str());
}
int main(int argc, char const *argv[]) {
  int num1, num2, max;
  int temp1, temp2;
  cin >> num1 >> num2;
  temp1 = num1;
  temp2 = num2;
  while (temp1 > 0) {
    if (temp1 % 10 > temp2 % 10) {
      max = num1;
      break;
    } else if (temp1 % 10 < temp2 % 10) {
      max = num2;
      break;
    }
    temp1 /= 10;
    temp2 /= 10;
  }
  cout << rev(max);

  return 0;
}
