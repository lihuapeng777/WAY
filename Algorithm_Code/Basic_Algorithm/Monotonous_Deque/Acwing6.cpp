#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010;

int n, m;
int f[N], g[N], q[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);
        for (int j = 0; j < v; j++)
        {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v)
            {
                if (hh <= tt && q[hh] < k - s * v) //超过队头元素
                    hh++;
                //实际比较的是 g[q[tt]] 与 g[k]的相对大小；但是每隔v减小一个w，所以需要比较 g[q[tt]] 与 g[k] -(k-q[tt])/v *w的大小
                while (hh <= tt && g[q[tt]] <= g[k] - (k - q[tt]) / v * w)
                    tt--;
                q[++tt] = k;
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}