#include <iostream>
using namespace std;

// 수열의 최대 크기가 1000000이기 때문에 1000001로 선언
int a[1000001];
// 각 자연수의 존재 여부 저장하는 배열
bool occur[2000001];
int n, t, x;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int pair_count = 0;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x;

  for (int i = 0; i < n; i++) {
    // 입력한 수가 x에 포함되어 쌍을 가지려면 x > a[i] 조건을 만족해야 함
    if (x > a[i] && occur[x - a[i]]) pair_count++;
    occur[a[i]] = true;
  }
  cout << pair_count;
}