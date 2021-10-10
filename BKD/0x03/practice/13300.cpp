#include <cmath>
#include <iostream>
using namespace std;

int n, k, ans = 0;
// 성별/반별 학생 수를 저장하는 배열
int stu[2][6];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  int gender, grade;
  for (int i = 0; i < n; i++) {
    cin >> gender >> grade;
    stu[gender][grade - 1]++;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      if (stu[i][j] > k)  // 최대 수용인원보다 크면 방을 더 줌
        ans += ceil((double)stu[i][j] / k);
      else if (stu[i][j] > 0)
        ans++;
    }
  }

  cout << ans << '\n';
}
