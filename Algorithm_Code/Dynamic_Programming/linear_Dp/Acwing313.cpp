#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
//#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110;
int f[N][N], w[N][N], p[N][N];
int n, m;

void print(int i, int j)
{
    if (i == 0)
        return;
    print(i - 1, p[i][j]);
    cout << j << " ";
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= m; i++)
        f[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= m; j++)
        {
            int maxv = 1;
            for (int k = 1; k < j; k++)
                if (f[i - 1][k] > f[i - 1][maxv])
                    maxv = k;
            f[i][j] = f[i - 1][maxv] + w[i][j];
            p[i][j] = maxv;
        }
    }
    int res = n;
    for (int i = n; i <= m; i++)
        if (f[n][i] > f[n][res])
            res = i;
    cout << f[n][res] << endl;
    print(n, res);
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

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110;
int w[N][N];
int f[N][N];//前i朵花，放在了前j个花瓶里的最大值
int p[N][N];
int n,m;
void print(int i,int j)
{
    if(i==0||j==0)return ;
    while(f[i][j]==f[i][j-1])j--;
    print(i-1,j-1);
    cout<<j<<" ";
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>w[i][j];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=m;j++)
            if(j==i)f[i][j]=f[i-1][j-1]+w[i][j];
            else f[i][j]=max(f[i][j-1],f[i-1][j-1]+w[i][j]);
    cout<<f[n][m]<<endl;
    print(n,m);
}

作者：WAWA鱼
链接：https://www.acwing.com/solution/content/75515/
来源：AcWing
