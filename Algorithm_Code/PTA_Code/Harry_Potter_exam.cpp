#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
int dist[N], g[N][N], st[N];

void dijkstra(int start) 
{
    memset(st, 0, sizeof(st));//清空st数组
    for (int i = 1; i <= n; i++)//此时以start为源点
        dist[i] = g[start][i];
    dist[start] = 0;//到自身的距离为1
    st[start] = 1;//标记已经使用
    for (int i = 1; i < n; i++) 
    {
        int mindist = INF, u = -1;
        for (int j = 1; j <= n; ++j)
            if ((!st[j]) && dist[j] < mindist)//如果没有走过 且 最小距离小于 之前的最小距离
            {
                mindist = dist[j];
                u = j;//那么就用最小的进行扩展
            }
        st[u] = 1;//标记已经使用
        if (u != -1)//如果不是一开始用的点(无意义的-1)
        {
            for (int j = 1; j <= n; j++)
                if ((!st[j]) && g[u][j] < INF && dist[u] + g[u][j] < dist[j])//更新
                    dist[j] = dist[u] + g[u][j];
        }
    }
}
int main()
{
    cin >> n >> m;
    
    memset(g,0x3f,sizeof g);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;//无向图
    }

    int l = 0, p = 0, maxv = INF;

    for (int i = 1; i <= n; i++) 
    {
        dijkstra(i);
        sort(dist + 1, dist + n + 1);
        if (dist[n] == INF)   l++;//如果最后为INF，说明是条死路，无法连通所有
        if (dist[n] < maxv)//找到最小的花费
        {
            maxv = dist[n];
            p = i;
        }
    }
    if (l == n)//死路情况
        cout << "0" << endl;
    else
        cout << p << " " << maxv << endl;
    return 0;
}