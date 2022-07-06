#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1010;
int w[N];
int f[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = w[i];
        for (int j = 0; j < i; j++)
        {
            if (w[i] > w[j])
                f[i] = max(f[i], f[j] + w[i]);
        }
        res = max(res, f[i]);
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
