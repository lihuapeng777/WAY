#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 60, M = 32010;
PII master[N];
vector<PII> servent[N];
int f[M];
int n, m;

int solve()
{
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        int weight, val, q;
        cin >> weight >> val >> q; // q:所属主件的编号
        val *= weight;             //实际价格
        if (!q)
            master[i] = {weight, val};
        else
            servent[q].push_back({weight, val});
    }

    for (int i = 1; i <= n; i++) //最外城枚举物品个数
    {
        for (int u = m; u >= 0; u--) //分组背包,枚举容积的形式
        {
            for (int j = 0; j < 1 << servent[i].size(); j++) //枚举四种组合(二进制简化代码)
            {
                int weight = master[i].first, val = master[i].second;
                for (int k = 0; k < servent[i].size(); k++)
                {
                    if (j >> k & 1) //表示选择该物品
                    {
                        weight += servent[i][k].first;
                        val += servent[i][k].second;
                    }
                }
                if (u >= weight)
                    f[u] = max(f[u], f[u - weight] + val);
            }
        }
    }
    cout << f[m] << endl;
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
