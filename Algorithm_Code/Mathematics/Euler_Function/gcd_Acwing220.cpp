#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e7 + 10;

int primes[N], cnt;
bool st[N];
int phi[N];
ll s[N];

void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] * i <= n; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    for (int i = 1; i <= n; i++) //求前缀和
        s[i] = s[i - 1] + phi[i];
}

int main()
{
    int n;
    cin >> n;

    init(n);

    ll res = 0;
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];       //因为题目中要求的最大公约数为素数的情况
        res += s[n / p] * 2 + 1; //即把2~n的所有素数的情况都枚举一遍
    }

    cout << res << endl;

    return 0;
}