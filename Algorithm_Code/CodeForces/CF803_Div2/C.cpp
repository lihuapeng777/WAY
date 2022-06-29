#include <bits/stdc++.h>
using namespace std;

#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
// const int N = 2e5 + 10;
// int a[N];
int n;

void solve()
{
    cin >> n;
    vector<int> pos, neg, a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            pos.push_back(x);
        }
        else if (x < 0)
        {
            neg.push_back(x);
        }
        else
        {
            if (a.size() < 2)
            {
                a.push_back(x);
            }
        }
    }
    if (pos.size() > 2 || neg.size() > 2)
    {
        cout << "NO\n";
        return;
    }

    for (int i : pos)
    {
        a.push_back(i);
    }
    for (int i : neg)
    {
        a.push_back(i);
    }

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            for (int k = j + 1; k < a.size(); k++)
            {
                bool ok = false;
                for (int l = 0; l < a.size(); l++)
                {
                    if (a[i] + a[j] + a[k] == a[l])
                    {
                        ok = true;
                    }
                }
                if (!ok)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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
