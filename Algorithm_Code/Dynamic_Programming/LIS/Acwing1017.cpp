#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 110;
int w[N];
int f_up[N], f_dw[N];
int n;

void solve()
{
    memset(f_up, 0, sizeof f_up);
    memset(f_dw, 0, sizeof f_dw);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    //正向最长上升子序列
    w[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (w[j] < w[i])
                f_up[i] = max(f_up[i], f_up[j] + 1);
        }
    }

    //反向最长上升子序列
    w[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = n + 1; j > i; j--)
        {
            if (w[i] > w[j])
                f_dw[i] = max(f_dw[i], f_dw[j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, f_up[i]);
        res = max(res, f_dw[i]);
    }

    cout << res << endl;
}

signed main()
{
    io;
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
