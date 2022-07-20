#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 110;
int w[N];
int f[N][M][2];
int n, k;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    memset(f, -0x3f, sizeof f);
    f[0][0][0] = 0; //初始状态f[0][0][0]

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            f[i][j][0] = f[i - 1][j][0];
            if (j)
                f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][1] + w[i]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j][0] - w[i]);
        }
    }

    int res = 0;
    for (int j = 0; j <= k; ++j)
        res = max(res, f[n][j][0]); //目标状态f[n][j][0]

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