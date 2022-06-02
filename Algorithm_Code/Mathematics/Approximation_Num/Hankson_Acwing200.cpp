//暴力法：总的时间复杂度是：O(T*logN*sqrt(N))

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * 1ll * b / gcd(a, b);
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int a, b, c, d; // b:最大公约数;d:最小公倍数
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int s = 0;
        for (int i = 1; i * i <= d; i++) //根号试除法：枚举x(因为x是d的倍数)
        {
            if (d % i) //不是倍数：过滤掉
                continue;
            if (gcd(a, i) == b and lcm(c, i) == d) //满足条件
                s++;
            if (i != d / i and gcd(a, d / i) == b and lcm(c, d / i) == d) //双端枚举：提高效率
                s++;
        }
        printf("%d\n", s);
    }

    return 0;
}

//优化：
/*
先预处理除1~sqrt(b1)内的所有质数,然后用这些质数取试除b1
将b1分解为质因数,然后通过dfs枚举除b1的所有约数
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 50010;

int primes[N], cnt;
bool st[N];
struct Factor
{
    int p, s; //质因子,该质因子的次数
} factor[10];
int fcnt; //质因子的个数

int dividor[1601], dcnt;

void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void dfs(int u, int p)
{
    if (u == fcnt) //枚举完了最小公倍数的所有质因子
    {
        dividor[dcnt++] = p; //记录
        return;
    }

    for (int i = 0; i <= factor[u].s; i++) //枚举该质数的所有次数
    {
        dfs(u + 1, p);    //
        p *= factor[u].p; //次数+1，即底数要多乘一个p
    }
}

int main()
{
    init(N - 1);

    int n;
    cin >> n;

    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        fcnt = 0;  //质因子的个数初始化为0
        int t = d; //最小公倍数

        for (int i = 0; primes[i] <= t / primes[i]; i++) //用质数试除最小公倍数
        {
            int p = primes[i];
            if (t % p == 0) //表示p此时是最小公倍数的质因子
            {
                int s = 0;
                while (t % p == 0) //求该质因子的出现次数
                    t /= p, s++;
                factor[fcnt++] = {p, s}; //存储质因子及其出现次数
            }
        }

        if (t > 1) //特判：防止没有除干净
            factor[fcnt++] = {t, 1};

        dcnt = 0;  //约数个数
        dfs(0, 1); //从第0个质数开始枚举,结果数
        //预处理出最小公倍数d->得出的所有质因子->质因子再重新组合成多个数字

        int res = 0;
        for (int i = 0; i < dcnt; i++) //枚举质因子重新组合成的多个数字
        {
            int x = dividor[i];
            if (gcd(a, x) == b and (ll) c * x / gcd(c, x) == d) //判断条件
                res++;
        }

        cout << res << endl;
    }

    return 0;
}