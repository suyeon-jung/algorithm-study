// STL 방식
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string init;
  cin >> init;
  // 입력받은 문자열 리스트로 만들기
  list<char> L;
  for (auto c : init) L.push_back(c);
  // 커서 설정(리스트의 맨 뒤) auto cursor = L.end()
  list<char>::iterator cursor = L.end();

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    char comm;
    cin >> comm;

    if (comm == 'P') {
      // 삽입할 문자
      char add;
      cin >> add;
      L.insert(cursor, add);
    } else if (comm == 'L') {
      if (cursor != L.begin()) cursor--;
    } else if (comm == 'D') {
      if (cursor != L.end()) cursor++;
    } else {  // 'B' 인 경우 커서 왼쪽 문자 삭제
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);  // erase 하고 나면 그 다음 원소의 위치를 반환
      }
    }
  }
  // 리스트 출력
  for (auto c : L) cout << c;
  return 0;
}
