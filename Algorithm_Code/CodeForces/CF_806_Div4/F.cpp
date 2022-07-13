#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int a[N];
int b[N];
int tr[N];
int n;

int lowbit(int x)
{
    return x & -x;
}

void add(int x)
{
    for (int i = x; i <= N; i += lowbit(i))
        tr[i]++; //注意是+的是数字的个数数量
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void solve()
{
    cin >> n;

    memset(tr, 0, sizeof tr);
    memset(b, 0, sizeof b);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < i)
        {
            b[++cnt] = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (a[b[i]] != 0)
            ans += query(a[b[i]] - 1);
        add(b[i]);
    }
    cout << ans << endl;
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

/*
#include <bits/stdc++.h>
using namespace std;
// https://www.zhihu.com/search?type=content&q=codeforces806
#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 4e5 + 10;
int a[N];
int n;
vector<int> nums;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    nums.clear();
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] < i)
        {
            auto t = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
            ans += t;
            nums.push_back(i);
        }
    }
    cout << ans << endl;
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