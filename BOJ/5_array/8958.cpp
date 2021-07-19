#include <iostream>
using namespace std;
int main(int argc, char const* argv[]) {
  int n, sum, score;
  string input;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    sum = score = 0;
    for (int j = 0; j < input.size(); j++) {
      input[j] == 'O' ? sum++ : sum = 0;
      score += sum;
    }
    cout << score << "\n";
  }

  return 0;
}