#include <bits/stdc++.h>
using namespace std;

// O(n^2)을 O(n)으로 개선
int func2(int arr[], int N) {
  int occur[101] = {};  // 0으로 초기화
  for (int i = 0; i < N; i++) {
    if (occur[100 - arr[i]]) return 1;
    occur[arr[i]] = 1;
  }
  return 0;
}
int main() {
  cout << func2({1, 52, 48}, 3) << "\n";
  return 0;
}
