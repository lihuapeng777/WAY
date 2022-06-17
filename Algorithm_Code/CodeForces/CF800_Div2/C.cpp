#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }

    int ansi = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] != 0)
        {
            ansi = i;
            break;
        }
    }
    // cout<<ansi<<endl;

    bool flag = true;
    int sum = 0;
    for (int i = 1; i <= ansi - 1; i++)
    {
        sum += a[i];
        // cout<<sum<<endl;
        if (sum <= 0)
            flag = false;
    }

    sum += a[ansi];
    // cout<<sum<<endl;
    if (flag and sum == 0)
        puts("YES");
    else
        puts("NO");
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}