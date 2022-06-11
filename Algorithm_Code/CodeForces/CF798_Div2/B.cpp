#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2010;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = i;
    }

    if (n == 1)
    {
        cout << "-1" << endl;
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            swap(b[i], b[i + 1]);
    }

    if (a[n] == b[n])
        swap(b[n - 1], b[n]);

    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}