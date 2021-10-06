#include <algorithm>
#include <iostream>
using namespace std;

int num[5], sum;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    cin >> num[i];
    sum += num[i];
  }

  sort(num, num + 5);
  cout << sum / 5 << '\n' << num[2];
}