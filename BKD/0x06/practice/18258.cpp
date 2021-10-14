#include <bits/stdc++.h>
using namespace std;

// N (1 ≤ N ≤ 2,000,000)
const int MX = 2000005;
int dat[MX];
int head, tail;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string cm;
    cin >> cm;
    if (cm == "push") {  // tail 자리에 추가하고 tail 을 늘림
      int val;
      cin >> val;
      dat[tail++] = val;
    } else if (cm == "pop") {
      cout << (head == tail ? -1 : q[head++]) << '\n';
    } else if (cm == "size") {
      cout << tail - head << '\n';
    } else if (cm == "empty") {
      cout << (tail == head) << '\n';
    } else if (cm == "front") {
      cout << (head == tail ? -1 : q[head]) << '\n';
    } else {  // back
      cout << (head == tail ? -1 : q[tail - 1]) << '\n';
    }
  }
}