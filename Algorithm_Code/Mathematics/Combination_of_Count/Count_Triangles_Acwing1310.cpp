#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, m;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

LL C(LL a, LL b)
{
    return a * (a - 1) * (a - 2) / 6;
}

int main()
{
    cin >> n >> m;
    n++, m++;                                         // 转化为格点数
    LL res = C(n * m, 3) - n * C(m, 3) - m * C(n, 3); //平行于横轴 与 平行于纵轴的情况
    n--, m--;                                         // 还原成长度
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            res -= 2 * (n - i + 1) * (m - j + 1) * (gcd(i, j) - 1);
    }
    cout << res << endl;
    return 0;
}