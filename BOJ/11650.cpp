#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int val_x, val_y;
    cin >> val_x >> val_y;
    v.push_back(make_pair(val_x, val_y));
  }
  sort(v.begin(), v.end(), cmp);
  for (auto i : v) cout << i.first << ' ' << i.second << '\n';
}