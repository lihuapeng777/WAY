#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 55;
int g[N][N];
int f[N * 2][N][N];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    for (int k = 2; k <= n + m; k++)
        for (int i = max(1ll, k - m); i <= n && i < k; i++)
            for (int j = max(1ll, k - m); j <= n && j < k; j++)
                for (int a = 0; a <= 1; a++)
                    for (int b = 0; b <= 1; b++)
                    {
                        int t = g[i][k - i];
                        if (i != j || k == 2 || k == n + m)
                        {
                            t += g[j][k - j];
                            f[k][i][j] = max(f[k][i][j], f[k - 1][i - a][j - b] + t);
                        }
                    }

    printf("%d\n", f[n + m][n][n]);
}

signed main()
{
    io;
    int T = 1;
    while (T--)
        solve();
    return 0;
}
