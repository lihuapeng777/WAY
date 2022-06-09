/*
题目大意;
给定n，k分别代表元素个数，经过的时问数
接下来是n个元素值，a1 a2 a3 ... an

有3个限制条件：
(1)每次只能最远 移动 1步(可以不移动)
(2)从x->y的这个过程中,她将收集y点所有 值a[y]
(3)她收集完了之后,所有点的 值+1

特殊限制：
她可以任选一点作为起始点
她不可以在时间为0十收集，即一开始的位置起始点

问：
在k的时间内，她所能收集到的 值之和最多是多少
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 2e5 + 5;
LL A[N], Ans, PreSum[N];
int n, k;

void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", A + i);
    Ans = 0ll; //相当于 0
    if (k < n) //如果 元素个数 小于 时间数
    {
        for (int i = 1; i <= n; i++)
            PreSum[i] = PreSum[i - 1] + A[i]; //预处理前缀和
        for (int i = k; i <= n; i++)
            Ans = max(Ans, PreSum[i] - PreSum[i - k]); //滑动窗口：锁定k区间内和最大的数
        Ans += (LL)k * (k - 1) / 2;                    //等差求和公式???
        printf("%lld\n", Ans);
    }
    else
    {
        for (int i = 1; i <= n; i++) //每个都需要走一遍
            Ans += A[i];
        Ans += (LL)n * k - (LL)n * (n + 1) / 2; // https://zhuanlan.zhihu.com/p/524057359
        printf("%lld\n", Ans);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}