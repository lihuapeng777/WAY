#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110;
int a[N];

void solve()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 'a' - 'A';
        }
    }
    if (str == "yes")
        puts("YES");
    else
        puts("NO");
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