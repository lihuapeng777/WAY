#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1010, M = 85;
int v1[N], v2[N], val[N];
int f[M][M];
int n, m, t;

void solve()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++)
        cin >> v1[i] >> v2[i] >> val[i];

    memset(f, 0x3f, sizeof f); //求最小值->把除初始状态以外的的所有状态初始化为 INF
    f[0][0] = 0;               //把所有j,k小于0的初始状态都合并到f[0][0][0]中来转移,也就是下面的max操作

    for (int i = 1; i <= t; i++)
        for (int j = n; j >= 0; j--)
            for (int k = m; k >= 0; k--)
                f[j][k] = min(f[j][k], f[max(j - v1[i], 0ll)][max(k - v2[i], 0ll)] + val[i]);

    cout << f[n][m] << endl;
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
