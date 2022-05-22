#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 500010;
struct Node
{
    int l, r;
    LL sum, d; // sum表示区间和，d表示[l,r]区间内的最大公约数
} tr[N * 4];   //最大开四倍空间
LL w[N];
int n, m; // n:数组元素个数；m：问题个数

LL gcd(LL a, LL b) //辗转相除
{
    return b ? gcd(b, a % b) : a;
}

void pushup(Node &u, Node &left, Node &right)
{
    u.sum = left.sum + right.sum;
    u.d = gcd(left.d, right.d);
}

void pushup(int u) //重载一下pushup,可以省去一点步骤
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) //维护的是一个差分数组
{
    if (l == r) //根节点，递归出口
    {
        LL d = w[r] - w[r - 1]; //差分值
        tr[u] = {l, r, d, d};   //初始化
    }
    else
    {
        tr[u].r = r, tr[u].l = l;
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        //回溯，用子节点的信息更新父节点
        pushup(u);
    }
}

void modify(int u, int x, LL v) //从u节点开始，修改x位置的值为v
{
    if (tr[u].l == x && tr[u].r == x)
    {
        LL sum = tr[u].sum + v;
        tr[u].sum = sum;
        tr[u].d = sum;
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (mid >= x)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        //回溯，用子节点的信息更新父节点的信息
        pushup(u);
    }
}

Node query(int u, int l, int r) //找到[l,r]这个区间
{
    if (tr[u].l >= l && tr[u].r <= r)
    { //找到完全包含的区间直接返回
        return tr[u];
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid)
        { //完全在左半区间,递归左半区间
            return query(u << 1, l, r);
        }
        else if (l > mid)
        { //完全在右半区间，递归右半区间
            return query(u << 1 | 1, l, r);
        }
        else
        { //横跨两个区间
            Node left = query(u << 1, l, r);
            Node right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &w[i]);

    build(1, 1, n);
    while (m--)
    {
        char op[2];
        int l, r;
        scanf("%s%d%d", op, &l, &r);
        if (op[0] == 'C')
        {
            LL d;
            scanf("%lld", &d);
            //对差分数组b[l] += c , b[r + 1] -= c,将相当于对原数组a[l ~ r] += c
            modify(1, l, d);
            if (r + 1 <= n)
                modify(1, r + 1, -d);
        }
        else if (op[0] == 'Q')
        {

            /**
             * 求(Al,Al+1,Al+2 ... Ar)这个区间的最大公约数
             * 可以转化为求(A[l] , A[l+1]-A[l] , A[l+2]-A[l+1] , A[l+3]-A[l+2] , ... , A[r]-A[r-1])的最大公约数
             */
            Node left = query(1, 1, l); // Al的值
            Node right({0, 0, 0, 0});
            //注意这个条件,题目中给出的数据l有可能比r大
            // b[l + 1 ~ r]的最大公约数，就相当于(A[l+1]-A[l] , A[l+2]-A[l+1] , A[l+3]-A[l+2] , ... , A[r]-A[r-1])的最大公约数
            if (l + 1 <= r)
                right = query(1, l + 1, r);

            /*
            可以只用求出A[l]和{b[l+1]~b[r] }这个区间的最大公约数即可；
            体现在代码上是gcd(left.sum,right.d)，其中left.sum是A[l]，right.d是{b[l+1]~b[r]}
            */
            LL res = abs(gcd(left.sum, right.d)); //约定最大公约数是没有负数的，所以遇到负数就把他取反
            printf("%lld\n", res);
        }
    }
}
