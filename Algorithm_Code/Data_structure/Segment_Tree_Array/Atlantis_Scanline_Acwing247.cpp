#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector> //离散化
using namespace std;

const int N = 100010;

// y总的坐标是笛卡尔坐标系
/*
y轴
\
\
\
-----------x轴*/
//对y轴建立线段树维护cnt和len两个值

struct segment //用来存储线段信息
{
    double x, y1, y2; //
    int d;            //区分它是该矩阵前面的线段还是后面的线段
    bool operator<(const segment &t) const
    {
        return x < t.x;
    }
} seg[N * 2]; //每个矩阵需要两个线段

//线段树的每个节点 保存的为线段，0号点为y[0]~y[1]，以此类推
struct Node //对y轴建立线段树
{
    int l, r;
    int cnt;    //记录这段区间出现了几次
    double len; //记录这段区间的长度：即线段长度
} tr[N * 8];    //由于线段2倍，所有需要8倍空间

vector<double> ys; //用于离散化
int n;

int find(double y)
{
    //需要返回vector 中第一个 >= y的数的下标
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int u)
{
    //例如：假设tr[1].l = 0,tr[1].r = 1;
    //      y[0]为ys[0]到ys[1]的距离, y[1]为ys[1]到ys[2]的距离
    //      tr[1].len 等于y[0]到y[1]的距离
    //      y[1] = ys[tr[1].r + 1] = ys[2], y[0] = ys[tr[1].l] = ys[0]
    if (tr[u].cnt) //表示整个区间都被覆盖，该段长度就为右端点 + 1后在ys中的值 - 左端点在ys中的值
        tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    // 借鉴而来
    // 如果tr[u].cnt等于0其实有两种情况:
    // 1. 完全覆盖. 这种情况由modify的第一个if进入.
    //    这时下面其实等价于把"由完整的l, r段贡献给len的部分清除掉",
    //    而留下其他可能存在的子区间段对len的贡献
    // 2. 不完全覆盖, 这种情况由modify的else最后一行进入.
    //    表示区间并不是完全被覆盖，可能有部分被覆盖,所以要通过儿子的信息来更新
    else if (tr[u].l != tr[u].r)
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    else
        tr[u].len = 0; //表示为叶子节点且该线段没被覆盖，为无用线段，长度变为0
}

//表示从线段树中l点->r点出现次数+d
void modify(int u, int l, int r, int d)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].cnt += d; //该区间出现次数+d
        pushup(u);      //更新该节点的len
    }
    else
    {
        int mid = tr[u].r + tr[u].l >> 1;
        if (l <= mid)
            modify(u << 1, l, r, d); //左边存在点
        if (r > mid)
            modify(u << 1 | 1, l, r, d); //右边存在点
        pushup(u);                       //进行更新
    }
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0}; //初始化cnt,len均为 0

    if (l != r) //不是叶节点才需要递归建树
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        //后面都为0,不需要更新len
    }
}

int main()
{
    int T = 1;
    while (scanf("%d", &n), n) //多组输入
    {
        ys.clear();                 //清空之前存的离散化
        int j = 0;                  //一共j条线段
        for (int i = 0; i < n; i++) //处理输入
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[j++] = {x1, y1, y2, 1};  //前面的线段
            seg[j++] = {x2, y1, y2, -1}; //后面的线段
            ys.push_back(y1);
            ys.push_back(y2); // y轴出现过的那些点
        }

        sort(seg, seg + j); //线段按x排序:

        // ys 存的是从 y轴的点 y1,y2......
        sort(ys.begin(), ys.end());                       //有序离散化
        ys.erase(unique(ys.begin(), ys.end()), ys.end()); //离散化去重

        //例子：假设现在有三个不同的y轴点,分为两个线段
        // y[0] ~ y[1],y[1] ~ y[2];
        //此时ys.size()为3,ys.size() - 2 为 1;
        //此时为 build(1, 0, 1);
        //有两个点0 和 1,线段树中0号点为y[0] ~ y[1],1号点为y[1] ~ y[2];
        build(1, 0, ys.size() - 2);

        double res = 0;

        for (int i = 0; i < j; i++) //遍历所有线段
        {
            //根节点的长度即为此时有效线段长度,再*x轴长度即为面积
            if (i)
                res += tr[1].len * (seg[i].x - seg[i - 1].x);
            //处理以下该线段的信息，是加上该线段还是消去
            //例子：假设进行modify(1,find(10),find(15)-1,1)
            //  假设 find(10)=0,find(15)=1
            //  此时modify(1,0,0,1)
            //  表示线段树中0号点出现次数+1
            //  而线段树中0号点刚好为线段(10~15)
            //  这就是为什么要进行find(seg[i].y2)-1的这个-1操作
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].d);
        }
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2lf\n\n", res);
    }

    return 0;
}