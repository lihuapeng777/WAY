#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 31, M = 5010;
PII g[N];
int s[N];
int f[N][M];
int ans[N];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i].first; //孩子的贪婪程度
        g[i].second = i;   //孩子的当前位置
    }
    //将孩子的贪婪程度从大->小进行排序
    sort(g + 1, g + n + 1);
    reverse(g + 1, g + n + 1);

    //求前缀和
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + g[i].first;

    //因为要求的是方案的最小值->故初始化为正无穷
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0; //将j:0块饼干分配给前i:0个孩子,且分配的饼干单调下降的方案数量
    //属性MIN
    //状态计算：集合划分的区域。最后有几个小朋友分配1个饼干
    //用k去划分这个集合

    for (int i = 1; i <= n; i++)     //枚举前i个孩子
        for (int j = 1; j <= m; j++) //枚举饼干的数量
        {
            if (j >= i)                            //只有饼干数量大于等于孩子数量才满足题意要求
                f[i][j] = f[i][j - i];             //状态转移
            for (int k = 1; k <= i && k <= j; k++) //划分集合：枚举这个图的后面的孩子拥有1块饼干的数量
                f[i][j] = min(f[i][j], f[i - k][j - k] + (s[i] - s[i - k]) * (i - k));
        } //含义：ans1求的相对的大小关系,因此同时减去一个数并不影响ans1的结果
    // f[i][j]中的后k个小朋友拥有1块饼干的数量.减去这部分之后,那么现在的目光就要舍去原本的后k个孩子及其他们所拥有的饼干数量
    //因此孩子和饼干数量都-k:本质上是一个贪心的过程

    cout << f[n][m] << endl; // ans1

    //最后求方案数只需倒退一遍,找出每个状态是由哪个状态计算得到的
    int i = n, j = m, h = 0;
    while (i && j)
    {
        if (j >= i && f[i][j] == f[i][j - i])
            j -= i, h++;
        else
        {
            for (int k = 1; k <= i && k <= j; k++)
                if (f[i][j] == f[i - k][j - k] + (s[i] - s[i - k]) * (i - k)) //状态符合
                {
                    for (int u = i; u > i - k; u--)
                        ans[g[u].second] = 1 + h;
                    i -= k, j -= k;
                    break;
                }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
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

/*
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 31, M = 5010;
int f[N][M];
struct child
{
    int d, ip;
} g[N];
int pre[N];
struct state
{
    int nd, t;
} st[N][M];
int ans[N];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> g[i].d, g[i].ip = i; // g[i].d孩子的贪婪程度,g[i].ip当前孩子所处的位置

    //将贪婪程度从大->小进行排序
    sort(g + 1, g + n + 1);
    reverse(g + 1, g + n + 1);
    memset(f, 0x3f, sizeof f);

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + g[i].d; //贪婪程度的前缀和
        f[i][0] = 0;                  //给前i个孩子分配0块饼干的贪婪之和为0
        st[i][0].nd = 0;              //状态
        st[i][0].t = i;               //状态
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (f[i][j - i] < f[i][j]) //求的是最小的->顺带更新
            {
                f[i][j] = f[i][j - i];             //最小
                st[i][j].nd = st[i][j - i].nd + 1; //记录转移(偏移量)
                st[i][j].t = st[i][j - i].t;       //记录转移(记录是由哪一个转移过来的)
            }
            for (int k = 1; k <= i; k++)
            {
                if (f[i - k][j - k] + (i - k) * (pre[i] - pre[i - k]) < f[i][j])
                {
                    f[i][j] = f[i - k][j - k] + (i - k) * (pre[i] - pre[i - k]);
                    st[i][j].nd = 1;
                    st[i][j].t = k;
                }
            }
        }
    }

    cout << f[n][m] << endl;

    int now = n, sum = m;
    while (now)
    {
        int dd = st[now][sum].nd;
        int tt = st[now][sum].t;
        ans[g[now].ip] = dd;
        for (int i = now; i >= now - tt + 1; i--)
            ans[g[i].ip] = dd;
        now -= tt;
        sum -= dd * tt;
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
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
