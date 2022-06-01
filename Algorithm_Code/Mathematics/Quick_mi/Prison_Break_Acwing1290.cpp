#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int mod = 100003;

int qmi(int a, ll k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % mod;
        a = (ll)a * a % mod;
        k >>= 1;
    }
    return res;
}

int main()
{
    int m;
    ll n;
    cin >> m >> n;

    cout << (qmi(m, n) - (ll)m * qmi(m - 1, n - 1) % mod + mod) % mod << endl;

    return 0;
}