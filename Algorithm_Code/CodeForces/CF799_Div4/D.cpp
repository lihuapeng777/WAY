#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int h, m, k;
set<string> S;

bool check(string s)
{
    if (s[0] == s[4] and s[1] == s[3])
        return true;
    return false;
}

void solve()
{
    scanf("%d:%d", &h, &m);
    cin >> k;
    S.clear();
    int res = 0;

    while (1)
    {
        string s = "";
        if (h < 10)
            s += "0";
        s += to_string(h);
        s += ":";
        if (m < 10)
            s += "0";
        s += to_string(m);

        if (S.count(s))
            break;
        S.insert(s);

        if (check(s))
            res++;
        h += k / 60;
        m += k % 60;

        if (m >= 60)
            m -= 60, h++;
        if (h >= 24)
            h -= 24;
    }

    cout << res << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}