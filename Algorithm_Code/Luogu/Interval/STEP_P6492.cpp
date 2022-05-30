/*https://www.luogu.com.cn/blog/xcg--123/ti-xie-p6492-coci2010-20116-step
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 8e5 + 5;
int n, m;
int S[N], H[N], L[N], R[N], len[N], ans[N];
void work(int node, int k) //将node节点的值赋值为k,并更新一下该点信息
{
    ans[node] = S[node] = H[node] = 1;
    L[node] = R[node] = k;
}
void pushup(int node)
{
    if (R[node << 1] ^ L[node << 1 | 1]) //如果左区间的右端点和右区间的左端点不同
    {
        ans[node] = H[node << 1] + S[node << 1 | 1];    //考虑两端合并后的符合条件的区间长度
        ans[node] = max(ans[node], ans[node << 1]);     //与左区间的进行比较
        ans[node] = max(ans[node], ans[node << 1 | 1]); //与右区间的进行比较
    }
    else
        ans[node] = max(ans[node << 1], ans[node << 1 | 1]); //否则只用考虑左右区间中最长的区间
    L[node] = L[node << 1];
    R[node] = R[node << 1 | 1]; // L和R数组的维护显而易见
    if (S[node << 1] == len[node << 1] && R[node << 1] ^ L[node << 1 | 1])
        S[node] = S[node << 1] + S[node << 1 | 1]; //左区间的S包含整个区间并且左区间的右端点与右区间的左端点不同,则两个区间的S合并成大区间的S
    else
        S[node] = S[node << 1]; //否则就继承左区间的S
    if (H[node << 1 | 1] == len[node << 1 | 1] && R[node << 1] ^ L[node << 1 | 1])
        H[node] = H[node << 1 | 1] + H[node << 1]; //右区间的H包含整个区间并且左区间的右端点与右区间的左端点不同,则两个区间的H合并成大区间的H
    else
        H[node] = H[node << 1 | 1]; //否则就继承右区间的H
}
void build(int node, int l, int r)
{
    len[node] = r - l + 1; //区间长度
    if (l == r)            //递归到了叶子节点
    {
        work(node, 0); //将该点赋值0,并更新一下该点信息
        return;
    }
    int mid = (l + r) / 2;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    pushup(node);
}
void change(int node, int l, int r, int x)
{
    if (l == r) //递归到了叶子节点
    {
        work(node, !L[node]); //将该节点赋值为!L[node],从而达到0变成1,1变成0的效果
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        change(node << 1, l, mid, x);
    else
        change(node << 1 | 1, mid + 1, r, x);
    pushup(node);
}
int main()
{
    scanf("%d %d", &n, &m);
    build(1, 1, n); //建树
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        change(1, 1, n, x);     //单点修改
        printf("%d\n", ans[1]); //每次要输出最长的符合条件的区间
    }
    return 0;
}*/
// https://www.luogu.com.cn/blog/LOVENUTMEGFOREVER/p6492-coci2010-20116-step-ti-xie-xian-duan-shu-zuo-you-qian-zhui-ou-j
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 3e5 + 10;
int n, m;
int op;
int a[N];
int sum[N << 2];  //对应一个区间的最大01连续子串
int lsum[N << 2]; //一个区间前缀最大01连续子串
int rsum[N << 2]; //一个区间后缀最大01连续子串

void pushup(int p, int l, int r)
{
    int mid = l + r >> 1;  //求左儿子的右端点,推之mid+1是右儿子的左端点
    int L = (mid - l + 1); //左孩子的长
    int R = r - mid;       //右孩子的长

    //先全部都从左右孩子身上扒他们的最值，保证我们操作的正确性
    lsum[p] = lsum[p << 1];
    rsum[p] = rsum[p << 1 | 1];
    sum[p] = max(sum[p << 1], sum[p << 1 | 1]);

    if (a[mid] != a[mid + 1]) //考虑连接情况
    {
        sum[p] = max(sum[p], rsum[p << 1] + lsum[p << 1 | 1]); //左区间的后缀+右区间的前缀
        //如果等于了左孩子的长度，则说明我们大区间的max前缀01需要更大的空间，那就从右儿子那里扒他的max前缀01
        if (sum[p << 1] == L)
            lsum[p] = L + lsum[p << 1 | 1];
        //如果等于了右孩子的长度 则说明我们大区间的max后缀01需要更大的空间，那就从左儿子那里扒他的max后缀01
        if (sum[p << 1 | 1] == R)
            rsum[p] = R + rsum[p << 1];
    }
}

void build(int p, int l, int r)
{
    sum[p] = lsum[p] = rsum[p] = 1; //赋初始值
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p, l, r);
}

void update(int p, int l, int r, int idx)
{
    if (l == r and l == idx) //找到了需要更改的节点
    {
        a[l] ^= 1;
        return;
    }
    int mid = l + r >> 1;
    if (idx <= mid)
        update(p << 1, l, mid, idx);
    else
        update(p << 1 | 1, mid + 1, r, idx);
    pushup(p, l, r);
}

int query() { return sum[1]; } //直接return最大区间的sum值

int main()
{
    scanf("%d %d", &n, &m);
    build(1, 1, n);

    while (m--)
    {
        scanf("%d", &op);
        update(1, 1, n, op);
        printf("%d\n", query());
    }

    return 0;
}