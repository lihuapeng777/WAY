#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (a == vector(n, 0))
    {
        cout << "0\n";
        return;
    }

    int l = 0, r = n - 1;
    while (a[l] == 0)
        l++;
    while (a[r] == 0)
        r--;

    if (count(a.begin() + l, a.begin() + r + 1, 0) == 0)
        cout << "1\n";
    else
        cout << "2\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
