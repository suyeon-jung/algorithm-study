#include <iostream>
using namespace std;

// 3개의 탑이 있다고 가정하면 a도 b도 아닌 기둥의 번호는 6-a-b
void hanoi(int start, int end, int n)
{
  if (n == 1)
  {
    cout << start << ' ' << end << '\n';
    return;
  }
  hanoi(start, 6 - start - end, n - 1);
  cout << start << ' ' << end << '\n';
  hanoi(6 - start - end, end, n - 1);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  cout << (1 << n) - 1 << '\n';

  hanoi(1, 3, n);
}