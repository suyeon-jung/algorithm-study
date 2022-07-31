#include <iostream>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;
// 현재 cur 인덱스 수를 더할지 말지 정하기
void func(int cur, int sum)
{
  if (cur == n)
  {
    if (sum == s)
      cnt++;
    return;
  }
  func(cur + 1, sum);
  func(cur + 1, sum + arr[cur]);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  func(0, 0);
  if (s == 0) // 아무것도 선택하지 않는 수열의 경우 제외
    cnt--;
  cout << cnt;
  return 0;
}