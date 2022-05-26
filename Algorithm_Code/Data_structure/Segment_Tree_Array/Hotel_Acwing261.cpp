#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50010;

struct Node
{
    int l, r;
    int d, ld, rd;
    int lazy;
} tr[N * 4];

int n, m;

/*
维护区间内最长的 0 串长度 d 需要同时维护以左端点开始的最长 0 串长度 ld
和以右端点结束的最长的 0 串长度 rd
用子节点更新父节点时可能会有左子节点右边的一截和右子节点左边的一截拼起来的情况
root.d = max(left.d, right.d, left.rd + right.ld)
*/

/*
询问时由于要找最靠左的满足条件的，那就从左往右依次询问
如果左子节点有满足条件的 00 串，那就返回左子节点的询问
如果左子节点和右子节点能拼出满足条件的 00 串，那就返回拼出的这个串的左端点
如果右子节点有满足条件的 00 串，那就返回右子节点的询问
否则返回 0

再有就是普通的懒标记下传，记得递归之前没事干都要pushdown一下
*/

void pushup(Node &u, Node &l, Node &r)
{
    u.ld = l.ld;
    //如果左节点的区间串长==左区间[l.l,l.r]的区间长
    if (l.d == l.r - l.l + 1)
        u.ld = l.d + r.ld;

    u.rd = r.rd;
    if (r.d == r.r - r.l + 1)
        u.rd = r.d + l.rd; //同理

    u.d = max(l.d, r.d);
    u.d = max(u.d, l.rd + r.ld);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r)
    {
        tr[u].d = tr[u].ld = tr[u].rd = 1;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(Node &u, Node &l, Node &r)
{
    if (u.lazy == 1)
    {
        l.d = l.ld = l.rd = l.r - l.l + 1;
        r.d = r.ld = r.rd = r.r - r.l + 1;
    }
    else if (u.lazy == 2)
    {
        l.d = l.ld = l.rd = r.d = r.ld = r.rd = 0;
    }
    l.lazy = r.lazy = u.lazy;
    u.lazy = 0;
}

void pushdown(int u)
{
    if (tr[u].lazy)
        pushdown(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

int query(int u, int len)
{
    if (tr[u].d == 1 && tr[u].l == tr[u].r && len == 1)
        return tr[u].l;
    if (tr[u].d < len)
        return 0;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (tr[u << 1].d >= len) //左区间的长度 >=len
        return query(u << 1, len);

    if (tr[u << 1].rd + tr[u << 1 | 1].ld >= len) //左区间的后缀+右区间的前缀
        return tr[u << 1].r - tr[u << 1].rd + 1;

    if (tr[u << 1 | 1].d >= len) //右区间的的长度
        return query(u << 1 | 1, len);
    return 0;
}

void modify(int u, int l, int r, int c)
{
    if (tr[u].l >= l and tr[u].r <= r)
    {
        if (c == 1) //入住
            tr[u].d = tr[u].ld = tr[u].rd = tr[u].r - tr[u].l + 1;
        else //退房
            tr[u].d = tr[u].ld = tr[u].rd = 0;
        tr[u].lazy = c;
        return;
    }

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(u << 1, l, r, c);
    if (r > mid)
        modify(u << 1 | 1, l, r, c);
    pushup(u);
}

int main()
{
    scanf("%d%d", &n, &m);

    build(1, 1, n);

    while (m--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int len;
            scanf("%d", &len);
            int l = query(1, len);
            printf("%d\n", l);
            if (l)
                modify(1, l, l + len - 1, 2);
        }
        else
        {
            int l, len;
            scanf("%d%d", &l, &len);
            modify(1, l, l + len - 1, 1);
        }
    }
    return 0;
}