#include <iostream>
using namespace std;
int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  char* arr = new char[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  return 0;
}
