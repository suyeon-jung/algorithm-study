#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    stack<char> s;
    string str;
    int ans = 0;

    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(') // 여는 괄호인 경우
            s.push('(');
        else // 닫는 괄호인 경우(레이저인 경우/레이저가 아닌 경우)
        {
            if (str[i - 1] == '(') // 레이저인 경우
            {
                s.pop();
                ans += s.size();
            }
            else // 레이저가 아닌 경우
            {
                s.pop();
                ans++;
            }
        }
    }
    cout << ans;
}