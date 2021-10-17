#include <bits/stdc++.h>
using namespace std;

// 입력받은 배열 큐에 담기(숫자만)
void parse(string& tmp, deque<int>& d) {  // 쉼표를 구분자
  int cur = 0;
  for (int i = 1; i + 1 < tmp.size(); i++) {  // [] 제외
    if (tmp[i] == ',') {
      d.push_back(cur);
      cur = 0;
    } else {
      cur = 10 * cur + (tmp[i] - '0');
    }
  }
  // 마지막 원소 처리
  if (cur != 0) {
    d.push_back(cur);
  }
}
// 결과 출력
void print_result(deque<int>& d) {
  cout << '[';
  for (int i = 0; i < d.size(); i++) {
    cout << d[i];
    if (i != d.size() - 1) {
      cout << ',';
    }
  }
  cout << "]\n";
}

int t;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;

  while (t--) {
    deque<int> DQ;
    int n;               // 배열 크기
    int rev = 0;         // 뒤집기 여부
    bool error = false;  // 에러 여부
    string query, tmp;
    cin >> query;  // 수행할 함수
    cin >> n;      // 배열 크기
    cin >> tmp;    // 입력 배열
    parse(tmp, DQ);
    for (char c : query) {  // 명령 수행부
      if (c == 'R')
        rev = 1 - rev;
      else {  // D 인 경우
        if (DQ.empty()) {
          error = true;
          break;
        }
        if (!rev)
          DQ.pop_front();
        else
          DQ.pop_back();
      }
    }

    // 출력부
    if (error) {
      cout << "error\n";
    } else {
      if (rev) reverse(DQ.begin(), DQ.end());
      print_result(DQ);
    }
  }
}