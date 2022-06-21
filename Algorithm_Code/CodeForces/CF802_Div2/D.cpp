#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5, INF = 0x3f3f3f3f;
int a[maxn], ans[maxn];
LL s[maxn];
// https://zhuanlan.zhihu.com/p/530963040
int main()
{

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    LL maxv = 0;
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
        maxv = max(maxv, (s[i] + i - 1) / i);
    }
    cin >> m;
    while (m--)
    {
        int x;
        cin >> x;
        if (x < maxv)
        {
            cout << -1 << '\n';
            continue;
        }
        else
        {
            int l = 1, r = n;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (1LL * x * mid >= s[n])
                    r = mid;
                else
                    l = mid + 1;
            }
            cout << r << '\n';
        }
    }
}