#include <iostream>
using namespace std;

int occur[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int result;
    cin >> a >> b >> c;

    result = a * b * c;

    while (result)
    {
        occur[result % 10]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << occur[i] << '\n';
    }
}