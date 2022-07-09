#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int a[N], cnt[N];
int n, m;

bool check(int mid)
{
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] >= mid)
            tot += mid;
        else
            tot += cnt[i] + (mid - cnt[i]) / 2;
        if (tot >= m)
            return true;
    }
    return false;
}

void solve()
{
    memset(a, 0, sizeof a);
    memset(cnt, 0, sizeof cnt);
    cin >> n >> m;
    set<int> s;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
    }

    if (s.size() == m)
        cout << 1 << endl;
    else
    {
        int left = 2, right = 1e9;
        while (left < right)
        {
            int mid = left + right >> 1;
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        cout << left << endl;
    }
}

signed main()
{
    io;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

//二分时间
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int a[N], cnt[N];
int n, m;

bool check(int mid)
{
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] >= mid)
            tot += mid;
        else
            tot += cnt[i] + (mid - cnt[i]) / 2;
        if (tot >= m)
            return true;
    }
    return false;
}

void solve()
{
    memset(a, 0, sizeof a);
    memset(cnt, 0, sizeof cnt);
    cin >> n >> m;
    set<int> s;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
    }

    if (s.size() == m)
        cout << 1 << endl;
    else
    {
        int left = 2, right = 1e9;
        while (left < right)
        {
            int mid = left + right >> 1;
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        cout << left << endl;
    }
}

signed main()
{
    io;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
