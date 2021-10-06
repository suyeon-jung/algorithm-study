#include <iostream>
using namespace std;

int arr[10];

int main(int argc, char const *argv[]) {
  int a, b, c;
  int result;

  cin >> a >> b >> c;
  if (a < 100 || b < 100 || c < 100) return 0;

  result = a * b * c;
  while (result > 0) {
    arr[(result % 10)]++;
    result /= 10;
  }
  // 출력
  for (int i = 0; i < 10; i++) cout << arr[i] << "\n";

  return 0;
}
