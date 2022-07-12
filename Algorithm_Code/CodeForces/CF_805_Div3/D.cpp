#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int is[N];

void solve()
{
    string s;
    int p;
    cin >> s >> p;
    vector<pair<char, int>> a;

    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a.push_back({s[i], i});
        sum += s[i] - 'a' + 1;
        is[i] = 0;
    }

    if (sum <= p)
    {
        cout << s << endl;
        return;
    }
    else
    {
        sort(a.begin(), a.end());
        int num = 0; //删除字符的个数
        for (int i = s.size() - 1; i >= 0; i--)
        {
            sum -= (a[i].first - 'a' + 1);
            num++;
            is[a[i].second] = 1;
            if (sum <= p)
                break;
        }
        if (num == s.size())
            cout << endl;
        else
        {
            for (int i = 0; i < s.size(); i++)
                if (!is[i]) //没有被标记的就是保留的
                    cout << s[i];
            cout << endl;
        }
    }
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