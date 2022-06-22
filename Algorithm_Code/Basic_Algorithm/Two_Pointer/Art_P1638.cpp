#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;
const int M = 2e3 + 10;
int a[N], flag[M];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = 1, r = 1;
    int ansl = 0, ansr = 0;
    int maxv = 0x3f3f3f3f;
    int cnt = 0;

    for (r = 1; r <= n; ++r)
    {
        if (!flag[a[r]])
            cnt++;
        flag[a[r]]++;
        while (flag[a[l]] > 1)
        {
            flag[a[l]]--, l++;
        }
        if (cnt == m)
        {
            if (r - l + 1 < maxv)
                maxv = r - l + 1, ansl = l, ansr = r;
        }
    }
    cout << ansl << " " << ansr << endl;
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T = 1;
    while (T--)
        solve();
    return 0;
}
