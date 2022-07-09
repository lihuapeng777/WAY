#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

int a[3][3];

void solve()
{
    int cnt = 0;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                cnt++;
        }
    }
    if (cnt == 0)
        puts("0");
    else if (cnt <= 3)
        puts("1");
    else if (cnt == 4)
        puts("2");
}

signed main()
{
    io;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
