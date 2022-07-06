#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 3010;
int a[N], b[N];
int f[N][N];
int n;

/*
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
            {
                for (int k = 0; k < j; k++)
                {
                    if (b[j] > b[k])
                        f[i][j] = max(f[i][j], f[i - 1][k] + 1);
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n; i++)
        res = max(res, f[n][i]);
    cout << res << endl;
}*/

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    // dp
    for (int i = 1; i <= n; ++i)
    {
        int maxv = 1;
        for (int j = 1; j <= n; ++j)
        {
            f[i][j] = f[i - 1][j];
            if (b[j] == a[i])
                f[i][j] = max(f[i][j], maxv);
            if (b[j] < a[i])
                maxv = max(maxv, f[i - 1][j] + 1);
        }
    }

    // find result
    int res = 0;
    for (int i = 0; i <= n; ++i)
        res = max(res, f[n][i]);
    cout << res << endl;
}

signed main()
{
    io;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
