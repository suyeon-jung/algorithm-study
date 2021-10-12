#include <iostream>
#include <queue>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> Q;
  int N;
  cin >> N;

  while (N--) {
    // 명령
    string com;
    cin >> com;
    if (com == "push") {
      int input;
      cin >> input;
      Q.push(input);
    } else if (com == "pop") {
      if (Q.size()) {
        cout << Q.front() << '\n';
        Q.pop();
      } else
        cout << -1 << '\n';
    } else if (com == "size") {
      cout << Q.size() << '\n';
    } else if (com == "empty") {
      cout << Q.empty() << '\n';
    } else if (com == "front") {
      if (Q.size())
        cout << Q.front() << '\n';
      else
        cout << -1 << '\n';
    } else if (com == "back") {
      if (Q.size())
        cout << Q.back() << '\n';
      else
        cout << -1 << '\n';
    }
  }
}