/*
对于x
若对懒标记的处理是先加再乘
    若此次操作为乘上一个数c
        可以表示为 (n + add) * mul * c 即 (n + X) * X 的形式
    若此次操作为加上一个数c
        (n + add) * mul + c 不能写成 (n + X ) * X的形式
        -> 无法更新新的懒标记

若对懒标记的处理是先乘再加
    若此次操作是加上一个数c
        可以表示为n * mul + add + c
        -> 此时新的add即为add + c
    若此次操作是乘上一个数c
        可以表示为n * mul * c + add * c
        -> 此时新的add即为add * c，新的mul即为mul * c

-> 故先乘再加，以便更新懒标记

可以把乘和加的操作都看成 x * c + d
    -> 若是乘法，d为0
    -> 若是加法，c为1

若当前x的懒标记为add和mul
    -> 操作可以写成(x * mul + add) * c + d
    -> 即x * (mul * c) + (add * c + d)
    -> 新的mul为(mul * c)，新的add为(add * c + d)

注意：乘的懒标记初始为1

作者：bigstone
链接：https://www.acwing.com/solution/content/43107/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, p, m;
int w[N];
struct Node
{
    int l, r, sum, add, mul;
} tr[4 * N];

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void eval(Node &root, int add, int mul) //计算在该区间加或乘一个数，数据可能会爆int
{
    root.sum = ((LL)root.sum * mul + (LL)(root.r - root.l + 1) * add) % p;
    root.mul = (LL)root.mul * mul % p;         //根据推的公式
    root.add = ((LL)root.add * mul + add) % p; //根据推的公式
}

void pushdown(int u)
{
    eval(tr[u << 1], tr[u].add, tr[u].mul);     //把当父区间的懒标记看作加或乘操作
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul); // tr[u].add即为在子区间加上add，mul同理
    tr[u].add = 0;                              //删去父区间懒标记
    tr[u].mul = 1;                              //删去父区间懒标记
}

void build(int u, int l, int r)
{
    tr[u].r = r, tr[u].l = l;
    if (l == r)
        tr[u].sum = w[l], tr[u].add = 0, tr[u].mul = 1;
    else
    {
        int mid = l + r >> 1;
        tr[u].add = 0, tr[u].mul = 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u); //回溯时通过子区间更新父区间信息
    }
}

void modify(int u, int l, int r, int add, int mul)
{
    if (tr[u].l >= l && tr[u].r <= r)
        eval(tr[u], add, mul); //若当前访问区间在查询区间内
    else
    {
        pushdown(u); //区间分列时需先处理懒标记
        int mid = tr[u].r + tr[u].l >> 1;
        if (mid >= l)
            modify(u << 1, l, r, add, mul); //递归处理左右子区间
        if (mid < r)
            modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum; //若当前访问区间在查询区间内
    else
    {
        pushdown(u); //区间分列时需先处理懒标记
        int mid = tr[u].l + tr[u].r >> 1;
        int sum = 0;
        if (mid >= l)
            sum = query(u << 1, l, r) % p; //递归处理左右子区间
        if (mid < r)
            sum = (sum + query(u << 1 | 1, l, r)) % p;
        return sum;
    }
}

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        int t, l, r, d;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            scanf("%d", &d);
            modify(1, l, r, 0, d);
        }
        else if (t == 2)
        {
            scanf("%d", &d);
            modify(1, l, r, d, 1);
        }
        else
            printf("%d\n", query(1, l, r));
    }
    return 0;
}