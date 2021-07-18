#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
  // 과목의 개수
  int n;
  double sum = 0, max = 0;
  double* score;

  cin >> n;
  if (n > 1000) return 0;

  score = new double[n];

  for (int i = 0; i < n; i++) {
    cin >> score[i];
    if (max < score[i]) max = score[i];
  }

  for (int i = 0; i < n; i++) {
    score[i] = score[i] / max * 100.0;
    sum += score[i];
  }
  cout << fixed;
  cout.precision(2);
  cout << sum / (double)n << "\n";
  return 0;
}
