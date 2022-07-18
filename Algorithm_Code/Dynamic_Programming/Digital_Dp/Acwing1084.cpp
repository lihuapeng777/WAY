#include <bits/stdc++.h>
using namespace std;

const int N = 11, M = 110;
int f[N][10][M]; //一共有i位,且最高位数字是j,且所有位数字和模N结果为k的数的个数
int p;

int mod(int u, int v) { return (u % v + v) % v; }

void init()
{
    memset(f, 0, sizeof f);
    for (int i = 0; i <= 9; i++)
        f[1][i][i % p]++;

    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k < p; k++)
                for (int x = 0; x <= 9; x++)
                    f[i][j][k] += f[i - 1][x][mod(k - j, p)]; //推公式
}

int dp(int n)
{
    if (!n)
        return 1;

    vector<int> nums;
    while (n)
        nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = 0; //最高位到 第i位的个数和
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for (int j = 0; j < x; j++)            //第i位放0~x-1
            res += f[i + 1][j][mod(-last, p)]; // 0~i位,一共有i+1位
        //枚举后面对应的满足的情况
        last += x;
        if (!i and last % p == 0)
            res++; //全选右端点且到头的情况
    }
    return res;
}

int main()
{
    int l, r;
    while (cin >> l >> r)
    {
        init();
        cout << dp(r) - dp(l - 1) << endl;
    }
    return 0;
}