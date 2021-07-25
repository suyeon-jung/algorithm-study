#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  long long fixedCost, variableCost, price;
  cin >> fixedCost >> variableCost >> price;

  int count = 1;

  if (variableCost >= price) {
    cout << -1;
    return 0;
  }
  cout << fixedCost / (price - variableCost) + 1;
  return 0;
}
