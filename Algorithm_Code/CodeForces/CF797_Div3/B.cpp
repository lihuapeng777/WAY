#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int a[N], b[N];

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int maxv = 0;
    for (int i = 0; i < n; i++)
        maxv = max(maxv, a[i] - b[i]);

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != max(a[i] - maxv, 0))
            flag = false;
    }

    if (flag)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}