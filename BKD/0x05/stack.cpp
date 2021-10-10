#include <iostream>
using namespace std;

const int MX = 1000005;
// stack
int dat[MX];
// top index = length
int pos = 0;

// stack에 x추가
void push(int x) { dat[pos++] = x; }
// top 에 있는 원소 제거(data값 자체는 굳이 바꾸지 않아도 됨)
void pop() { pos--; }
// top에 있는 원소 값 확인
int top() { return dat[pos - 1]; }

void test() {
  push(5);
  push(4);
  push(3);
  cout << top() << '\n';  // 3
  pop();
  pop();
  cout << top() << '\n';  // 5
  push(10);
  push(12);
  cout << top() << '\n';  // 12
  pop();
  cout << top() << '\n';  // 10
}

int main(void) { test(); }