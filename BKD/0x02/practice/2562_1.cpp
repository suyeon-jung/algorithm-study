#include <algorithm>
#include <iostream>
using namespace std;

int a[9];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 9; i++) cin >> a[i];
  cout << *max_element(a, a + 9) << '\n';
  cout << max_element(a, a + 9) - a + 1 << '\n';
}