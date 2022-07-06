/*
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 50010;
int f[N];
PII p[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;

    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (p[j].y < p[i].y)
                f[i] = max(f[i], f[j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res << endl;
}

signed main()
{
    io;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define f first
#define s second

using namespace std;

typedef pair<int, int> PII;
const int N = 5050;

PII a[N];
// int q[N];
int q[N];
int n;

int main()
{
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);

    int len = 0;
    q[0] = -1;
    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (q[mid] < a[i].second)
                l = mid;
            else
                r = mid - 1;
        }

        len = max(len, r + 1);
        q[r + 1] = a[i].second;
    }

    cout << len;

    return 0;
}
