#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<int> v1(3, 5);       // {5,5,5};
  cout << v1.size() << '\n';  // 3
  v1.push_back(7);            // {5,5,5,7};

  vector<int> v2(2);             // {0,0};
  v2.insert(v2.begin() + 1, 3);  // {0,3,0};

  vector<int> v3 = {1, 2, 3, 4};  // {1,2,3,4}
  v3.erase(v3.begin() + 2);       // {1,2,4};

  vector<int> v4;  // {}
  v4 = v3;  // {1,2,4} deep copy 이후에 v4를 바꿔도 v3에 영향을 주지 않음
  cout << v4[0] << v4[1] << v4[2] << '\n';
  v4.pop_back();  // {1,2}
  v4.clear();     // {}

  cout << v3[0] << v3[1] << v3[2] << '\n';

  vector<int> v5 = {1, 2, 3, 4, 5};

  // 1. reange-based for loop (since C++11)
  // 여기서 int& e로 하면 원본에 영향을 주게 됨
  for (int e : v5) cout << e << ' ';

  // 2. not bad
  for (int i = 0; i < v5.size(); i++) cout << v5[i] << ' ';

  // 3. ***WRONG***
  /*
    vector의 size 메서드는 unsigned int를 반환 -> v5가 0 길이일때 unsigned
    overflow가 발생
   */
  for (int i = 0; i <= v5.size() - 1; i++) cout << v5[i] << ' ';
}