#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 55;
int a[N];
int up[N], down[N];
int n, res;

//考虑前y个导弹
//采用了上升系统个数sum_up
//和下降系统个数sum_down
void dfs(int u, int sum_up, int sum_down)
{
    //如果已经超过了最优解答案，那么直接剪枝
    if (sum_up + sum_down >= res)
        return;
    //没有超过最优解答案，且把所有导弹都考虑到了
    //那他就是当前最优解了
    if (u == n)
    {
        res = sum_up + sum_down;
        return;
    }
    //情况一：考虑用上升拦截系统来拦截第u个导弹
    // 上升拦截系统的贪心思路是：
    //     如果当前已有的上升拦截系统的高度都大于第u个导弹高度，则重新开一套系统
    //     否则，则由当前低于第u个导弹最高拦截系统来负责拦截
    int k = 0;
    while (k < sum_up && up[k] >= a[u])
        ++k;
    //找到了有这么个拦截系统
    int t = up[k]; // t用于dfs回溯的时候恢复现场
    up[k] = a[u];
    if (k >= sum_up)
        dfs(u + 1, sum_up + 1, sum_down);
    else
        dfs(u + 1, sum_up, sum_down);
    //恢复现场
    up[k] = t;

    //情况二：考虑用下降拦截系统来拦截第u个导弹
    // 下降拦截系统的贪心思路是：
    //     如果当前已有的下降拦截系统的高度都小于第u个导弹高度，则重新开一套系统
    //     否则，则由当前大于第u个导弹最低拦截系统来负责拦截
    k = 0;
    while (k < sum_down && down[k] <= a[u])
        ++k;
    t = down[k]; // t用于dfs回溯的时候恢复现场
    down[k] = a[u];
    if (k >= sum_down)
        dfs(u + 1, sum_up, sum_down + 1);
    else
        dfs(u + 1, sum_up, sum_down);
    //恢复现场
    down[k] = t;
}

void solve()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        //最差情况是n个导弹分别用n个系统拦截
        //因此可以设置res初始为n来设立哨兵
        res = n;
        dfs(0, 0, 0);
        cout << res << endl;
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
