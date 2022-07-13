/**
 * @file N-Queen.cpp
 * @author your name (you@domain.com)
 * @brief 9663
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
using namespace std;

#define MAX 10000000

int cnt = 0;
int n;

bool isused1[40];
bool isused2[30];
bool isused3[30];

// cur번째 행에 말을 배치할 예정
void func(int cur)
{
  if (cur == n)
  {
    cnt++;
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1])
      continue;
    isused1[i] = 1;
    isused2[cur + i] = 1;
    isused3[cur - i + n - 1] = 1;
    func(cur + i);
    isused1[i] = 0;
    isused2[cur + i] = 0;
    isused3[cur - i + n - 1] = 0;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;

  return 0;
}