#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> v;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1') //遍历01串,将1的位置尾插入 vector中
            v.push_back(i);
    }
    //步长允许
    if (v.size() and k >= n - v.back() - 1) //优先将一个1放到末尾
    {
        swap(s[v.back()], s[n - 1]);
        k -= n - v.back() - 1;
        v.pop_back(); //删除 原串中最末尾的'1'
    }

    if (v.size() and k >= *v.begin()) //如果有剩余步数,将一个1移至开头
        swap(s[0], s[*v.begin()]);

    int ans = 0;
    for (int i = 1; i < s.length(); i++)
        ans += 10 * (s[i - 1] - '0') + s[i] - '0';
    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}