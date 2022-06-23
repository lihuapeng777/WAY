#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int a[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    int maxv = -0x3f3f3f3f;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        maxv = max(maxv, sum);
        if (sum < 0)
            sum = 0;
    }

    cout << maxv << '\n';
}

signed main()
{
    solve();
    return 0;
}