#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
struct SegmentTree
{
    int l, r;
    int v; //区间[l,r]的最大值
} tr[4 * N];
int a[N]; //原始数组
int n, m;

void pushup(int u)
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r)
    {
        tr[u].v = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int v)
{
    if (tr[u].l == tr[u].r)
    {
        if (tr[u].v < v)
            tr[u].v = v;
        return;
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;

        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);

        pushup(u); //回溯
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].v; // 树中节点，已经被完全包含在[l, r]中了

    int mid = tr[u].l + tr[u].r >> 1;
    int v = -1e9;
    if (l <= mid)
        v = query(u << 1, l, r);
    if (r > mid)
        v = max(v, query(u << 1 | 1, l, r));

    return v;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    build(1, 1, n);

    while (m--)
    {
        char op[2];
        int l, r;
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'Q') //查询
        {
            cout << query(1, l, r) << endl;
        }
        else if (*op == 'U') //单点修改
        {
            modify(1, l, r);
        }
    }

    return 0;
}