#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 4;
int a[N];
bool st[N];

void solve()
{
    memset(st, 0, sizeof st);
    int n;
    cin >> n;

    for (int i = 1; i <= 3; i++)
        cin >> a[i];

    int sum = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (st[n])
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            sum += n;
            st[n] = true;
            n = a[n];
        }
    }
    if (sum < 6)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

signed main()
{
    io;
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}