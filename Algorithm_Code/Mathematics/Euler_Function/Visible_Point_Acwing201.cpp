#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int primes[N], cnt;
bool st[N];
int phi[N];

void init(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] * i <= n; j++)
        {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    init(N - 1);

    int n, m;
    cin >> m;
    for (int T = 1; T <= m; T++)
    {
        cin >> n;
        int res = 1;
        for (int i = 1; i <= n; i++)
            res += phi[i] * 2;
        cout << T << ' ' << n << ' ' << res << endl;
    }

    return 0;
}