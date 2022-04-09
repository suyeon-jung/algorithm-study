#include <iostream>
#include <stack>
using namespace std;

int word_num, ans;

bool check(string str)
{
    stack<char> s;
    for (auto c : str)
    {
        if (!s.empty() && s.top() == c)
            s.pop();
        else
            s.push(c);
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

    cin >> word_num;
    while (word_num--)
    {
        string str;
        cin >> str;
        if (check(str))
            ans++;
    }
    cout << ans << '\n';
}