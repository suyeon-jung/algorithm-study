// 직접 구현 방식
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char c) {
  // 새로운 원소 생성
  dat[unused] = c;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];

  if (nxt[addr] != -1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}
void erase(int addr) {
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
  int cur = nxt[0];
  while (cur != -1) {
    cout << dat[cur];
    cur = nxt[cur];
  }
  cout << "\n\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // pre, nxt 배열 초기화
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);
  string init;
  cin >> init;
  int cursor = 0;

  // 리스트 초기화
  for (auto c : init) {
    insert(cursor, c);
    cursor++;
  }

  int m;
  cin >> m;

  while (m--) {
    char comm;
    cin >> comm;

    if (comm == 'P') {
      // 삽입할 문자
      char add;
      cin >> add;
      insert(cursor, add);
      cursor = nxt[cursor];
    } else if (comm == 'L') {
      if (pre[cursor] != -1) cursor = pre[cursor];
    } else if (comm == 'D') {
      if (nxt[cursor] != -1) cursor = nxt[cursor];
    } else {  // 'B' 인 경우 커서 왼쪽 문자 삭제
      if (cursor != 0) {
        erase(cursor);
        cursor = pre[cursor];
      }
    }
  }
  traverse();
  return 0;
}
