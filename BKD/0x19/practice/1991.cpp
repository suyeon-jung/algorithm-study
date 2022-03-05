#include <iostream>
#include <vector>
using namespace std;

#define MAX 27

char lc[MAX];
char rc[MAX];

void preorder(char cur)
{
    int idx = cur - 'A';
    cout << cur;
    if (lc[idx] && lc[idx] != '.')
        preorder(lc[idx]);
    if (rc[idx] && rc[idx] != '.')
        preorder(rc[idx]);
}
void inorder(char cur)
{
    int idx = cur - 'A';

    if (lc[idx] && lc[idx] != '.')
        inorder(lc[idx]);
    cout << cur;
    if (rc[idx] && rc[idx] != '.')
        inorder(rc[idx]);
}
void postorder(char cur)
{
    int idx = cur - 'A';

    if (lc[idx] && lc[idx] != '.')
        postorder(lc[idx]);
    if (rc[idx] && rc[idx] != '.')
        postorder(rc[idx]);
    cout << cur;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int node_num;
    char cur, left, right;

    cin >> node_num;

    for (int i = 0; i < node_num; i++)
    {
        cin >> cur >> left >> right;
        lc[cur - 'A'] = left;
        rc[cur - 'A'] = right;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}