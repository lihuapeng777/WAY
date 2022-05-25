// https://www.acwing.com/activity/content/code/content/3466165/
/*
//(1)模拟
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e4 + 10;
int w[N];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);

    int res = 0;

    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);

        for (int i = l; i <= r; i++)
            w[i] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        if (w[i] == 1)
            res++;//统计被标记的树个数
    }

    cout << n-res+1 << endl;

    system("pause");

    return 0;
}
*/

//线段树
/*#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10;
struct SegmentTree
{
    int l, r;
    int sum;
} tr[4 * N];
int l, m;

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    tr[u].l = l;
    tr[u].r = r;
    if (l == r)
    {
        tr[u].sum = 1;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int x, int y)
{
    //范围外 || 已经被标记为了0
    if (l > y || r < x || tr[u].sum == 0)
        return;

    if (x <= l && y >= r) //完全包含
    {
        tr[u].sum = 0;
        return;
    }
    int mid = l + r >> 1;
    modify(u << 1, l, mid, x, y);
    modify(u << 1 | 1, mid + 1, r, x, y);
    pushup(u);
}

int main()
{
    scanf("%d%d", &l, &m);

    build(1, 1, l + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        modify(1, 1, l + 1, x + 1, y + 1);
    }

    printf("%d\n", tr[1].sum);

    return 0;
}
*/

//线段树懒标记
/*
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e4 + 10;
struct SegmentTree
{
    int l, r;
    int sum;
    bool f;
} tr[N * 4];
int n, m;

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    if (!tr[u].f) //如果没有被标记过
        return;
    tr[u << 1].sum = tr[u << 1].r - tr[u << 1].l + 1; //因为值是1,所以sum也即[l,r]元素的个数
    tr[u << 1].f = true;
    tr[u << 1 | 1].sum = tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1;
    tr[u << 1 | 1].f = true;
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, 0};
    else
    {
        tr[u] = {l, r, 0};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        tr[u].sum = tr[u].r - tr[u].l + 1, tr[u].f = true;
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (mid >= l)
            modify(u << 1, l, r);
        if (mid < r)
            modify(u << 1 | 1, l, r);
        pushup(u);
    }
}

void solve()
{
    cin >> n >> m;
    build(1, 0, n);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        modify(1, l, r);
    }
    cout << n + 1 - tr[1].sum << endl;
}

signed main()
{
    solve();
    return 0;
}
*/

//区间合并
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int n, m;
PII seg[N];

int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        cin >> seg[i].first >> seg[i].second;

    sort(seg, seg + n);

    int res = m + 1;
    int st = seg[0].first;
    int ed = seg[0].second;

    for (int i = 1; i < n; i++)
    {
        if (seg[i].first <= ed)
            ed = max(seg[i].second, ed);
        else
        {
            res -= ed - st + 1;
            st = seg[i].first;
            ed = seg[i].second;
        }
    }
    res -= ed - st + 1;

    cout << res << endl;

    return 0;
}