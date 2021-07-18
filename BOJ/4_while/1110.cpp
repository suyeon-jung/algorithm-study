#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int N;
  int New;
  int sum;
  int cycle = 0;
  cin >> N;
  New = N;
  
  if (N < 0 || N > 99) {
    return 0;
  }

  while (1) {
    sum = (New / 10) + (New % 10);
    New = (New % 10) * 10 + (sum % 10);
    cycle++;
    if (N == New) break;
  }
  cout << cycle;
  return 0;
}
