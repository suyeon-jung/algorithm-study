#include <iostream>
using namespace std;
int main() {
  int n;
  int sum = 0;
  cin >> n;
  if (n < 1 || n > 10000) return 0;
  for (int i = 0; i < n; i++) {
    sum += (i + 1);
  }
  cout << sum;

  // 수식 사용하는 방법 n * (n+1)/2
  return 0;
}