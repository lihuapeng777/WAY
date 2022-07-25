#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 5, INF = 0x3f3f3f3f;
int a[maxn], d[maxn];
pair<int, int> p[maxn];

int main()
{

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i], d[i] = 0;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            d[x]++, d[y]++;
            p[i] = {x, y};
        }
        if (m & 1)
        {
            int res = INF;
            for (int i = 1; i <= n; i++)
                if (d[i] & 1)
                    res = min(res, a[i]);
            for (int i = 1; i <= m; i++)
                if ((d[p[i].first] + d[p[i].second] + 1 & 1))
                    res = min(res, a[p[i].first] + a[p[i].second]);
            cout << res << '\n';
        }
        else
            cout << 0 << '\n';
    }
}