#include <iostream>
using namespace std;

typedef long long ll;
const int N = 2010;
const int mod = 100003;

int f[N], inf[N];

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (ll)res * a % mod;
        a = (ll)a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    if (a < b)
        return 0;
    return (ll)f[a] * inf[b] % mod * inf[a - b] % mod;
}

int A(int a, int b)
{
    if (a < b)
        return 0;
    return (ll)f[a] * inf[a - b] % mod;
}

int main()
{
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    f[0] = inf[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = (ll)f[i - 1] * i % mod;
        inf[i] = (ll)inf[i - 1] * qmi(i, mod - 2) % mod;
    }

    int res = 0;
    for (int i = 0; i <= b; i++)
        res = (res + (ll)C(b, i) * A(a, i) % mod * C(d, k - i) % mod * A(a + c - i, k - i) % mod) % mod;

    cout << (res % mod + mod) % mod << endl;

    return 0;
}