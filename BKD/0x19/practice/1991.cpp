#include <iostream>
#include <vector>
using namespace std;

#define MAX 27

int node_num;
int lc[MAX];
int rc[MAX];

// 전위 순회
void preorder(int cur)
{
    cout << char(cur + 'A' - 1);
    if (lc[cur])
        preorder(lc[cur]);
    if (rc[cur])
        preorder(rc[cur]);
}
// 중위 순회
void inorder(int cur)
{
    if (lc[cur])
        inorder(lc[cur]);
    cout << char(cur + 'A' - 1);
    if (rc[cur])
        inorder(rc[cur]);
}
// 후위 순회
void postorder(int cur)
{
    if (lc[cur])
        postorder(lc[cur]);
    if (rc[cur])
        postorder(rc[cur]);
    cout << char(cur + 'A' - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char cur, left, right;

    cin >> node_num;

    for (int i = 0; i < node_num; i++)
    {
        cin >> cur >> left >> right;
        if (left != '.')
            lc[cur - 'A' + 1] = left - 'A' + 1;
        if (right != '.')
            rc[cur - 'A' + 1] = right - 'A' + 1;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
}