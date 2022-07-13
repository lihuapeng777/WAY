#include <bits/stdc++.h>
using namespace std;
// https://www.zhihu.com/search?type=content&q=codeforces806
#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 110;
int g[N][N];
bool ins[N][N];
string s;
int n;
int x, y, xx, yy, ans, t;

void solve()
{
    cin >> n;
    ans = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j <= n; j++)
        {
            g[i][j + 1] = (s[j] == '1'), ins[i][j + 1] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //奇数时,中心不用管
            if (n & 1 and i == (n + 1) / 2 and j == (n + 1) / 2)
                continue;
            if (!ins[i][j])
            {
                t = 0;
                x = i, y = j;
                while (!ins[x][y])
                {
                    ins[x][y] = 1, t += g[x][y];
                    xx = y, yy = n + 1 - x; //变为旋转90*的下一个点
                    x = xx, y = yy;
                }
                ans += min(t, 4 - t);
            }
        }
    }
    cout << ans << endl;
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