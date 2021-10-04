#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

/*
 * addr 번지에 num 삽입
 * 1. 새로운 원소를 생성 (unused = 새로운 원소가 들어갈 자리)
 * 2. 새 원소의 pre 값에 삽입할 위치의 주소를 대입
 * 3. 새 원소의 nxt 값에 삽입할 위치의 nxt 값을 대입
 * 4. 삽입할 위치의 nxt 값과 삽입할 위치의 다음 원소의 pre 값을 새 원소로 변경
 * 5. unused 1 증가(다음 수행에서 비어있는 번지를 쓸 수 있도록)
 */

void insert(int addr, int num) {
  // 새로운 원소 생성
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];

  // addr 다음 번지가 있다면
  if (nxt[addr] != -1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}

/*
 * 1. 이전 위치의 nxt를 삭제할 위치의 nxt로 변경
 * 2. 다음 위치의 pre를 삭제할 위치의 pre로 변경
 * 제거된 내용에 대한 처리를 안해줘서 메모리 leak 발생
 */
void erase(int addr) {
  nxt[pre[addr]] = nxt[addr];
  /*    dummy node가 있기 때문에 pre[addr] 이 -1이 아님이 보장되지만
     nxt[addr]은 보장이 안되므로 체크해줘야 함 */
  if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

// 전체 출력
void traverse() {
  int cur = nxt[0];
  while (cur != -1) {
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test() {
  cout << "****** insert_test *****\n";
  insert(0, 10);  // 10(address=1)
  traverse();
  insert(0, 30);  // 30(address=2) 10
  traverse();
  insert(2, 40);  // 30 40(address=3) 10
  traverse();
  insert(1, 20);  // 30 40 10 20(address=4)
  traverse();
  insert(4, 70);  // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test() {
  cout << "****** erase_test *****\n";
  erase(1);  // 30 40 20 70
  traverse();
  erase(2);  // 40 20 70
  traverse();
  erase(4);  // 40 70
  traverse();
  erase(5);  // 40
  traverse();
}

int main(void) {
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);
  insert_test();
  erase_test();
}