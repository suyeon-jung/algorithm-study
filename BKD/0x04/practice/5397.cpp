#include <iostream>
#include <list>
using namespace std;

int T;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    list<char> ans;
    list<char>::iterator t = ans.begin();

    for (char c : s) {
      if (c == '-') {  // 앞 문자 삭제
        if (t != ans.begin()) {  // t가 ans.begin이면 전으로 이동할 수 없으므로
          t--;
          t = ans.erase(t);
        }
      } else if (c == '<') {
        if (t != ans.begin()) t--;
      } else if (c == '>') {
        if (t != ans.end()) t++;
      } else {  // t가 가리키는 자리 이전 자리에 값 추가
        ans.insert(t, c);
      }
    }

    for (char c : ans) cout << c;
    cout << '\n';
  }
}