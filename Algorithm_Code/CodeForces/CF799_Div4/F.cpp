#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N];

void solve()
{
    int n;
    cin >> n;
    vector<int> b(10, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i] %= 10;
        b[a[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (((i + j + k) % 10 == 3 and b[i] >= 3 and i == j and i == k) ||
                    ((i + j + k) % 10 == 3 and b[i] >= 2 and b[j] >= 1 and i == k and i != j) ||
                    ((i + j + k) % 10 == 3 and b[i] >= 1 and b[j] >= 1 and b[k] >= 1 and i != j and i != k and j != k))
                {
                    puts("YES");
                    return;
                }
            }
        }
    }
    puts("NO");
    return;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}