//建树
// 笔记链接：https://www.acwing.com/blog/content/372/
#include <iostream>
using namespace std;

const int N = 1000;
int a[] = {1, 3, 5, 7, 9, 11};
int Size = 6;
int tree[N];

//建立范围为a[start]~a[end]
void build(int a[], int tree[], int node /*当前节点*/, int start, int end)
{
    //递归边界(即遇到叶子节点时)
    if (start == end)
        tree[node] = a[start];
    else
    {
        //将建立的区间分成两半
        int mid = start + end >> 1;

        int left = 2 * node + 1;  //左子节点的下标
        int right = 2 * node + 2; //右节点的下标

        //求出左子节点的值
        build(a, tree, left, start, mid);
        build(a, tree, right, mid + 1, end);

        tree[node] = tree[left] + tree[right];
    }
}

void modify(int a[], int tree[], int node, int start, int end, int x, int val)
{
    //找到a[x],并修改
    if (start == end)
    {
        a[x] = val;
        tree[node] = val;
    }
    else
    {
        int mid = start + end >> 1;

        int left = 2 * node + 1;
        int right = 2 * node + 2;

        if (x >= start && x <= mid) //如果x在左分支
        {
            modify(a, tree, left, start, mid, x, val);
        }
        else //如果x在右分支
        {
            modify(a, tree, right, mid + 1, end, x, val);
        }
        tree[node] = tree[left] + tree[right];
    }
}

int query(int a[], int tree[], int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
        return 0;

    //若目标区间包含当时区间,直接返回节点值
    else if (l <= start && end <= r)
    {
        return tree[node];
    }
    else
    {
        int mid = start + end >> 1;

        int left = 2 * node + 1;
        int right = 2 * node + 2;

        int sum_left = query(a, tree, left, start, mid, l, r);
        int sum_right = query(a, tree, right, mid + 1, end, l, r);

        return sum_left + sum_right;
    }
}

int main()
{
    //从根节点(即节点0)开始建树,建树范围为a[0]~a[size-1]
    build(a, tree, 0, 0, Size - 1);

    for (int i = 0; i <= 14; i++)
        printf("tree[%d]=%d\n", i, tree[i]);
    system("pause");
}