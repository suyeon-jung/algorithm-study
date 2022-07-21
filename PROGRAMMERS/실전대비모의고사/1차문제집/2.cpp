#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * want : 정현이가 원하는 제품
 * number : 정현이가 원하는 제품의 수량
 * discount : XYZ 마트에서 할인하는 제품
 */

bool check(vector<string> wa, vector<int> nu, vector<string> dis)
{
  for (int i = 0; i < wa.size(); i++)
  {
    auto it = dis.begin();
    while (nu[i])
    {
      it = find(it, dis.end(), wa[i]);
      if (it != dis.end())
        nu[i]--;
      else // 만족하지 못하는 경우
        return false;
      it++;
    }
  }
  return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
  int answer = 0;

  for (int i = 0; i < discount.size() - 9; i++)
  {
    vector<string> sub = {discount.begin() + i, discount.begin() + i + 10}; // 열흘간의 할인 목록
    bool result = check(want, number, sub);
    if (result == true)
      answer++;
  }
  return answer;
}