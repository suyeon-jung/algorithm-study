// upper case: 65~90
// lower case: 97~122
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  string input;
  int arr[26] = {0};

  int max = 0, max_index = 0;
  int count = 0;  // 같은 빈도수를 가진 아이템 개수

  cin >> input;

  for (int j = 0; j < input.length(); j++) {
    int n = input[j];
    // 소문자, 대문자 한번에 처리
    arr[n % 97 % 65] += 1;
    // 소문자인 경우, 대문자인 경우 따로 처리
    // if (n < 97) {  // 대문자
    //   arr[n - 65]++;
    // } else {  // 소문자
    //   arr[n - 97]++;
    // }
  }

  for (int i = 0; i < 26; i++) {
    if (max < arr[i]) {
      max = arr[i];
      max_index = i;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (arr[i] == max) {
      count++;
      if (count >= 2) {
        cout << "?";
        return 0;
      }
    }
  }
  cout << (char)(max_index + 65);
  return 0;
}
