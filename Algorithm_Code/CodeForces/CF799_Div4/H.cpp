#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200010;

int n, a[N], x[N];
vector<int> v[N];
map<int, int> mp;
int idx;

int get(int x)
{
    if (!mp.count(x))
        mp[x] = ++idx;
    return mp[x];
}

void solve()
{
    mp.clear();
    cin >> n;
    idx = 0;
    for (int i = 1; i <= n; i++)
        cin >> x[i], a[i] = get(x[i]);
    for (int i = 1; i <= idx; i++)
        v[i].clear();
    for (int i = 1; i <= n; i++)
        v[a[i]].push_back(i);
    int res = 0, l = 1, r = 1, num = x[1];
    for (int i = 1; i <= idx; i++)
    {
        int tmp = 1, last = v[i][0];
        for (int j = 1; j < v[i].size(); j++)
        {
            int len = v[i][j] - v[i][j - 1] - 1;
            if (tmp - len < 0)
            {
                tmp = 1;
                last = v[i][j];
            }
            else
                tmp -= len - 1;
            if (tmp > res)
            {
                res = tmp;
                num = x[v[i][j]];
                l = last;
                r = v[i][j];
            }
        }
    }
    cout << num << ' ' << l << ' ' << r << '\n';
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}