#include <iostream>
using namespace std;

bool check(int x, int y, int *a)
{
    for (int i = 1; i <= x; i++)
    {
        if (a[i] == y)
            return false;
        if (a[i] + i == x + y)
            return false;
        if (i - a[i] == x - y)
            return false;
    }

    return true;
}

void dfs(int row, int n, int *cnt, int *a)
{
    if (row == n + 1)
    // 边界判断
    {
        (*cnt)++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check(row, i, a))
        {
            a[row] = i;
            dfs(row + 1, n, cnt, a);
            a[row] = 0;
        }
    }

    return;
}

int main()
{
    int quantity;
    cin >> quantity;
    int *a = new int[quantity]();
    int cnt = 0;
    dfs(1, quantity, &cnt, a);
    cout << cnt << endl;

    delete[] a;
}