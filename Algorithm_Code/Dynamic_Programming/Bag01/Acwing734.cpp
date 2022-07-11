/*
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110, M = 10010;
int n;

struct Stone
{
    int s, e, l;
} stones[N];

bool cmp(Stone a, Stone b) //贪心证明排序
{
    return a.s * b.l < b.s * a.l;
}

int f[N][M];

int solve()
{
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        int s, e, l;
        cin >> s >> e >> l;
        stones[i] = {s, e, l};
        m += s;
    }

    sort(stones + 1, stones + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= stones[i].s)
            {
                int s = stones[i].s, e = stones[i].e, l = stones[i].l;
                f[i][j] = max(f[i][j], f[i - 1][j - s] + max(0ll, e - l * (j - s)));
            }
        }

    int res = 0;
    for (int i = 0; i <= m; i++)
        res = max(res, f[n][i]);
    return res;
}
signed main()
{
    io;
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
        printf("Case #%d: %d\n", i, solve());
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

const int N = 110, M = 1e5 + 10;
int n, m;

struct Node
{
    int s, e, l;
    bool operator<(const Node &t) const
    {
        return s * t.l < t.s * l;
    }
} a[N];
int f[M]; //所用时间恰好为j的方案(能获得的最大能量)

int solve()
{
    //求恰好的背包dp,为了保证状态都是从起点转移的,要把非起点初始化为0x3f以避免转移
    memset(f, -0x3f, sizeof f);
    f[0] = m = 0; //当m=0 -> f[0]=0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i].s >> a[i].e >> a[i].l, m += a[i].s;

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= a[i].s; j--)
        {
            int pre = j - a[i].s; //吃两块能量石之间经历的时间->前一刻吃能量石的时间
            f[j] = max(f[j], f[pre] + a[i].e - pre * a[i].l);
        }
    int res = 0;
    for (int j = 0; j <= m; j++)
        res = max(res, f[j]);
    return res;
}
signed main()
{
    io;
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
        printf("Case #%d: %d\n", i, solve());
    return 0;
}
