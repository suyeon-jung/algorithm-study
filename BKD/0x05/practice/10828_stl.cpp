#include <iostream>
#include <stack>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> S;
  int N;
  cin >> N;

  string s;
  while (N--) {
    cin >> s;
    if (s == "push") {
      int t;
      cin >> t;
      S.push(t);
    } else if (s == "pop") {
      if (S.empty())
        cout << -1 << '\n';
      else {
        cout << S.top() << '\n';
        S.pop();
      }
    } else if (s == "size")
      cout << S.size() << '\n';
    else if (s == "empty")
      cout << (int)S.empty() << '\n';
    else  // top
    {
      if (S.empty())
        cout << -1 << '\n';
      else
        cout << S.top() << '\n';
    }
  }
}