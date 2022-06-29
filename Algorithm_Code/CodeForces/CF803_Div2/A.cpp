#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 110;
int a[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << a[1] << endl;
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
