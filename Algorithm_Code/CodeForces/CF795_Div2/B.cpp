#include <iostream>
#include <map>
#include <string>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]]++;

    for (auto [_, cnt] : mp)
        if (cnt == 1)
        {
            cout << -1 << '\n';
            return;
        }

    int l = 1;
    for (auto [_, cnt] : mp) //将数组元素顺时针旋转
    {
        int r = l + cnt - 1;
        for (int i = l + 1; i <= r; i++)
            cout << i << " ";
        cout << l << " ";
        l += cnt;
    }
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}