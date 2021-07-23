#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int arr[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6,  6,  6,  7,
                 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
  int time = 0;
  string input;
  cin >> input;

  for (int i = 0; i < input.length(); i++) {
    int index = input[i] - 65;
    time += arr[index];
  }
  cout << time;

  return 0;
}
