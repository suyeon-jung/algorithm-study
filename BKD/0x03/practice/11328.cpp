#include <iostream>
#include <string>
using namespace std;

string strfry(string s1, string s2) {
  // 배열값 0으로 초기화
  int freq[26] = {};
  for (char c : s1) freq[c - 'a']++;
  for (char c : s2) freq[c - 'a']--;

  for (int i = 0; i < 26; i++) {
    // 어떤 알파벳이더라도 개수가 남아있으면 안됨
    if (freq[i]) return "Impossible";
  }
  return "Possible";
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << strfry(s1, s2) << '\n';
  }
}