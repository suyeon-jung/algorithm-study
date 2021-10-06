#include <iostream>
using namespace std;

int Y, M;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  int sec;
  for (int i = 0; i < N; i++) {
    cin >> sec;
    Y += (sec / 30 + 1) * 10;
    M += (sec / 60 + 1) * 15;
  }

  if (Y < M)
    cout << "Y " << Y << '\n';
  else if (Y > M)
    cout << "M " << M << '\n';
  else
    cout << "Y M " << Y << '\n';

  return 0;
}