#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110;
int f[N];
int weight[N][N], val[N][N], s[N];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i]; //第i组物品的个数
        for (int j = 1; j <= s[i]; j++)
            cin >> weight[i][j] >> val[i][j];
    }

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= s[i]; k++)
                if (j >= weight[i][k])
                    f[j] = max(f[j], f[j - weight[i][k]] + val[i][k]);
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
