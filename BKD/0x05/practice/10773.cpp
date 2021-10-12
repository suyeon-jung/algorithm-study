#include <iostream>
#include <stack>
using namespace std;

int K, ans;
stack<int> S;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K;

  while (K--) {
    int t;
    cin >> t;
    if (t)
      S.push(t);
    else
      S.pop();
  }

  while (!S.empty()) {
    ans += S.top();
    S.pop();
  }
  cout << ans;
}