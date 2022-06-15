#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], b[N];
int n, k;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] < 2 * a[i])
            b[i] = 1;
    }
    b[1] = 1;

    //前缀和长度 为k的索引

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + b[i];

    int res = 0;
    for (int i = 1; i + k <= n; i++)
    {
        if (pre[i + k] - pre[i] == k)
            res++;
    }

    cout << res << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}