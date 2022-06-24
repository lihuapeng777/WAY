#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int a[N], b[N], g[N], k[N], s[N];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> g[i] >> k[i], s[i] = i;

    int x, y;
    cin >> x >> y;
    int ok = 1;
    for (int i = n; i >= 1; i--)
    {
        if (x >= a[i] and x <= a[i] + g[i] and y >= b[i] and y <= b[i] + k[i])
        {
            ok = 0, cout << s[i];
            break;
        }
    }

    if (ok)
        puts("-1");

    return 0;
}