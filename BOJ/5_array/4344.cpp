#include <iostream>
using namespace std;
int main(int argc, char const* argv[]) {
  int c, n;
  int sum, count, avg;

  cin >> c;
  for (int i = 0; i < c; i++) {
    cin >> n;
    int* score = new int[n];
    sum = 0, count = 0, avg = 0;

    for (int j = 0; j < n; j++) {
      cin >> score[j];
      sum += score[j];
    }
    avg = sum / n;
    for (int j = 0; j < n; j++) {
      if (score[j] > avg) count++;
    }

    cout << fixed;
    cout.precision(3);
    cout << (float)count / n * 100 << "%"
         << "\n";

    delete[] score;
  }
  return 0;
}
