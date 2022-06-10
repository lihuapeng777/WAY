#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    vector<int> v;
    v.push_back(b[0] - a[0]);
    int last = b[0];
    for (int i = 1; i < n; i++)
    {
        int t = b[i] - a[i];
        if (a[i] < last)
            t = b[i] - last;
        last = b[i];
        v.push_back(t);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
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