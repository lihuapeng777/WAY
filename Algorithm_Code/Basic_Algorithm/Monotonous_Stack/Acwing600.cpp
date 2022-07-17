#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int h[N];
int f[N];
stack<int> s;
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() and h[s.top()] <= h[i])
            s.pop();
        f[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
        cout << f[i] << endl;
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