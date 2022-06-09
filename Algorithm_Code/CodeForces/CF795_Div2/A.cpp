#include <iostream>
#include <map>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt_odd = 0;
    int cnt_even = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1)
            cnt_odd += 1;
        else
            cnt_even += 1;
    }
    cout << min(cnt_odd, cnt_even) << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}