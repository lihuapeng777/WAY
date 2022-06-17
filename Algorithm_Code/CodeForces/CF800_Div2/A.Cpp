#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    string str = "";

    int t1 = a, t2 = b;
    while (t1 || t2)
    {
        if (t1 > 0)
            str += "0", t1--;
        if (t2 > 0)
            str += "1", t2--;
    }

    cout << str << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}