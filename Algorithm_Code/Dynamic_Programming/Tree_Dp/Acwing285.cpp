#include <iostream>
#include <algorithm>
using namespace std;

#define N 6010

bool vis[N]; // 判断此小弟是否有上司
int head[N], cnt;
int f[N][2], happy[N], n;

struct edge
{
    int to, nex;
} e[N];

void add(int from, int to)
{
    e[++cnt] = (edge){to, head[from]};
    head[from] = cnt;
}

void dfs(int boss)
{
    f[boss][1] = happy[boss]; // 1代表这个boss要来，先加上他来的利益

    for (int i = head[boss]; i; i = e[i].nex)
    {
        int too = e[i].to;
        dfs(too); // 递归一直搜

        f[boss][0] += max(f[too][0], f[too][1]); // boss不来，那小弟就是王了，但小弟要以利益为重，如果小小弟来可以获利更大，就让小小弟来
        f[boss][1] += f[too][0];                 // boss来了！！！小弟都承让
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> happy[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(b, a);
        vis[a] = true; // a有上司了（以后出行要小心）
    }

    int root = 1;
    while (vis[root])
        root++; // 找到根节点（没有上司的董事长）

    dfs(root);

    cout << max(f[root][0], f[root][1]); // 取董事长来和不来的最大利益
    return 0;
}