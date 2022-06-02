#include <cstdio>
#include <iostream>

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

    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        int s = 0;
        for (int j = n; j; j /= p)
            s += j / p;
        printf("%d %d\n", p, s);
    }

    return 0;
}
/*
p=2 s=0
for(int j=5;j;j/=2)
(1)s+=5/2=2
j=5/=2=1

(2)s+=1/2=0
j=1/2=0

*/