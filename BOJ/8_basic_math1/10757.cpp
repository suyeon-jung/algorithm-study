#include <iostream>
#include <string>
using namespace std;

void solve();
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
void solve() {
  string a, b;
  // a, b의 합 문자열
  string answer;
  int carry = 0;

  cin >> a >> b;

  if (a.size() < b.size()) {
    swap(a, b);
  }

  for (int i = 1; i <= a.size(); i++) {
    int aIndex = a.size() - i;
    int bIndex = b.size() - i;

    char aChar = a[aIndex];
    // a가 b보다 문자열의 길이가 김
    char bChar = bIndex < 0 ? '0' : b[bIndex];

    int newNum = (aChar - '0') + (bChar - '0') + carry;
    carry = (newNum >= 10 ? newNum / 10 : 0);
    char remain = (newNum % 10) + '0';
    answer = remain + answer;
  }

  if (carry) {
    answer = char(carry + '0') + answer;
  }

  cout << answer;
}