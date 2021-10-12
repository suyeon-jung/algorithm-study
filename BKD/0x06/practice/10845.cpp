#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) { dat[tail++] = x; }
void pop() { head++; }
int front() { return dat[head]; }
int back() { return dat[tail - 1]; }
int size() { return tail - head; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while (N--) {
    // 명령
    string com;
    cin >> com;
    if (com == "push") {
      int input;
      cin >> input;
      push(input);
    } else if (com == "pop") {
      if (tail == head)
        cout << -1 << '\n';
      else {
        cout << front() << '\n';
        pop();
      }
    } else if (com == "size") {
      cout << size() << '\n';
    } else if (com == "empty") {
      cout << (tail == head) << '\n';
    } else if (com == "front") {
      if (tail == head)
        cout << -1 << '\n';
      else
        cout << front() << '\n';
    } else if (com == "back") {
      if (tail == head)
        cout << -1 << '\n';
      else
        cout << back() << '\n';
    }
  }
}