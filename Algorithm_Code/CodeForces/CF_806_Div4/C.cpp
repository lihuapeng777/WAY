#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110;
int q[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> q[i];

    for (int i = 1; i <= n; i++)
    {
        int cnt;
        string str;
        cin >> cnt >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'D')
            {
                q[i] += 1;
                if (q[i] == 10)
                    q[i] = 0;
            }
            else
            {
                q[i] -= 1;
                if (q[i] == -1)
                    q[i] = 9;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << q[i] << ' ';
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