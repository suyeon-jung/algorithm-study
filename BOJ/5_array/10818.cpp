#include <iostream>
using namespace std;
int main(int argc, char const* argv[]) {
  int n;
  int min = 1000000;
  int max = -1000000;

  cin >> n;
  int* arr = new int[n];

  if (n < 1 || n > 1000000) return 0;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (max < arr[i]) max = arr[i];
    if (min > arr[i]) min = arr[i];
  }

  cout << min << " " << max;
  delete[] arr;

  return 0;
}
