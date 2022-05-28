// https://www.luogu.com.cn/blog/susheep/solution-p1438
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

struct point
{
    ll sum;
    ll tag;
} tr[4 * N];
ll a[N];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    tr[u].tag = 0;
    int mid = (l + r) >> 1;
    if (l == r)
    {
        tr[u].sum = a[l];
        return;
    }
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
void pushdown(int u, int l, int r)
{
    int mid = (l + r) >> 1;
    tr[u << 1].tag += tr[u].tag;
    tr[u << 1 | 1].tag += tr[u].tag;

    tr[u << 1].sum += tr[u].tag * (mid - l + 1);
    tr[u << 1 | 1].sum += tr[u].tag * (r - mid);

    tr[u].tag = 0;
}
void add(int u, int l, int r, int ql, int qr, ll x)
{
    if (ql <= l && qr >= r)
    {
        tr[u].tag += x;
        tr[u].sum += (r - l + 1) * x;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(u, l, r);
    if (ql <= mid)
        add(u << 1, l, mid, ql, qr, x);
    if (qr > mid)
        add(u << 1 | 1, mid + 1, r, ql, qr, x);
    pushup(u);
    // return;
}
ll query(int u, int l, int r, int ql, int qr)
{
    if (ql <= l && qr >= r)
        return tr[u].sum;
    int mid = (l + r) >> 1, ret = 0;
    pushdown(u, l, r);
    if (ql <= mid)
        ret += query(u << 1, l, mid, ql, qr);
    if (qr > mid)
        ret += query(u << 1 | 1, mid + 1, r, ql, qr);
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n - 1; i > 0; i--)
        a[i + 1] = a[i + 1] - a[i];
    build(1, 1, n);

    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            add(1, 1, n, l, l, k); //处理[l,k]区间的序列
            //剩下的2个if是对 r的情况进行讨论
            if (l + 1 <= r) //当l与r之间间隔0，1个元素时
                add(1, 1, n, l + 1, r, d);
            if (r < n)                                          //普通情况：间隔>=2个元素时,并且保证在n内
                add(1, 1, n, r + 1, r + 1, -(k + d * (r - l))); //注意这里加了判断
        }
        else
        {
            int t;
            cin >> t;
            cout << query(1, 1, n, 1, t) << endl;
        }
    }
    return 0;
}