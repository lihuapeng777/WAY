#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1010, K = 110;
int v1[N], v2[N], val[N];
int f[K][K];
int n, V, W;

void solve()
{
    cin >> n >> V >> W;
    for (int i = 1; i <= n; i++)
        cin >> v1[i] >> v2[i] >> val[i];

    for (int i = 1; i <= n; i++)
        for (int j = V; j >= v1[i]; j--)
            for (int k = W; k >= v2[i]; k--)
                f[j][k] = max(f[j][k], f[j - v1[i]][k - v2[i]] + val[i]);
    cout << f[V][W] << endl;
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
