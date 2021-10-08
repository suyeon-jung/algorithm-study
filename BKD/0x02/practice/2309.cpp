#include <algorithm>
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

  sort(height.begin(), height.end());

  int check1, check2;
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (sum - (height[i] + height[j]) == 100) {
        check1 = i;
        check2 = j;
        break;
      }
    }
  }

  for (int i = 0; i < height.size(); i++) {
    if (i != check1 && i != check2) cout << height[i] << '\n';
  }
  return 0;
}