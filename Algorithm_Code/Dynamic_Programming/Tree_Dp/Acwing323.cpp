#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1510;
int h[N], e[N], ne[N], idx;
int f[N][2];
bool not_root[N];
int n;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u)
{
    f[u][0] = 0;
    f[u][1] = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += f[j][i];
        f[i][1] += min(f[j][0], f[j][1]);
    }
}

int main()
{
    while (~scanf("%d", &n))
    {
        memset(h, -1, sizeof h);
        memset(not_root, 0, sizeof not_root);
        idx = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b, siz;
            scanf("%d:(%d) ", &a, &siz);
            while (siz--)
            {
                scanf("%d", &b);
                add(a, b);
                not_root[b] = true;
            }
        }
        int root = 0;
        while (not_root[root])
            root++;
        dfs(root);
        cout << min(f[root][0], f[root][1]) << endl;
    }
}