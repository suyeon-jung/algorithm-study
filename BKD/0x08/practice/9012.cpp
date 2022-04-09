#include <iostream>
#include <string>
#include <stack>
using namespace std;

int test_case;

bool check(string str)
{
    stack<char> s;
    for (auto c : str)
    {
        if (c == '(')
            s.push(c);
        else
        {
            if (!s.empty())
                s.pop();
            else
                return false;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> test_case;
    while (test_case--)
    {
        string str;
        cin >> str;

        if (check(str))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}