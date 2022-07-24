#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010, M = N * 2, INF = 0x3f3f3f3f;

int n;
int h[N], e[M], w[M], ne[M], idx;
int d1[N], d2[N], p1[N], up[N];
bool is_leaf[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_d(int u, int father) //这里是向下递归的过程，目的是得到每个点的向下路径的最大长度和次大长度
{
    d1[u] = d2[u] = -INF;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father)
            continue;
        int d = dfs_d(j, u) + w[i];
        if (d >= d1[u])
        {
            d2[u] = d1[u], d1[u] = d;
            p1[u] = j; //表示当前被更新的u这个父节点的下一点为j
        }
        else if (d > d2[u])
            d2[u] = d;
    }
    if (d1[u] == -INF) //如果没有被更新说明是叶节点，那么最大值和次大值都是0，而且标记为叶节点
    {
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }
    return d1[u]; //每次返回这个最大值
}

void dfs_u(int u, int father) //第一步向上递归，第二步向下或继续向上递归的过程
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father)
            continue; //这里不要理解为父节点，其实这句话的根本目的是为了判重，防止回到上一次的
        //搜索的节点（如果理解为父节点可能比较难解释向上搜索）
        if (p1[u] == j)
            up[j] = max(up[u], d2[u]) + w[i];
        // p1[u]==j说明遇到了之前向下递归的那条路径，为了避免路径的重复，
        //那么便只能用次大值来更新这条路径的长度
        // up[j] = max(up[u], d2[u]) + w[i];这句话是说从j这一节点的向上路径的长度等于它的父节点u继续
        //向上到其他点的路径或从父节点向下的路径的长度加上u与j直接的距离
        else
            up[j] = max(up[u], d1[u]) + w[i];
        dfs_u(j, u);
    }
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs_d(1, -1);
    dfs_u(1, -1);
    int res = d1[1];
    for (int i = 2; i <= n; i++)
        if (is_leaf[i])
            res = min(res, up[i]);
        else
            res = min(res, max(d1[i], up[i]));
    printf("%d\n", res);
    return 0;
}
