#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 40;
int a[N][N];
int n;

PII find(int num)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == num)
            {
                return {i, j};
            }
        }
    }
}

void op1(int x, int y, int num)
{
    a[n][y + 1] = num;
}

void op2(int x, int y, int num)
{
    a[x - 1][1] = num;
}

void op3(int x, int y, int num)
{
    a[x + 1][y] = num;
}

void op4(int x, int y, int num)
{
    a[x - 1][y + 1] = num;
}

void op5(int x, int y, int num)
{
    a[x + 1][y] = num;
}

int main()
{
    cin >> n;
    // 1的处理
    a[1][(n / 2) + 1] = 1;

    for (int i = 2; i <= n * n; i++)
    {
        int x = find(i - 1).first;
        int y = find(i - 1).second;

        if (x == 1 and y != n)
            op1(x, y, i);
        else if (y == n and x != 1)
            op2(x, y, i);
        else if (x == 1 and y == n)
            op3(x, y, i);
        else if (x != 1 and y != n)
        {
            if (a[x - 1][y + 1] == 0)
                op4(x, y, i);
            else
                op5(x, y, i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        puts("");
    }

    return 0;
}