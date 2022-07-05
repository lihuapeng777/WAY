#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
// const int N = 2e5 + 10;
// int a[N];

void solve()
{
    int n;
    cin >> n;
    if (n & 1)
        cout << "-1" << endl;
    else
    {
        cout << n / 2 << " 0"
             << " 0" << endl;
    }
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
