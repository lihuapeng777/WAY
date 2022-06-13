//题目要求1 与 1 之间 至少要间隔 K 个 0
/*
求出满足上述要求的方案数

f[i]集合：考虑i头牛，且第i头牛是1的方案
f[i]属性：方案数
状态计数：f[i]=f[i-k-1]+f[i-k-2]+.....+f[0]
此处设置一个边界f[0]表示 只有0没有1的边界情况

最终的答案就是把所有f[i]包括(f[0]，表示该方案全是0，没有1)累加起来即可
res=f[0]+f[1]+...f[n]
可以用前缀和数组进行优化
*/

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int mod = 5000011;
int n, k;
int f[N], s[N];

int main()
{
    cin >> n >> k;

    f[0] = s[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = s[max(i - k - 1, 0)]; // 0用来处理所有负数边界
        s[i] = (s[i - 1] + f[i]) % mod;
    }

    cout << s[n] << endl;

    return 0;
}