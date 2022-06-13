// https://www.acwing.com/solution/content/24670/
// https://www.acwing.com/solution/content/48248/
#include <iostream>
using namespace std;

typedef long long ll;
const int p = 1e6 + 3;

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    int up = 1, down = 1;
    for (int i = a, j = 1; j <= b; j++, i--)
    {
        up = (ll)up * i % p;
        down = (ll)down * j % p;
    }
    return (ll)up * qmi(down, p - 2) % p; //逆元
}

int Lucas(int a, int b)
{
    if (a < p && b < p)
        return C(a, b);
    return (ll)C(a % p, b % p) * Lucas(a / p, b / p) % p;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        cout << (Lucas(r - l + n + 1, r - l + 1) - 1 + p) % p << endl;
    }
    return 0;
}