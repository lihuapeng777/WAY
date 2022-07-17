#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 3e6 + 10;
int a[N]; //输入的数组
int f[N]; //存储答案的数组
int n;
stack<int> s;
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() and a[s.top()] <= a[i])
            s.pop();
        f[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
        cout << f[i] << ' ';
    cout << endl;
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