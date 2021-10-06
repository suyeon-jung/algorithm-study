#include <algorithm>
#include <iostream>
using namespace std;

int input, dice[7];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++) {
    cin >> input;
    dice[input]++;
  }

  int max_value = 0, max_index;
  for (int i = 1; i < 7; i++) {
    if (max_value < dice[i]) max_value = dice[i];
    if (dice[i] >= 1) max_index = i;
  }

  //   int max = 0;
  //   for (int i = 1; i < 7; i++) {
  //     if (dice[i] == 3) {
  //       cout << 10000 + i * 1000;
  //       break;
  //     } else if (dice[i] == 2) {
  //       cout << 1000 + i * 100;
  //       break;
  //     } else
  //       max = dice[i] == 1 ? i : max;
  //   }

  //   if (max != 0) cout << max * 100;
}