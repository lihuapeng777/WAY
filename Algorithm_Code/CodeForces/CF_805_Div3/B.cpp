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
    string str;
    cin >> str;

    set<char> s;
    int cnt = 0;

    for (int i = 0; i < (int)str.size(); i++)
    {
        s.insert(str[i]);
        if ((int)s.size() > 3)
        {
            s.clear();
            s.insert(str[i]);
            cnt++;
        }
    }

    cout << cnt + 1 << endl;
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