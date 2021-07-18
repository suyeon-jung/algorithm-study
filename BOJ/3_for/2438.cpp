#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N < 1 || N > 100) return 0;      // 1<= N <= 100 사이 return 0;
  for (int i = 0; i < N; i++) {        // 각 줄
    for (int j = 0; j < i + 1; j++) {  // 각 줄당 별개수
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}