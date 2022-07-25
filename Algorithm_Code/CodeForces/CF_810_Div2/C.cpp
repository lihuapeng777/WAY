#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5, INF = 0x3f3f3f3f;
LL a[maxn];
LL n, m;
int k;

bool check()
{
    if ((n & 1) && a[k] < 3 * m)
        return false;
    LL sum = 0;
    for (int i = 1; i <= k; i++)
    {
        LL t = a[i] / m;
        if (t >= 2)
            sum += t;
    }
    return sum >= n;
}

int main()
{

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {

        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        sort(a + 1, a + k + 1);

        if (check())
        {
            cout << "Yes" << '\n';
            continue;
        }
        swap(n, m);
        if (check())
        {
            cout << "Yes" << '\n';
            continue;
        }
        cout << "No" << '\n';
    }
}