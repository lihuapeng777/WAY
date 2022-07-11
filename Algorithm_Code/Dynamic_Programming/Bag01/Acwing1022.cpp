#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110, M = 1010, K = 510;
int v1[N], v2[N];
int f[M][K];
int n, m, t;

void solve()
{
    // input
    cin >> m >> t >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v1[i] >> v2[i];

    // dp
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= v1[i]; --j)
        {
            for (int k = t - 1; k >= v2[i]; --k)
            {
                f[j][k] = max(f[j][k], f[j - v1[i]][k - v2[i]] + 1);
            }
        }
    }

    // output
    cout << f[m][t - 1] << " ";
    //找到满足最大价值的所有状态里，第二维费用消耗最少的
    int cost_health = t;
    for (int k = 0; k <= t - 1; ++k)
    {
        if (f[m][k] == f[m][t - 1])
        {
            cost_health = min(cost_health, k);
        }
    }
    cout << t - cost_health << endl;
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
