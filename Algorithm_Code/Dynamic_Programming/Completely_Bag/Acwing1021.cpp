#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 20, M = 3010;
int v[N];
int f[M];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] += f[j - v[i]];
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
