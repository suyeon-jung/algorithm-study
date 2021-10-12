#include <iostream>
#include <stack>
using namespace std;

stack<int> S;
int n;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (n--) {
    int t;
    cin >> t;
    S.push(t);
  }
}