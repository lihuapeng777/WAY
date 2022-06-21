#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
char s[N];

vector<int> sub(vector<int> &a, vector<int> &b)
{
    vector<int> c;
    for (int i = 0, t = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if (i < b.size())
            t -= b[i];
        c.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

void solve()
{
    int n;
    cin >> n;
    cin >> s + 1;

    if (s[1] != '9')
    {
        for (int i = 1; i <= n; i++)
        {
            cout << 9 - (s[i] - '0');
        }
        cout << '\n';
    }
    else
    {
        vector<int> a, b;
        for (int i = 1; i <= n + 1; i++)
            a.push_back(1);
        for (int i = n; i; i--)
            b.push_back(s[i] - '0');
        auto c = sub(a, b);
        for (int i = c.size() - 1; i >= 0; i--)
            cout << c[i];
        cout << '\n';
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}