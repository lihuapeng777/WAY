#include <bits/stdc++.h>
const int N = 2e5 + 10;
using namespace std;
int a[N];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int sum = 0, M = -1e9 - 7, f = 1;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            M = max(M, a[i]);
            if (sum - M > 0)
            {
                cout << "NO" << endl;
                f = 0;
                break;
            }
            if (sum < 0)
                sum = 0, M = -1e9 - 7;
        }
        if (!f)
            continue;
        sum = 0, M = -1e9 - 7;
        for (int i = n; i >= 1; i--)
        {
            sum += a[i];
            M = max(M, a[i]);
            if (sum - M > 0)
            {
                cout << "NO" << endl;
                f = 0;
                break;
            }
            if (sum < 0)
                sum = 0, M = -1e9 - 7;
        }
        if (f)
            cout << "YES" << endl;
    }
    return 0;
}
