#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    int cnt = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (a[0] < a[i])
            cnt++;
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