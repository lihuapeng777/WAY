#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int M = 2010;
int f[M];
int n, m;
struct good
{
    int weight, val;
};

void solve()
{
    cin >> n >> m;
    vector<good> Good;

    for (int i = 1; i <= n; i++)
    {
        int weight, val, cnt;
        cin >> weight >> val >> cnt;
        for (int k = 1; k <= cnt; k *= 2)
        {
            cnt -= k;
            Good.push_back({k * weight, k * val});
        }
        if (cnt > 0)
            Good.push_back({cnt * weight, cnt * val});
    }

    for (auto good : Good)
    {
        for (int j = m; j >= good.weight; j--)
            f[j] = max(f[j], f[j - good.weight] + good.val);
    }
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
