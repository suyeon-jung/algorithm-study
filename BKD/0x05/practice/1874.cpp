#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s({0});
vector<int> seq;   //수열
vector<char> ans;  // 연산

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 수열 개수 입력
  int n;
  cin >> n;

  int t;
  // 수열 입력
  for (int i = 0; i < n; i++) {
    cin >> t;
    seq.push_back(t);
  }

  // 수열 인덱스
  int idx = 0;
  // 스택에 채울 자연수
  int num = 1;

  // 수열을 다 찾을 때까지 반복문 수행
  while (idx != n) {
    if (s.top() > seq[idx]) {
      cout << "NO" << '\n';
      return 0;
    }

    if (s.top() == seq[idx]) {  // top == 수열 원소
      s.pop();
      ans.push_back('-');
      idx++;
    } else {  // top != 수열 원소
      s.push(num);
      ans.push_back('+');
      num++;
    }
  }

  for (auto c : ans) cout << c << '\n';
}