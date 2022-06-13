#include <iostream>
using namespace std;

const int N = 150;
const int mod = 1000;

int k, x;
int f[1000][100][N]; //前两维是组合数,后一位是高精度

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

//高精度：a=b+c
void add(int a[N], int b[N], int c[N])
{
    for (int i = 0, t = 0; i < N; i++)
    {
        t += b[i] + c[i];
        a[i] = t % 10;
        t /= 10;
    }
}

int main()
{
    cin >> k >> x;

    //求n=x^x
    int n = qmi(x % mod, x);

    //求组合数C(n-1,k-1);
    //递推式：C(i,j)=C(i-1,j)+C(i-1,j);
    for (int i = 0; i < n; i++)
    {                                         //因为最终状态是：C的上端是 k-1，故上端的范围是k-1
        for (int j = 0; j <= i && j < k; j++) // C的上端要求严格小于等于 下端
        {
            if (!j) // C的上端
                f[i][j][0] = 1;
            else
                add(f[i][j], f[i - 1][j], f[i - 1][j - 1]);
        }
    }

    //输出答案C(n-1,k-1);
    //先去掉前导零，再输出g
    int it = N - 1;
    while (!f[n - 1][k - 1][it]) //寻找第一个不等于 0的 组合数C n-1 k-1
        --it;
    while (it >= 0)
    {
        cout << f[n - 1][k - 1][it--];
    }

    return 0;
}