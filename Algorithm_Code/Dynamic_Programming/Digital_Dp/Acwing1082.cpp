#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int f[N][N]; // f[i][j]表示i位数最高位为j的不降序的方案数

void init()
{
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = j; k <= 9; k++)
                f[i][j] += f[i - 1][k];
}

int dp(int n)
{
    if (!n)
        return 1;
    // n==0,只有0这一种方案

    vector<int> nums;
    while (n)
        nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = 0; //保存上一位的最大值
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for (int j = last; j < x; j++) //左边分支
            res += f[i + 1][j];

        if (last > x) //不构成降序,右分支结束
            break;
        last = x;
        if (!i)
            res++;
    }
    return res;
}

int main()
{
    int n, m;
    init();

    while (cin >> n >> m)
        cout << dp(m) - dp(n - 1) << endl;

    return 0;
}