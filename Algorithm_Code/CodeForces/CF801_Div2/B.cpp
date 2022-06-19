#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 60;
int a[N];

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n % 2 == 1)
    {
        puts("Mike");
        return;
    }

    int minv = 1e9 + 10;
    int mini = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < minv)
        {
            minv = a[i];
            mini = i;
        }
    }
    if (mini % 2 == 1)
        puts("Joe");
    else
        puts("Mike");
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}