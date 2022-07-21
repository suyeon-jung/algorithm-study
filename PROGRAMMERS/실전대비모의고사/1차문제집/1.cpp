#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
vector<char> partner;

int cnt[10]; // 숫자의 빈도수

// 빈도수 세기
void count(string str)
{
  for (int i = 0; i < str.length(); i++)
    cnt[str[i] - '0']++;
}

// 짝꿍 찾기
void get_partner(string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (cnt[str[i] - '0'] > 0)
    {
      partner.push_back(str[i]);
      cnt[str[i] - '0']--;
    }
  }
}

string solution(string X, string Y)
{

  string answer = "";

  count(X);       // X 문자열에서 각 숫자의 빈도수 세기
  get_partner(Y); // 짝꿍 찾기

  // partner 벡터를 내림차순 정렬
  sort(partner.begin(), partner.end(), greater<char>());

  if (partner.empty())
    answer = "-1";
  else
  {
    if (partner.front() == '0') // 처음 문자가 0 인 경우
      answer = "0";
    else
    {
      for (auto p : partner)
        answer += p;
    }
  }
  return answer;
}