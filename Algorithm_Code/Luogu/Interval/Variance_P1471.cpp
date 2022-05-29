#include <iostream>
#include <cstdio>
using namespace std;

const int N = 300010;
double sega[N], segb[N];
double mark[N];

void pushup(int u)
{
    sega[u] = sega[u << 1] + sega[u << 1 | 1];
    segb[u] = segb[u << 1] + segb[u << 1 | 1];
}

void pushdown(int u, int x)
{
    if (mark[u]) //标记存在
    {
        segb[u << 1] += 2 * mark[u] * sega[u << 1] + (x - x / 2) * mark[u] * mark[u];
        segb[u << 1 | 1] += 2 * mark[u] * sega[u << 1 | 1] + (x / 2) * mark[u] * mark[u];
        sega[u << 1] += (x - x / 2) * mark[u];
        sega[u << 1 | 1] += (x / 2) * mark[u];
        mark[u << 1] += mark[u];
        mark[u << 1 | 1] += mark[u];

        mark[u] = 0; //取消标记
    }
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        cin >> sega[u];
        segb[u] = sega[u] * sega[u];
    }
    else
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

double query_a(int u, int l, int r, int L, int R)
{
    if (l >= L and r <= R)
    {
        return sega[u];
    }
    else
    {
        pushdown(u, r - l + 1);
        int mid = l + r >> 1;

        double res = 0;
        if (mid >= L)
            res += query_a(u << 1, l, mid, L, R);
        if (mid < R)
            res += query_a(u << 1 | 1, mid + 1, r, L, R);
        return res;
    }
}

double query_b(int u, int l, int r, int L, int R)
{
    //--L--l--r--R--
    if (l >= L && r <= R)
        return segb[u];
    else
    {
        pushdown(u, r - l + 1);
        int mid = (r + l) / 2;
        double ret = 0;
        if (mid >= L)
            ret += query_b(u << 1, l, mid, L, R);
        if (mid < R)
            ret += query_b(u << 1 | 1, mid + 1, r, L, R);
        return ret;
    }
}

void update(int u, int l, int r, int L, int R, double x)
{
    if (l >= L and r <= R)
    {
        mark[u] += x, segb[u] += 2 * x * sega[u] + x * x * (r - l + 1);
        sega[u] += (r - l + 1) * x;
    }
    else
    {
        pushdown(u, r - l + 1);
        int mid = l + r >> 1;

        if (mid >= L)
            update(u << 1, l, mid, L, R, x);
        if (mid < R)
            update(u << 1 | 1, mid + 1, r, L, R, x);
        pushup(u);
    }
}

double sqr(double x)
{
    return x * x;
}

int main()
{
    int n, m, x, y, c;
    double z;

    scanf("%d%d", &n, &m);

    build(1, 1, n);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &c);

        if (c == 2) //平均数
        {
            scanf("%d%d", &x, &y);
            printf("%.4lf\n", query_a(1, 1, n, x, y) / (y - x + 1));
        }
        if (c == 1) //区间+
        {
            scanf("%d%d", &x, &y);
            cin >> z;
            update(1, 1, n, x, y, z);
        }
        if (c == 3) //方差
        {
            scanf("%d%d", &x, &y);
            double sum1 = query_b(1, 1, n, x, y) / (y - x + 1);
            double sum2 = query_a(1, 1, n, x, y) / (y - x + 1);
            double ans = sum1 - sum2 * sum2;

            printf("%.4lf\n", ans);
        }
    }

    return 0;
}