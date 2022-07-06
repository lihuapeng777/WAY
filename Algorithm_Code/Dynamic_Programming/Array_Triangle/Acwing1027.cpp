#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 15, M = 2 * N;
int w[N][N];
int f[M][N][N];
int a, b, c;
int n;

/*
void solve()
{
    cin >> n;
    while (cin >> a >> b >> c, a || b || c)
        w[a][b] = c;

    for (int k = 2; k <= 2 * n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int &t = f[k][i][j];
                if (k - i <= 0 || k - i > n || k - j <= 0 || k - j > n)
                    continue;

                //判断是否两条路线走到了相同的格子中
                int v = w[i][k - i];
                if (i != j)
                    v += w[j][k - j];

                t = max(t, f[k - 1][i - 1][j - 1]); // left left
                t = max(t, f[k - 1][i][j - 1]);     // up left
                t = max(t, f[k - 1][i - 1][j]);     // left up
                t = max(t, f[k - 1][i][j]);         // up up
                t += v;
            }
        }
    }
    cout << f[2 * n][n][n] << endl;
}
*/

int dfs(int k, int i, int j)
{
    if (f[k][i][j] >= 0)
        return f[k][i][j];
    if (k == 2 and i == 1 and j == 1)
        return f[k][i][j] = w[1][1];
    if (i <= 0 || i >= k || j <= 0 || j >= k)
        return -0x3f3f3f3f;

    int v = w[i][k - i];
    if (i != j)
        v += w[j][k - j];

    int &t = f[k][i][j];
    t = max(t, dfs(k - 1, i, j));
    t = max(t, dfs(k - 1, i - 1, j));
    t = max(t, dfs(k - 1, i, j - 1));
    t = max(t, dfs(k - 1, i - 1, j - 1));

    return f[k][i][j] = t + v;
}

void solve()
{
    memset(f, -1, sizeof f);
    cin >> n;
    while (cin >> a >> b >> c, a || b || c)
        w[a][b] += c;
    cout << dfs(2 * n, n, n) << endl;
}

signed main()
{
    io;
    int T = 1;
    while (T--)
        solve();
    return 0;
}
