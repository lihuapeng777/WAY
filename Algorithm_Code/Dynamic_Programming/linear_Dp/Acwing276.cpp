#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 16;
int w[N][N];
int f[N][N * N][N][N][2][2];
int n, m, k;

struct State
{
    int i, j, l, r, x, y;
} g[N][N * N][N][N][2][2];

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    memset(f, -0x3f, sizeof f);

    for (int i = 1; i <= n; i++)             //枚举行数
        for (int j = 0; j <= k; j++)         //前i行,一共选择了j个格子
            for (int l = 1; l <= m; l++)     //枚举左端点
                for (int r = l; r <= m; r++) //枚举右端点：(一定是右端点大于等于左端点)
                {
                    if (j < r - l + 1) //选择的格子数量小于 该行的左右端点之间的格子数时：该方案不成立
                        continue;

                    // 左扩张，右扩张
                    {
                        auto &vf = f[i][j][l][r][1][0];
                        auto &vg = g[i][j][l][r][1][0];
                        if (j == r - l + 1) //一行恰好相等
                            vf = 0;
                        for (int p = l; p <= r; p++)     //枚举下一个左端点
                            for (int q = p; q <= r; q++) //枚举下一个右端点
                            {
                                int val = f[i - 1][j - (r - l + 1)][p][q][1][0]; //前i-1行的状态
                                if (vf < val)                                    //如果前i-1行的状态>当前i行的状态
                                {
                                    vf = val;                                  //直接赋值
                                    vg = {i - 1, j - (r - l + 1), p, q, 1, 0}; //
                                }
                            }
                        for (int u = l; u <= r; u++) //从左端点+右端点，相当于线性dp的加上权值
                            vf += w[i][u];
                    }

                    // 左扩张，右收缩
                    {
                        auto &vf = f[i][j][l][r][1][1];
                        auto &vg = g[i][j][l][r][1][1];
                        for (int p = l; p <= r; p++)
                            for (int q = r; q <= m; q++)
                                for (int y = 0; y <= 1; y++)
                                {
                                    int val = f[i - 1][j - (r - l + 1)][p][q][1][y];
                                    if (vf < val)
                                    {
                                        vf = val;
                                        vg = {i - 1, j - (r - l + 1), p, q, 1, y};
                                    }
                                }
                        for (int u = l; u <= r; u++)
                            vf += w[i][u];
                    }

                    // 左收缩，右扩张
                    {
                        auto &vf = f[i][j][l][r][0][0];
                        auto &vg = g[i][j][l][r][0][0];
                        for (int p = 1; p <= l; p++)
                            for (int q = l; q <= r; q++)
                                for (int x = 0; x <= 1; x++)
                                {
                                    int val = f[i - 1][j - (r - l + 1)][p][q][x][0];
                                    if (vf < val)
                                    {
                                        vf = val;
                                        vg = {i - 1, j - (r - l + 1), p, q, x, 0};
                                    }
                                }
                        for (int u = l; u <= r; u++)
                            vf += w[i][u];
                    }

                    // 左收缩，右收缩
                    {
                        auto &vf = f[i][j][l][r][0][1];
                        auto &vg = g[i][j][l][r][0][1];
                        for (int p = 1; p <= l; p++)
                            for (int q = r; q <= m; q++)
                                for (int x = 0; x <= 1; x++)
                                    for (int y = 0; y <= 1; y++)
                                    {
                                        int val = f[i - 1][j - (r - l + 1)][p][q][x][y];
                                        if (vf < val)
                                        {
                                            vf = val;
                                            vg = {i - 1, j - (r - l + 1), p, q, x, y};
                                        }
                                    }
                        for (int u = l; u <= r; u++)
                            vf += w[i][u];
                    }
                }

    int res = 0;
    State state;

    for (int i = 1; i <= n; i++)
        for (int l = 1; l <= m; l++)
            for (int r = 1; r <= m; r++)
                for (int x = 0; x <= 1; x++)
                    for (int y = 0; y <= 1; y++)
                    {
                        int val = f[i][k][l][r][x][y];
                        if (res < val) //寻找最大值
                        {
                            res = val;
                            state = {i, k, l, r, x, y}; //最大值对应的状态
                        }
                    }

    printf("Oil : %d\n", res);

    while (state.j)
    {
        for (int i = state.l; i <= state.r; i++)
            printf("%d %d\n", state.i, i);
        state = g[state.i][state.j][state.l][state.r][state.x][state.y]; //状态转移
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
