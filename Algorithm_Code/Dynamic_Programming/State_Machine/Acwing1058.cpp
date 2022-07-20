#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int w[N];
int f[N][3];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][2]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - w[i]);
        f[i][2] = f[i - 1][1] + w[i];
    }
    cout << max(f[n][0], f[n][2]) << endl;
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