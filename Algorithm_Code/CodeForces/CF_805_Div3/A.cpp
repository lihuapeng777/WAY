#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

int get(int num)
{
    int cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return cnt;
}

void solve()
{
    int num;
    cin >> num;

    int cnt = get(num);
    int minv = 1;
    for (int i = 1; i < cnt; i++)
        minv *= 10;

    cout << num - minv << endl;
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