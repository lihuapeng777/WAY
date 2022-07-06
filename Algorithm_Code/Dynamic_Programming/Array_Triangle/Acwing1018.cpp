#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 110;
int w[N][N];
int f[N][N];
int n;
/*
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> w[i][j];

    memset(f, 0x3f, sizeof f);
    f[1][1] = w[1][1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);
            f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);
        }
    }

    cout << f[n][n] << endl;
}
*/

int dfs(int x, int y)
{
    if (f[x][y] >= 0)
        return f[x][y];
    if (x == 1 and y == 1)
        return w[x][y];
    if (x < 1 or y < 1)
        return 0x3f3f3f3f;

    int t = 0x3f3f3f3f;
    t = min(t, dfs(x - 1, y));
    t = min(t, dfs(x, y - 1));
    return f[x][y] = t + w[x][y];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> w[i][j];

    memset(f, -1, sizeof f);
    cout << dfs(n, n) << endl;
}

signed main()
{
    io;
    int T = 1;
    while (T--)
        solve();
    return 0;
}
