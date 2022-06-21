#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;

    for (int j = 1; j <= m; j++)
        sum += j;

    for (int i = 2; i <= n; i++)
        sum += (i - 1) * m + m;

    cout << sum << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}