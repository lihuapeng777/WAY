#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int cnt = 0;
    bool flag = false;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[i - 1] and !flag)
            cnt++, flag = true;
        else
            flag = false;
    }
    cout << cnt << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}