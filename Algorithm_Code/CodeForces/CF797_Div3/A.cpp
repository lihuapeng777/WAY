#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n % 3 == 0)
    {
        cout << n / 3 << " " << n / 3 + 1 << " " << n / 3 - 1 << endl;
    }
    else
    {
        int l2, l3;
        int t = n % 3;
        int l1 = n / 3 + 2;

        l2 = n / 3 + t / 2;
        l3 = n / 3 - 1;
        cout << l2 << " " << l1 << " " << l3 << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}