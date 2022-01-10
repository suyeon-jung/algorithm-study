#include <iostream>
#include <list>
using namespace std;

// (2) 연결리스트로 구현 - STL
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  list<int> dat;
  string comm;
  int num;
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> comm;
    if (comm == "push") {
      cin >> num;
      dat.push_back(num);
    } else if (comm == "pop") {
      if (!dat.size())
        cout << -1 << '\n';
      else {
        cout << dat.back() << '\n';
        dat.pop_back();
      }

    } else if (comm == "size") {
      cout << dat.size() << '\n';
    } else if (comm == "empty") {
      if (!dat.size())
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (comm == "top") {
      if (!dat.size())
        cout << -1 << '\n';
      else {
        cout << dat.back() << '\n';
      }
    }
  }
}