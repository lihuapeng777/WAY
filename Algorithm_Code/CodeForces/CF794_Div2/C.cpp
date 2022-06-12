#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int ans[N];
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    if (n & 1)
    {
        cout << "NO" << endl;
        return;
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1, j = 1; i <= n; i += 2, j++)
        ans[i] = a[j]; //山谷
    for (int i = 2, j = n / 2 + 1; i <= n; i += 2, j++)
        ans[i] = a[j];
    bool flag = true;

    for (int i = 2; i <= n - 1; i++)
    {
        if (ans[i] > ans[i - 1] && ans[i] > ans[i + 1])
            continue;
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
            continue;
        flag = false;
        break;
    }

    if (!(ans[1] > ans[n] && ans[1] > ans[2]) && !(ans[1] < ans[n] && ans[1] < ans[2]))
        flag = false;
    if (!(ans[n] > ans[n - 1] && ans[n] > ans[1]) && !(ans[n] < ans[n - 1] && ans[n] < ans[1]))
        flag = false;

    if (flag)
    {
        puts("YES");
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else
        cout << "NO" << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}