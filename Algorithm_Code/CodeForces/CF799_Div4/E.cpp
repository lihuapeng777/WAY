#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 200010;
int a[N];
int n, k;

void solve()
{
    cin >> n >> k;
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum < k)
    {
        cout << "-1" << endl;
        return;
    }

    int s = 0, res = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        s += a[i];
        while (s > k and j < i)
            s -= a[j++];
        if (s == k)
            res = max(res, i - j + 1);
    }
    cout << n - res << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}