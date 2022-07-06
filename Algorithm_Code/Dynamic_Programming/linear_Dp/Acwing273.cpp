#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010, INF = 0x3f3f3f3f;

int n;
int a[N], b[N];
int f[N][N];

int work()
{
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i++)
    {
        int minv = INF; //表示只考虑i-1个元素，结尾元素为b中的下标为1到j的最优解
        for (int j = 1; j <= n; j++)
        {
            minv = min(minv, f[i - 1][j]);     //先更新一下最优解
            f[i][j] = minv + abs(a[i] - b[j]); // dp[i][j] 就是只考虑前i-1种元素的最优解加上当前这个的abs
        }
    }

    int res = INF;
    for (int i = 1; i <= n; i++)
        res = min(res, f[n][i]);

    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int res = work();
    reverse(a + 1, a + n + 1);
    res = min(res, work());

    printf("%d\n", res);

    return 0;
}