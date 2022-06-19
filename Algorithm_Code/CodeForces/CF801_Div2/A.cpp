#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 50;
int a[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;

    int maxv = -1e9 - 10;
    int maxi = 0;
    int maxj = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > maxv)
            {
                maxv = a[i][j];
                maxi = i;
                maxj = j;
            }
        }
    }

    // cout<<maxi<<" "<<maxj<<endl;

    int x1 = abs(n - maxi + 1);
    int x2 = abs(maxi);
    int ansx = max(x1, x2);

    int y1 = abs(m - maxj + 1);
    int y2 = abs(maxj);
    int ansy = max(y1, y2);

    cout << ansx * ansy << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}