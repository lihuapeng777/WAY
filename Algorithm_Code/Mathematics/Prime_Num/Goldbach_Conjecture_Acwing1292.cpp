#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000010;
int primes[N], cnt;
bool st[N];

void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) //用质数筛
        {
            st[primes[j] * i] = true; //质数的i倍筛掉
            if (i % primes[j] == 0)   //如果i被primes筛掉,break;
                break;
        }
    }
}

int main()
{
    init(N - 1);

    int n;
    while (cin >> n, n)
    {
        for (int i = 1;; i++)
        {
            int a = primes[i];
            int b = n - a;
            if (!st[b])
            {
                printf("%d=%d+%d\n", n, a, b);
                break;
            }
        }
    }

    return 0;
}