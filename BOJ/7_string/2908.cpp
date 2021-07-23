#include <iostream>
using namespace std;
// 수가 세자리 수라는 제한
int main(int argc, char const *argv[]) {
  string a, b;
  string max;
  cin >> a >> b;

  int i = 2;
  while (1) {
    if (a[i] > b[i]) {
      max = a;
      break;
    } else if (a[i] < b[i]) {
      max = b;
      break;
    }
    i--;
  }
  cout << max[2] << max[1] << max[0];

  return 0;
}
