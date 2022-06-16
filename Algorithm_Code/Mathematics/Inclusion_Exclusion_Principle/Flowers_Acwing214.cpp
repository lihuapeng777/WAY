#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 20;
const int mod = 1e9 + 7;

ll A[N];
int down = 1;

int qmi(int a, int k, int p)

{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

int C(ll a, ll b)
{
    if (a < b)
        return 0;
    int up = 1;
    // down定义在全局了

    for (ll i = a; i > a - b; i--)
        up = i % mod * up % mod;

    return (ll)up * down % mod; //费马小定理
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int j = 1; j <= n - 1; j++)
        down = (ll)j * down % mod;

    down = qmi(down, mod - 2, mod);

    int res = 0;
    for (int i = 0; i < 1 << n; i++)
    {
        ll a = m + n - 1;
        ll b = n - 1;
        int sign = 1;

        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                sign *= -1;    //容斥原理展开后的式子
                a -= A[j] + 1; //至少A[j]+1
            }
        }
        res = (res + C(a, b) * sign) % mod;
    }

    cout << (res + mod) % mod << endl;

    return 0;
}