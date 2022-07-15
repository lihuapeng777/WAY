#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110;
int h[N], e[N], ne[N], idx;
int weight[N], val[N];
int f[N][N];
int n, m, root;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {                   //对当前结点的边进行遍历
        int son = e[i]; // e数组的值是当前边的终点，即儿子结点
        dfs(son);
        for (int j = m - weight[u]; j >= 0; j--)
        {
            //遍历背包的容积，因为我们是要遍历其子节点，所以当前节点我们是默认选择的。
            //这个时候当前结点我们看成是分组背包中的一个组，子节点的每一种选择我们都看作是组内一种物品，所以是从大到小遍历。
            //我们每一次都默认选择当前结点，因为到最后根节点是必选的。
            for (int k = 0; k <= j; k++)
            { //去遍历子节点的组合
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
            }
        }
    }
    //加上刚刚默认选择的父节点价值
    for (int i = m; i >= weight[u]; i--)
    {
        f[u][i] = f[u][i - weight[u]] + val[u];
    }
    //因为我们是从叶子结点开始往上做，所以如果背包容积不如当前物品的体积大，那就不能选择当前结点及其子节点，因此赋值为零
    for (int i = 0; i < weight[u]; i++)
    {
        f[u][i] = 0;
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int root;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> weight[i] >> val[i] >> p;
        if (p == -1)
        {
            root = i;
        }
        else
        {
            add(p, i); //如果不是根节点就加入邻接表,其中p是该节点的父节点，i是当前是第几个节点
        }
    }
    dfs(root);
    cout << f[root][m] << endl;
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
