#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;

int primes[N], cnt;
bool st[N];

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

int main()
{
    int n;
    cin >> n;

    init(n);

    int res = 1;
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        int s = 0;
        for (int j = n; j; j /= p)
            s += j / p;                    //质因子的指数
        res = (ll)res * (2 * s + 1) % mod; //约数个数公式
    }

    cout << res << endl;

    return 0;
}