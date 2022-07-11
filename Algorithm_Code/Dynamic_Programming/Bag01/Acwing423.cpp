#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1010;
int m, n;
int f[N];

void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int weight, val;
        cin >> weight >> val;
        for (int j = m; j >= weight; j--)
        {
            f[j] = max(f[j], f[j - weight] + val);
        }
    }
    cout << f[m] << endl;
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
