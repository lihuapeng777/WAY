#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 110;
int w[N][N];
int f[N][N];
int n, m;
/*
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    memset(f, 0, sizeof f);
    f[1][1] = w[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 and j == 1)
                continue;
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
        }
    }
    cout << f[n][m] << endl;
}
*/

int dfs(int x, int y)
{
    if (x < 1 || y < 1)
        return 0;
    if (f[x][y] > 0)
        return f[x][y];
    return f[x][y] = max(dfs(x - 1, y), dfs(x, y - 1)) + w[x][y];
}

void solve()
{
    cin >> n >> m;
    memset(f, 0, sizeof f);
    memset(w, 0, sizeof w);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    cout << dfs(n, m) << endl;
}

signed main()
{
    io;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
