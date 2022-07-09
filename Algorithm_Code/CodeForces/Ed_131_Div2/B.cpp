#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

void solve()
{
    int n;
    cin >> n;

    int d = 2;
    cout << d << endl;

    vector<int> res;
    vector<bool> st(n + 1);
    for (int i = 0; i <= n; i++)
        st[i] = false;

    res.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            res.push_back(i), st[i] = true;
            for (int j = 2 * i; j <= n; j *= 2)
                res.push_back(j), st[j] = true;
        }
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << endl;
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
