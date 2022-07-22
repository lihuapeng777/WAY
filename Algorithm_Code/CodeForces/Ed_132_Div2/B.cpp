#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int a[N];
int s1[N];
int s2[N];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i++)
        s1[i] = s1[i - 1] + max(0ll, a[i - 1] - a[i]);
    for (int i = n - 1; i >= 1; i--)
        s2[i] = s2[i + 1] + max(0ll, a[i + 1] - a[i]);

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
            cout << "0" << endl;
        else if (l < r)
            cout << s1[r] - s1[l] << endl;
        else
            cout << s2[r] - s2[l] << endl;
    }
}

signed main()
{
    io;
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}