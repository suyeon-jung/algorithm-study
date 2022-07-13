#include <iostream>
using namespace std;

int d[11];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    cin >> test_case;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    // d를 미리 다 구해놓는 것이 효율적
    for (int i = 4; i <= 11; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    while (test_case--)
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}