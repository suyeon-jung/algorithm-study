#include <iostream>
#include <list>
using namespace std;

int N, K;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  list<int> L;

  // 1~N 까지의 숫자 리스트에 추가
  for (int i = 1; i <= N; i++) L.push_back(i);
  list<int>::iterator t = L.begin();

  cout << "<";
  int temp;
  while (L.size()) {
    for (int i = 1; i < K; i++) {
      if (++t == L.end()) {
        t = L.begin();
        continue;
      }
    }

    // 순열 출력부
    if (L.size() == 1)
      cout << *t;
    else
      cout << *t << ", ";

    t = L.erase(t);
    // 삭제한 원소 자리가 이미 end인 경우 begin으로 보내줌
    t = (t == L.end()) ? L.begin() : t;
  }

  cout << ">";
}
