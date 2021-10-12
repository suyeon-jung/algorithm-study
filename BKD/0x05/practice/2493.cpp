#include <iostream>
#include <stack>
using namespace std;

#define X first
#define Y second

int N;
stack<pair<int, int>> tower;  // (height, index)
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  tower.push(
      {100000001, 0});  // height의 최대값보다 더 큰 수(없음을 보이기 위해)
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;
    // 한 번 작았으면 더이상 고려하지 않아도 됨
    while (tower.top().X < height) tower.pop();
    cout << tower.top().Y << " ";
    tower.push({height, i});
  }
}