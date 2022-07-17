#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int s[N][N], l[N], r[N]; // h表示每个矩形高度，l和r分别表示矩形能向左右两侧扩展的边界
int q[N];                // q储存单调栈

int work(int h[]) //传入直方图的高，这个函数就是131题的原代码
{
    h[0] = h[m + 1] = -1; //保证矩形左右两侧一定有小于它高度的矩形，即保证栈非空
                          //可省去判断条件tt >= 0
    //求左边界
    int tt = 0; // tt表示栈顶
    q[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        while (h[q[tt]] >= h[i])
            tt--;     //往左找到第一个比h[i]小的位置为止
        l[i] = q[tt]; //记录第一个比h[i]小的矩形的位置
        q[++tt] = i;  //添加当前矩形到栈中
    }

    //求右边界
    tt = 0;
    q[0] = m + 1;
    for (int i = m; i; i--)
    {
        while (h[q[tt]] >= h[i])
            tt--;
        r[i] = q[tt];
        q[++tt] = i;
    }

    int res = 0;
    for (int i = 1; i <= m; i++)
        res = max(res, h[i] * (r[i] - l[i] - 1)); //更新矩形最大值

    return res;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == 'F')
                s[i][j] = s[i - 1][j] + 1; //累计F及其上方一共有几个F，该步见上图①
        }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, work(s[i])); //当下边界为i时，计算最大面积

    cout << res * 3 << endl;

    return 0;
}