// Code:预处理（包括其本身的差分）
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int N = 100010;
int n, m;
int a[N];
ll tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

ll sum(int x)
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        add(i, a[i] - a[i - 1]); //树上差分

    while (m--)
    {
        char op[2];
        int l, r, d;
        scanf("%s%d", op, &l);
        if (*op == 'C') //区间修改
        {
            scanf("%d%d", &r, &d);
            add(l, d);
            add(r + 1, -d);
        }
        else
            printf("%lld\n", sum(l));
        //树状数组中的前缀和维护使得差分数组能更快地求出 1~i的差分数组的和
    }

    return 0;
}

// Code：预处理：只记录变化区间的差分《算法竞赛进阶指南》
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int tr[N]; //树上差分
int n, m;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    while (m--)
    {
        char op[2];
        int l;
        scanf("%s%d", op, &l);

        if (*op == 'C') //区间添加操作
        {
            int r, d;
            scanf("%d%d", &r, &d);
            add(l, d), add(r + 1, -d);
        }
        else
        {
            printf("%d\n", sum(l) + a[l]);
        }
    }

    return 0;
}
