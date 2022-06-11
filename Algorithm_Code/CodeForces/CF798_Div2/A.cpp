#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    string c = "";
    int i = 0, j = 0;
    int cnt1 = 0, cnt2 = 0;

    while (i < n and j < m) //有一个为空就出去
    {
        if ((a[i] < b[j] && cnt1 < k) || (cnt2 == k)) //普通情况 + 另一个cnt已经满了的情况
        {
            c += a[i];
            i++;
            cnt1++;
            cnt2 = 0;
        }
        else
        {
            c += b[j];
            j++;
            cnt2++;
            cnt1 = 0;
        }
    }
    cout << c << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}