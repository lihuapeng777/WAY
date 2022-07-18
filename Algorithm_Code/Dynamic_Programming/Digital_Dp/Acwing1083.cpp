#include <bits/stdc++.h>
using namespace std;

const int N = 11;

int f[N][N]; // f[i][j] 表示一共有i位，且最高为是数字j的满足wingy数定义的数的个数

void init()
{
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (abs(k - j) >= 2)
                    f[i][j] += f[i - 1][k];
}

int dp(int n)
{
    int res = 0, last = -10;

    vector<int> a;
    while (n)
        a.push_back(n % 10), n /= 10;

    int len = a.size() - 1;
    //答案是a.size()位的
    for (int i = len; i >= 0; --i)
    {
        int x = a[i];
        for (int j = (i == len); j < x; ++j) //最高位从1开始
            if (abs(j - last) >= 2)
                res += f[i + 1][j];

        if (abs(x - last) < 2)
            break; //不满足定义，直接break
        last = x;

        if (!i)
            res++;
    }
    //答案小于a.size()位的
    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= 9; j++)
            res += f[i][j];

    return res;
}
int main()
{
    init();
    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1);
    return 0;
}