#include <string>
#include <vector>
#include <stack>
using namespace std;

/**
 * 보조 컨테이너 - 스택
 */
int solution(vector<int> order)
{
  int answer = 0;  // 실을 수 있는 상자 개수
  int cur = 1;     // 현재 상자
  stack<int> belt; // 보조 컨테이너 벨트

  for (auto box : order)
  {
    if (cur < box)
    {
      while (cur < box)
      {
        belt.push(cur);
        cur++;
      }
      cur++;
    }
    else if (cur == box)
      cur++;
    else
    {
      if (belt.top() != box)
        return answer;
      belt.pop();
    }
    answer++;
  }
  return answer;
}