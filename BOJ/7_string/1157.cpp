// check!!!
// upper case: 65~90
// lower case: 97~122
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  string input;
  int arr[26] = {0};
  int max = 0, max_index = 0;
  cin >> input;
  for (int j = 0; j < input.length(); j++) {
    arr[(int)input[j] % 97 % 65] += 1;
  }
  for (int i = 0; i < 26; i++) {
    if (max < arr[i]) {
      max = arr[i];
      max_index = i;
    } else if (max == arr[i]) {
      // ? -> 63
      max_index = -2;
    }
  }
  cout << (char)(max_index + 65);
  return 0;
}
