#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (str[i - 1] == 'B')
            v[i] = 1;
        else if (str[i - 1] == 'W')
            v[i] = 0;
    }

    vector<int> pre(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
        // cout<<i<<" "<<pre[i]<<endl;
    }

    int cnt = 0;
    int maxv = 0;
    for (int i = 0; i + k <= n; i++)
    {
        cnt = pre[i + k] - pre[i];
        maxv = max(cnt, maxv);
        if (n == k)
            maxv = pre[n];
    }
    // cout<<maxv<<endl;
    if (maxv > k)
        puts("0");
    else
        printf("%d\n", k - maxv);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}