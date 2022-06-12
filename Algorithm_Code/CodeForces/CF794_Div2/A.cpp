#include <bits/stdc++.h>
using namespace std;

const int N = 60;
double a[N];

void solve()
{
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    double ave = 1.0 * sum / n;

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ave)
            flag = true;
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}