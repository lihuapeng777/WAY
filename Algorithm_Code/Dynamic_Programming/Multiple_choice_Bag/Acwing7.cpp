#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1010;
int n, m;
int v[N], w[N], s[N];
int f[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; ++i)
    {
        //完全背包
        if (!s[i])
        {
            for (int j = v[i]; j <= m; ++j)
            {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
        else
        {
            //把多重背包用二进制优化
            //这样就变成做多个01背包了
            if (s[i] == -1)
                s[i] = 1;
            //二进制优化
            for (int k = 1; k <= s[i]; k *= 2)
            {
                for (int j = m; j >= k * v[i]; --j)
                {
                    f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
                }
                s[i] -= k;
            }
            if (s[i]) //如果有剩余->再做一次
            {
                for (int j = m; j >= s[i] * v[i]; --j)
                {
                    f[j] = max(f[j], f[j - s[i] * v[i]] + s[i] * w[i]);
                }
            }
        }
    }

    cout << f[m] << endl;
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
