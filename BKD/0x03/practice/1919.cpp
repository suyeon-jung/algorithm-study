#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int first_freq[26], second_freq[26];
int diff;

string s1, s2;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s1 >> s2;

  for (char c : s1) first_freq[c - 'a']++;
  for (char c : s2) second_freq[c - 'a']++;

  for (int i = 0; i < 26; i++) diff += abs(first_freq[i] - second_freq[i]);

  cout << diff << '\n';
}