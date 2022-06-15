#include <bits/stdc++.h>
using namespace std;
void solve()
{
    char a[10][10] = {0};

    for (int i = 1; i <= 8; i++)
    {
        scanf("%s", a[i]);
    }

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            if (j >= 1 and a[i - 1][j - 1] == '#' and a[i - 1][j + 1] == '#' and a[i + 1][j - 1] == '#' and a[i + 1][j + 1] == '#')
            {
                cout << i << " " << j + 1 << endl;
                return;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}