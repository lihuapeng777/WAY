#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
typedef long long ll;

int n;
int a[N], b[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1]; //构造差分序列

    ll p = 0, q = 0;
    for (int i = 2; i <= n; i++)
    {
        if (b[i] > 0)
            p += b[i]; //正数之和
        else
            q -= b[i]; //负数之和
    }

    cout << max(p, q) << endl;      //最小操作次数
    cout << abs(p - q) + 1 << endl; //可能的 序列结果方案数

    return 0;
}