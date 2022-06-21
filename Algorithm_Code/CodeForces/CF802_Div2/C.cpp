#include <bits/stdc++.h>
#pragma G++ optimize(2)
using namespace std;

#define int long long
const int N = 2e5 + 10;
int a[N];
int s[N];
// https://zhuanlan.zhihu.com/p/531272396
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = a[i] - a[i - 1];
    }

    int res = 0;
    for (int i = 2; i <= n; i++)
    {
        if (s[i] > 0)
            res += s[i];
        else
        {
            res += abs(s[i]);
            s[1] -= abs(s[i]);
        }
    }

    res += abs(s[1]);
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}