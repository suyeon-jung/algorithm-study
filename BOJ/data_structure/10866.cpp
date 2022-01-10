#include <deque>
#include <iostream>
using namespace std;

int main(void) {
  deque<int> DQ;
  int N;
  cin >> N;

  while (N--) {
    string s;
    cin >> s;
    if (s == "push_front") {
      int val;
      cin >> val;
      DQ.push_front(val);
    } else if (s == "push_back") {
      int val;
      cin >> val;
      DQ.push_back(val);
    } else if (s == "pop_front") {
      if (DQ.empty())
        cout << -1 << '\n';
      else {
        cout << DQ.front() << '\n';
        DQ.pop_front();
      }
    } else if (s == "pop_back") {
      if (DQ.empty())
        cout << -1 << '\n';
      else {
        cout << DQ.back() << '\n';
        DQ.pop_back();
      }
    } else if (s == "size") {
      cout << DQ.size() << '\n';
    } else if (s == "empty") {
      cout << DQ.empty() << '\n';
    } else if (s == "front") {
      if (DQ.empty())
        cout << -1 << '\n';
      else {
        cout << DQ.front() << '\n';
      }
    } else if (s == "back") {
      if (DQ.empty())
        cout << -1 << '\n';
      else {
        cout << DQ.back() << '\n';
      }
    }
  }
}