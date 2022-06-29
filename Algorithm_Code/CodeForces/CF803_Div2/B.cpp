#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 2e5 + 10;
int a[N];
int n, k;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (k == 1)
    {
        cout << ((n - 3) / 2) + 1 << endl;
    }
    else
    {
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (a[i] > a[i - 1] + a[i + 1])
                cnt++;
        }
        cout << cnt << endl;
    }
}

signed main()
{
    io;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
