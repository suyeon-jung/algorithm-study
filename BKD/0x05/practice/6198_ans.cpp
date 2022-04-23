#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAX 1000000005

stack<int> s; // (height)
long long ans;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    long long h;
    while (N--)
    {
        cin >> h;
        while (!s.empty() && s.top() <= h)
            s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans;
}