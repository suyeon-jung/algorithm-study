#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
  if (a.size() != b.size()) {  // 길이가 다른 경우
    return a.size() < b.size();
  } else {  // 길이가 같은 경우
    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] >= '0' && a[i] <= '9') sum_a += a[i] - '0';
      if (b[i] >= '0' && b[i] <= '9') sum_b += b[i] - '0';
    }
    if (sum_a != sum_b) return sum_a < sum_b;
    return a < b;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s[50];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  sort(s, s + n, cmp);
  for (int i = 0; i < n; i++) {
    cout << s[i] << '\n';
  }
}