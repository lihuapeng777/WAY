#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<int> cnt(27, 0);
    for (int i = 0; i < str.size(); i++)
    {
        // cout << str[i] - 'A' + 1 <<endl;
        cnt[str[i] - 'A' + 1]++;
    }

    int res = 0;
    for (int i = 1; i <= 26; i++)
    {
        if (cnt[i] >= 1)
            res += cnt[i] + 1;
    }

    cout << res << endl;
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