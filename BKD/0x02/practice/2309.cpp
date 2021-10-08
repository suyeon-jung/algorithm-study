#include <iostream>
#include <vector>
using namespace std;

vector<int> height;
int input, sum;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 9; i++) {
    cin >> input;
    height.push_back(input);
    sum += input;
  }
  for (int i : height) cout << i << ' ';
  cout << '\n';

  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (sum - (height[i] + height[j]) == 100) {
        remove(height.begin(), height.end(), height[i]);
        remove(height.begin(), height.end(), height[j]);
        cout << i << ' ' << j;
        break;
      }
    }
  }
  for (int i : height) cout << i << ' ';

  return 0;
}