#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 510, M = 6010;
int weight[N], val[N], s[N];
int f[M];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> val[i] >> s[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= weight[i]; j--)
            for (int k = 0; k <= s[i]; k++)
                if (j - k * weight[i] >= 0)
                    f[j] = max(f[j], f[j - k * weight[i]] + k * val[i]);
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
