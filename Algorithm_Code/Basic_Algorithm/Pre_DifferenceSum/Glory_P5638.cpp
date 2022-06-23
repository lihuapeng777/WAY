#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;
int a[N], pre[N];
int n, m;

void solve()
{
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int maxv = 0;
    for (int i = m; i <= n; i++)
    {
        maxv = max(maxv, pre[i] - pre[i - m]);
    }

    sum -= maxv;
    cout << sum << '\n';
}

signed main()
{
    solve();
    return 0;
}