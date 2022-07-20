#include <iostream>
#include <algorithm>
using namespace std;

int n;                    // 회의의 수
pair<int, int> s[100005]; // [end time, start time]

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i].second >> s[i].first;
  }

  // 1. 끝나는 시간 2. 시작 시간(정렬 우선순위)
  sort(s, s + n);

  int ans = 0;
  int t = 0; // 기준 시간

  for (int i = 0; i < n; i++)
  {
    if (t > s[i].second)
      continue;
    ans++;
    t = s[i].first;
  }
  cout << ans;

  return 0;
}