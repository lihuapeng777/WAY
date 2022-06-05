#include <iostream>
using namespace std;

typedef long long ll;
const int N = 15;

int n;
int a[N], m[N];

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

int main()
{
    cin >> n;
    ll M = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> m[i] >> a[i];
        M *= m[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll Mi = M / m[i]; //计算Mi=M/mi
        ll ti, y;
        //这一步是求逆元,根据逆元公式的衍生公式可以得到：ti*Mi+y*mi=1
        exgcd(Mi, m[i], ti, y);
        res += a[i] * Mi * ti; //计算的同时累加到res中
    }
    //对于任意x+kM都是满足要求的解，但目标是输出最小的正整数x，因此取模即可
    cout << (res % M + M) % M << endl;

    return 0;
}