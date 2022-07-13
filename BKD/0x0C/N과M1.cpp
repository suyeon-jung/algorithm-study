/**
 * @file N과M(1).cpp
 * @author suyeon-jung
 * @brief 15649
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
using namespace std;

int n, m;
int arr[10];     // - 수열을 담을 배열
bool isused[10]; // - 특정 수가 쓰였는지 여부를 나타내는 배열

// 현재 k개까지 수를 택한 상황에서 arr[k]를 정하는 함수
void func(int k)
{
  if (k == m) // 수열 출력 이후 함수 종료
  {
    for (int i = 0; i < m; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) // 아직 쓰이지 않은 수 찾아내기
  {
    if (!isused[i])
    {
      arr[k] = i;
      isused[k] = true;
      func(k + 1);
      isused[i] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
  return 0;
}