#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 1010;
int w[N];
int f_up[N], f_dw[N];
int n;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    //正向上升
    w[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (w[j] < w[i])
                f_up[i] = max(f_up[i], f_up[j] + 1);
        }
    }

    //反向下降
    w[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = n + 1; j > i; j--)
        {
            if (w[j] < w[i])
                f_dw[i] = max(f_dw[i], f_dw[j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, f_dw[i] + f_up[i] - 1);
    }

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
