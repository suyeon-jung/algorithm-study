#include <iostream>
using namespace std;

void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
void solve() {
  int x1, y1, x2, y2, x3, y3, answer_x, answer_y;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  answer_x = x1;
  answer_y = y1;
  if (answer_x == x2) {
    answer_x = x3;
  } else if (answer_x == x3) {
    answer_x = x2;
  }

  if (answer_y == y2) {
    answer_y = y3;
  } else if (answer_y == y3) {
    answer_y = y2;
  }
  cout << answer_x << " " << answer_y << "\n";
}