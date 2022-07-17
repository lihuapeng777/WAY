#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int h[N], l[N], r[N];
stack<int> s;

void solve()
{
    int n;
    while (cin >> n, n)
    {
        for (int i = 1; i <= n; i++)
            cin >> h[i];

        h[0] = h[n + 1] = -1;

        s.push(0);
        for (int i = 1; i <= n; i++)
        {
            while (h[i] <= h[s.top()])
                s.pop();
            l[i] = s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        s.push(n + 1);
        for (int i = n; i >= 1; i--)
        {
            while (h[s.top()] >= h[i])
                s.pop();
            r[i] = s.top();
            s.push(i);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, h[i] * (r[i] - l[i] - 1));
        cout << ans << endl;
    }
}

signed main()
{
    io;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}