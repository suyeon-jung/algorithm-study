#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int N, count;
  int five, three;

  cin >> N;

  five = N / 5;

  while (five != -1) {
    // 5kg 설탕 봉지 개수를 제외하고 남은 kg이 3의 배수라면
    if ((N - five * 5) % 3 == 0) {
      break;
    }
    five -= 1;
  }

  if (five == -1) {
    count = -1;
  } else {
    three = (N - 5 * five) / 3;
    count = five + three;
  }

  cout << five << " " << three << " " << count;
  return 0;
}
