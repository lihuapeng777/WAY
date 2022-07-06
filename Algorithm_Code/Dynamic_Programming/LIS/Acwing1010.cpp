#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1010;
int q[N];
int f[N], g[N];
int n;

void solve()
{
    while (cin >> q[n])
        n++;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (q[j] >= q[i])
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;

    int cnt = 0; //此时拥有下降子序列的个数
    for (int i = 0; i < n; i++)
    {
        int k = 0; //枚举的序列的个数
        while (k < cnt and g[k] < q[i])
            k++;      //满足条件为：子序列的最后一个要大于q[i]:即当前数
        g[k] = q[i];  //将q[i]作为子序列的数字尾端
        if (k >= cnt) //如果枚举完了所有子序列都没有找到合适的，那么就自己开一个子序列
            cnt++;
    }
    cout << cnt << endl;
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
