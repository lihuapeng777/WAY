/*
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 5e5 + 10;
bool v[N];
int L[N], R[N], id[N], a[N];
int ans[N], p[N];
int n;

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        id[i] = i;
        int x;
        cin >> x;
        a[i] = x;
        if (x == i) //二分找出a[i]的取值范围为L[x]~~~R[x]
            L[i] = R[i] = 1;
        else
        {
            // lower_bound
            int left = 1, right = n;
            while (left < right)
            {
                int mid = left + right >> 1;
                if (i / mid <= x)
                    right = mid;
                else
                    left = mid + 1;
            }
            L[i] = right;

            // upper_bound
            left = 1, right = n;
            while (left < right)
            {
                int mid = left + right + 1 >> 1;
                if (i / mid < x)
                    right = mid - 1;
                else
                    left = mid;
            }
            R[i] = right;
        }
    }
    //问题转化->已知每个点的取值范围,要求构造一个排列
    //我们把位置按照right排序,然后每个位置能取的最小值即可
    //题目里保证了一定有解,取最小值的操作用set或者并查集均可
    //按照右端点为第一关键字,升序排序
    sort(id + 1, id + n + 1, [&](int a, int b)
         {
            if (R[a] != R[b]) return R[a] < R[b];
            return L[a] < L[b]; });

    for (int i = 1; i <= n; i++) //并查集的初始化
        p[i] = i;

    for (int i = 1; i <= n; i++) // id->的左端点的父亲
    {
        int t = find(L[id[i]]);
        ans[id[i]] = t;
        p[t] = t + 1;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
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
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
typedef pair<int, int> PII;

const int N = 5e5 + 10;
vector<PII> g[N];
priority_queue<PII, vector<PII>, greater<PII>> que;
int a[N], b[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++) //找出每个点的 左端点和右端点
    {
        int L = i / (b[i] + 1) + 1;
        int R = b[i] == 0 ? n : i / b[i];
        g[L].push_back({R, i}); // L作为索引存入
    }

    for (int i = 1; i <= n; i++) //枚举左端点
    {
        for (PII p : g[i]) //依据左端点建堆
            que.push(p);
        PII p = que.top(); //取出右端点最小的值
        que.pop();
        a[p.second] = i; //放数
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
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