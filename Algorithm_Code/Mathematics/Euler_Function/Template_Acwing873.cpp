/*
#include <iostream>
using namespace std;

int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i++)
        // 分解质因数，带入公式
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        res = res / x * (x - 1);

    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << phi(x) << endl;
    }

    return 0;
}*/

#include <iostream>
using namespace std;

const int N = 50010;
int primes[N], cnt;
bool st[N];
int phi[N];

void init(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) //是素数
        {
            primes[cnt++] = i;
            phi[i] = i - 1; //除了自身之外的1~i-1的数
        }
        for (int j = 0; primes[j] * i <= n; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) //能被最小质因子整除
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            //不能被最小质因子整除
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    init(N - 1);

    for (int i = 1; i <= 12; i++)
        printf("%d %d\n", i, phi[i]);
    system("pause");

    return 0;
}