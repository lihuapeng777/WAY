#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int a[N];
int s[N];
int mi[40] = {1};

void solve()
{
    for (int i = 1; i <= 33; i++)
        mi[i] = mi[i - 1] * 2ll;
    int n, k;
    cin >> n >> k;

    int ANS = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    int ans = 0;
    for (int x = 0; x <= n; x++)
    {
        ans = s[x] - k * 1ll * x; //计算1~x的好钥匙
        for (int i = x + 1; i <= min(x + 32, n); i++)
            ans += a[i] / mi[i - x];
        ANS = max(ANS, ans);
    }
    cout << ANS << endl;
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