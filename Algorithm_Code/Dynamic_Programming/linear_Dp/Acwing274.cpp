#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 210, M = 1010, INF = 0x3f3f3f3f;
int w[N][N];
int f[M][N][N];
int p[M];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> w[i][j]; // i->j的权值
    for (int i = 1; i <= m; i++)
        cin >> p[i]; //请求列表

    p[0] = 3; //任意初始化为1，2，3均可
    memset(f, 0x3f, sizeof f);
    f[0][1][2] = 0; //初始状态

    for (int i = 0; i < m; i++)          //请求数量
        for (int x = 1; x <= n; x++)     //枚举x的位置
            for (int y = 1; y <= n; y++) //枚举y的位置
            {
                int z = p[i], v = f[i][x][y];   // z:当前的地方,v:当前的路线花费之和最小值
                if (x == y || x == z || y == z) //保证同样位置不出现两个员工
                    continue;
                int u = p[i + 1];                                  //需要去的下一个位置
                f[i + 1][x][y] = min(f[i + 1][x][y], v + w[z][u]); //派z出发
                f[i + 1][z][y] = min(f[i + 1][z][y], v + w[x][u]); //派x出发
                f[i + 1][x][z] = min(f[i + 1][x][z], v + w[y][u]); //派y出发
            }

    int res = INF;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
        {
            int z = p[m];
            if (x == y || x == z || y == z)
                continue;
            res = min(res, f[m][x][y]); //已经完成了所有的m个请求,枚举x,y的所有位置,并寻找最小值
        }
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
