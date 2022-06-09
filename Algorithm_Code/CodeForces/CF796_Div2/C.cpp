// https://zhuanlan.zhihu.com/p/524057359
#include <iostream>
#include <map>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<char, int> mp;

    for (int i = 1; i <= 2 * n + 1; i++)
    {
        string s;
        cin >> s;
        for (auto it : s)
            mp[it]++;
    }

    for (auto [c, cnt] : mp)
    {
        if (cnt % 2 == 1)
        {
            cout << c << "\n";
            return;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}