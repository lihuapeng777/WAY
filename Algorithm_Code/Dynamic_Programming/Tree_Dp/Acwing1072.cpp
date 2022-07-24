/*
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 10010, M = N << 1;
int h[N], w[2 * N], ne[2 * N], e[2 * N], idx;
int ans;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

//该图为无向图:并且迭代过程中不能回到父亲节点:因此要特判
int dfs(int u, int father)
{
    int dist = 0;
    int d1 = 0, d2 = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father)
            continue;
        int d = dfs(j, u) + w[i]; //求出路径的长度
        dist = max(dist, d);      //求f[x]的最大值
        // d1,d2求出以该点为顶点的最长路径
        if (d >= d1)
            d2 = d1, d1 = d;
        else if (d > d2)
            d2 = d;
    }
    ans = max(ans, d1 + d2);
    return dist;
}

void solve()
{
    memset(h, -1, sizeof h);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    dfs(1, -1);
    cout << ans << endl;
}

signed main()
{
    io;
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, M = N << 1; //初始不确定树的拓扑结构，因此要建立双向边

int n;
int h[N], e[M], w[M], ne[M], idx;
int f1[N], f2[N], res;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int father)
{
    f1[u] = f2[u] = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father)
            continue;
        dfs(j, u);
        if (f1[j] + w[i] >= f1[u])
            f2[u] = f1[u], f1[u] = f1[j] + w[i]; //最长路转移
        else if (f1[j] + w[i] > f2[u])
            f2[u] = f1[j] + w[i]; //次长路转移
    }
    res = max(res, f1[u] + f2[u]);
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1); //我们可以任意选取一个点作为根节点，这样整棵树的拓扑结构被唯一确定下来了
    printf("%d\n", res);
    return 0;
}