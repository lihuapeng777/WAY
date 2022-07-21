/*
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 360, M = 130;
int p[N]; //格子上的分数
int w[N]; //卡牌的能走的步数
int f[M][N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= m; i++)
        cin >> w[i];

    f[0][1] = p[1]; //选择了0张卡牌,此时位于点1的最大分数

    for (int i = 1; i <= m; i++)         //枚举使用的卡牌数量
        for (int j = 1; j <= n; j++)     //枚举可能到达的格子点
            for (int k = 1; k <= m; k++) //线性dp划分区间的核心
            {
                // if(j-w[k]>=1)
                f[i][j] = max(f[i][j], f[i - 1][j - w[k]] + p[j]);
            }

    cout << f[m][n] << endl; //使用了m张卡牌,最后到达第n个格子点的最大值
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
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 360, M = 41;

int n, m;
int score[N];
int f[M][M][M][M];

int main()
{
    int b[5] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &score[i]);

    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        b[t]++;
    }

    for (int A = 0; A <= b[1]; A++)
        for (int B = 0; B <= b[2]; B++)
            for (int C = 0; C <= b[3]; C++)
                for (int D = 0; D <= b[4]; D++)
                {
                    int t = score[A + B * 2 + C * 3 + D * 4];
                    int &v = f[A][B][C][D];
                    v = t;
                    if (A)
                        v = max(v, f[A - 1][B][C][D] + t);
                    if (B)
                        v = max(v, f[A][B - 1][C][D] + t);
                    if (C)
                        v = max(v, f[A][B][C - 1][D] + t);
                    if (D)
                        v = max(v, f[A][B][C][D - 1] + t);
                }

    printf("%d\n", f[b[1]][b[2]][b[3]][b[4]]);
    return 0;
}