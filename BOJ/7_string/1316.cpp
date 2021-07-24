#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int word_count, group_count;
  cin >> word_count;
  group_count = word_count;

  while (word_count > 0) {
    string input;
    cin >> input;

    bool alphabet[26] = {false};
    for (int i = 0; i < input.length(); i++) {
      int idx = input[i] - 'a';
      if (!alphabet[idx])
        alphabet[idx] = true;
      else if (alphabet[idx] && input[i - 1] != input[i]) {
        group_count--;
        break;
      }
    }
    word_count--;
  }

  cout << group_count << endl;

  return 0;
}
