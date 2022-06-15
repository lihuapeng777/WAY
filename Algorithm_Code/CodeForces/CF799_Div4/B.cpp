#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(a[i]);

    int n1 = st.size();

    if (n % 2 == 0 and n1 % 2 == 0)
        cout << n1 << endl;
    else if (n % 2 == 0 and n1 % 2 == 1)
        cout << n1 - 1 << endl;
    else if (n % 2 == 1 and n1 % 2 == 0)
        cout << n1 - 1 << endl;
    else if (n % 2 == 1 and n1 % 2 == 1)
        cout << n1 << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}