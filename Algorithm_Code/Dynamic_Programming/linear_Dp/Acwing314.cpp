#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 5010;
int w[N];
int f[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    //反向最长上升子序列
    int res = -1;
    for (int i = n; i >= 1; i--)
    {
        f[i] = 1;
        for (int j = n + 1; j > i; j--)
        {
            if (w[i] > w[j])
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }

    cout << res << " ";

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (f[i] == res)
            cnt++;

    cout << cnt << endl;
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
