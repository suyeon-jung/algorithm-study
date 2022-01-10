#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> Q;
string cm;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  while (n--) {
    cin >> cm;
    if (cm == "push") {
      int val;
      cin >> val;
      Q.push(val);
    } else if (cm == "pop") {
      if (Q.size()) {
        cout << Q.front() << '\n';
        Q.pop();
      } else {
        cout << -1 << '\n';
      }
    } else if (cm == "size") {
      cout << Q.size() << '\n';
    } else if (cm == "empty") {
      cout << Q.empty() << '\n';
    } else if (cm == "front") {
      if (Q.size()) {
        cout << Q.front() << '\n';
      } else {
        cout << -1 << '\n';
      }
    } else {  // back
      if (Q.size()) {
        cout << Q.back() << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }
}