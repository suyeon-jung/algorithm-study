#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // -100 <= v && v <= 100 이므로 201로 자리를 지정
  int n, v, occur[201] = {};
  cin >> n;

  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    occur[t + 100]++;
  }
  cin >> v;
  cout << occur[v + 100];
}