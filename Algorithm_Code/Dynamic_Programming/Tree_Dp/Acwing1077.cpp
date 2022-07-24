#include <iostream>
#include <cstring>
using namespace std;

/*
以下注释为早期笔记，希望对你有所帮助

状态机 + 树形Dp问题
状态表示:
    f(i, 0)：第i号结点被他的父结点安排的守卫看住的方案数
    f(i, 1)：第i号结点被他的子结点安排的守卫看住的方案数
    f(i, 2)：第i号结点自己安排守卫看住的方案数
状态计算:(j是i的子结点)
    f(i, 0) = sum{min(f(j,1), f(j,2))}
        i是被他父结点看住的，那他的子结点要么自己看自己，要么被自己的子结点看住
    f(i, 1) = min{w(k) + f(k, 2) - sum{min(f(j,1), f(j,2))}}
        i如果是被子结点看住的，那么就要枚举他是被哪个子结点看住的所有方案，对所有方案求最小值
        这里的sum不包括j==k的情况，因此需要手动额外减去
    f(i, 2) = sum{min(f(j,0), f(j,1), f(j,2))} + w(u)
        i是被自己看住的，那他的子结点可以被父结点看住，可以自己看自己，也可以被自己的子结点看住
*/
const int N = 1510;
int n;
int h[N], w[N], e[N], ne[N], idx;
int f[N][3];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
    f[u][0] = 0;
    f[u][1] = 1e9;  // f[u][1]求最小值，初始化为最大值
    f[u][2] = w[u]; //初始化放置自己的代价
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += min(f[j][1], f[j][2]);
        f[u][2] += min(min(f[j][0], f[j][1]), f[j][2]);
    }
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        // f[u][0]中记录了sum{min(f(j,1), f(j,2))}，再从中减去对应的贡献即可得到remain ver
        f[u][1] = min(f[u][1], f[u][0] + f[j][2] - min(f[j][1], f[j][2]));
    }
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int id, cnt, cost;
        cin >> id >> cost >> cnt;
        w[id] = cost;
        while (cnt--)
        {
            int ver;
            cin >> ver;
            add(id, ver);
            st[ver] = true;
        }
    }
    int root = 1;
    while (st[root])
        ++root;
    dfs(root);
    printf("%d\n", min(f[root][1], f[root][2]));
    return 0;
}