#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100005;
int cows[N];
double sum[N];

int n, m;

bool check(double avg)
{
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (cows[i] - avg); //计算前缀和
    }

    double minv = 0; //设置最小值
    for (int i = 0, j = m; j <= n; j++, i++)
    {
        minv = min(minv, sum[i]); //找最优极小值
        if (sum[j] - minv >= 0)
            return true; //进行判断
    }
    return false; //如果所有的都不满足，那么这个平均数就一定不满足
}

int main()
{
    scanf("%d %d", &n, &m);
    double l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cows[i]);
        r = max(r, (double)cows[i]);
    } //最小左区间 最大右区间

    while (r - l > 1e-5)
    {                             //开始二分 因为是实数所以这里还搞个精度
        double mid = (l + r) / 2; // 不是>>1 这里是实数
        if (check(mid))
            l = mid; //将问题转变为判定问题
        else
            r = mid;
    }
    printf("%d\n", (int)(r * 1000)); //因为我们找的极大值 所以要右端点*1000 否则可能会出错
    return 0;
}