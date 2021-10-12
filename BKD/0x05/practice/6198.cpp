#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<int> h;
  for (int i = 0; i < N; i++) {
    int height;
    cin >> height;
    h.push_back(height);
  }

  stack<int> tower({0});
  for (int i = 0; i < N; i++) {
    // 벡터의 뒤분터 순회
    while (tower.top() > h.back()) tower.pop();
    cout << tower.size() << ' ';
    tower.push(h.back());
    h.pop_back();
  }
}