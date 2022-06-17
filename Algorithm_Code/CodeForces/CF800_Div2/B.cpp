#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (s[i] != s[i - 1])
        {
            ans += i;
        }
    }

    cout << ans << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}