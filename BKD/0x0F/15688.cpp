// counting sort - O(n+k)
#include <bits/stdc++.h>
using namespace std;

// n이 절댓값이 1000000보다 작거나 같은 정수
int freq[2000005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int val;
    cin >> val;
    freq[val + 1000000]++;
  }

  for (int i = 0; i <= 2000000; i++) {
    while (freq[i]--) {
      cout << i - 1000000 << '\n';
    }
  }
}