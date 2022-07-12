/*
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 5, M = 1010;
int v[N] = {0, 10, 20, 50, 100};
int f[N][M];
int n = 4, m;

void solve()
{
    cin >> m;

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; v[i] * k <= j; k++)
                f[i][j] += f[i - 1][j - v[i] * k];

    cout << f[n][m] << endl;
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
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 5, M = 1010;
int v[N] = {0, 10, 20, 50, 100};
int f[M];
int n = 4, m;

void solve()
{
    cin >> m;

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] += f[j - v[i]];
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
