#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 3010;
int g[N][N], h[N][N];
int l[N], r[N];
stack<int> s;
int n, m, p;

int work(int h[])
{
    int res = 0;
    for (int i = 1; i <= m + 1; i++)
    {
        while (!s.empty() and h[s.top()] >= h[i])
        {
            int l = s.top();
            s.pop();
            res = max(res, h[l] * (s.empty() == 0 ? i - 1 : i - s.top() - 1));
        }
        s.push(i);
    }
    return res;
}

void solve()
{
    cin >> n >> m >> p;
    while (p--)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }

    //计算本行本列向上最多有多少可用位置
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!g[i][j])                  //如果是0的话
                h[i][j] = h[i - 1][j] + 1; //地图

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, work[h[i]]);
    cout << res << endl;
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