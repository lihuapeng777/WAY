#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 5, INF = 0x3f3f3f3f;
int h[maxn], e[maxn * 2], ne[maxn * 2], idx;
int sz[maxn], f[maxn];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int fa)
{
    sz[u] = 1;
    int s1 = -1, s2 = -1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            dfs(j, u);
            sz[u] += sz[j];
            if (s1 == -1)
                s1 = j;
            else if (s2 == -1)
                s2 = j;
        }
    }
    if (s1 == -1)
        return f[u] = 0;
    if (s2 == -1)
        return f[u] = sz[s1] - 1;
    return f[u] = max(sz[s1] - 1 + f[s2], sz[s2] - 1 + f[s1]);
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
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            h[i] = -1;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            add(a, b), add(b, a);
        }
        cout << dfs(1, -1) << '\n';
    }
}