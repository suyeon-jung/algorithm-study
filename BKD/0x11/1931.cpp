#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 회의의 수

// 1. 끝나는 시간이 빠른 순 정렬 2. 시작 시간이 빠른 순 정렬
bool compare(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second)
  {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  vector<pair<int, int>> v; // (시작 시간, 끝나는 시간)

  for (int i = 0; i < n; i++)
  {
    int start, end;
    cin >> start >> end;
    v.push_back({start, end});
  }

  sort(v.begin(), v.end(), compare);

  int ans = 0;

  vector<pair<int, int>>::iterator it = v.begin();

  int end = (*it).second; // 첫번째 회의의 끝나는 시간
  it++;
  ans++;

  for (; it != v.end(); it++)
  {
    int start = (*it).first;
    if (end <= start)
    {
      end = (*it).second;
      ans++;
    }
  }

  cout << ans;

  return 0;
}