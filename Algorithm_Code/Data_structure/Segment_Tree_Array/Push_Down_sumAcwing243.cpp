#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100010;
int n, m;
int w[N];
struct Node
{
    int l, r;
    // sum：如果考虑当前节点及子节点上的所有标记，当前区间是多少
    // add：给当前区间的所有儿子加上add(不包括当前区间！)
    ll sum, add;
} tr[4 * N];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    auto &root = tr[u]; //引用:取别名
    auto &left = tr[u << 1];
    auto &right = tr[u << 1 | 1];

    if (root.add)
    {
        left.add += root.add; //左区间的根节点+=当前根节点的add
        //左区间的和修改为：左区间所有数的个数*add
        left.sum += (ll)(left.r - left.l + 1) * root.add;

        //右区间同理
        right.add += root.add;
        right.sum += (ll)(right.r - right.l + 1) * root.add;

        root.add = 0; //加了之后就没了
    }
}

void build(int u, int l, int r)
{
    if (l == r)                  //叶节点的区间和初始化为：原数组的大小
        tr[u] = {l, r, w[r], 0}; // add初始为0
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u); //回溯需要**pushup**
    }
}

void modify(int u, int l, int r, int d)
{
    if (tr[u].l >= l && tr[u].r <= r) //完全包含
    {
        tr[u].sum += (ll)(tr[u].r - tr[l].l + 1) * d;
        tr[u].add += d;
    }
    else //一定要分裂
    {
        pushdown(u); //父节点向下更新
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, d);
        if (r > mid)
            modify(u << 1 | 1, l, r, d);
        pushup(u); //回溯时子节点向上更新
    }
}

ll query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if (l <= mid)
        sum = query(u << 1, l, r);
    if (r > mid)
        sum += query(u << 1 | 1, l, r);
    return sum;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n;; i++)
        scanf("%d", &w[i]);

    build(1, 1, n);

    char op[2];
    int l, r, d;

    while (m--)
    {
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'C')
        {
            scanf("%d", &d);
            modify(1, l, r, d);
        }
        else
            printf("%lld\n", query(1, l, r));
    }

    return 0;
}