#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int q[N];
int n, m;

void solve()
{
    //查询一个数是否在它的右边
    cin >> n >> m;

    map<int, int> mp1; //记录从左到右的:保留偏右的坐标
    map<int, int> mp2; //记录从右到左的:保留偏左的坐标
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        mp1[q[i]] = i;
    }

    for (int i = n; i >= 1; i--)
        mp2[q[i]] = i;

    while (m--)
    {
        int left, right;
        cin >> left >> right;
        if (!mp1[left] || !mp1[right])
            puts("NO");
        else if ((mp1[left] < mp1[right]) || (mp2[left] < mp2[right]) || (mp2[left] < mp1[right]))
            puts("YES");
        else
            puts("NO");
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