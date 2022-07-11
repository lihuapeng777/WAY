#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110, M = 10030;
int v[N];
int f[M];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    //和为0的方案数为1,即任何一个数字都不选
    f[0] = 1; //方案数dp的核心
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
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
