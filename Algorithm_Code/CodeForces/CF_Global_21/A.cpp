#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5;
int a[N];

void solve()
{
    int n, z;
    cin >> n >> z;
    int maxv = -1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] |= z;
        maxv = max(maxv, a[i]);
    }
    cout << maxv << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}