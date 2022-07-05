#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 55;
int ans[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    ans[1][1] = 1;
    for (int i = 2; i <= n; i++)
        if (i & 1)
            ans[i][1] = ans[i - 1][1];
        else
            ans[i][1] = (ans[i - 1][1] ^ 1);
    for (int i = 2; i <= m; i++)
        if (i & 1)
            ans[1][i] = ans[1][i - 1];
        else
            ans[1][i] = (ans[1][i - 1] ^ 1);
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
        {
            if (i & 1)
                ans[i][j] = ans[i - 1][j];
            else
                ans[i][j] = (ans[i - 1][j] ^ 1);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << ans[i][j] << " \n"[j == m];
}

signed main()
{
    io;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
