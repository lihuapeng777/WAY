#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10;
string s[N];

void solve()
{
    int n;
    cin >> n;
    map<string, bool> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        mp[s[i]] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        bool ok = false;
        for (int j = 1; j < s[i].size(); j++)
        {
            string pref = s[i].substr(0, j);
            string suff = s[i].substr(j, s[i].size() - j);
            if (mp.count(pref) and mp.count(suff))
            {
                ok = true;
                break;
            }
        }
        if (ok)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
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