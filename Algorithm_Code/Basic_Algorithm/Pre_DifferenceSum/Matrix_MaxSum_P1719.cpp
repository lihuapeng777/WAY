#include <bits/stdc++.h>
using namespace std;

const int N = 130;
int a[N][N], pre[N][N]; // pre指的是第i行->j的前缀和
int sum[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]),
                pre[i][j] = pre[i][j - 1] + a[i][j],
                sum[i][j] = sum[i - 1][j] + pre[i][j];

    int mx = -0x3f3f3f3f;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= n; y1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                for (int y2 = 1; y2 <= n; y2++)
                {
                    if (x2 < x1 || y2 < y1)
                        continue;
                    mx = max(mx, sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x2][y1 - 1] - sum[x1 - 1][y2]);
                }
            }
        }
    }
    cout << mx << endl;
    return 0;
}