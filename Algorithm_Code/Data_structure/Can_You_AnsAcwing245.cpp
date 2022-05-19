#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=500010;
int w[N];//原始数组
struct Node{
    int l,r;//左右区间
    int lmax;//最大前缀和
    int rmax;//最后后缀和
    int tmax;//最大连续子段和
    int sum;//区间和
}tr[4*N];
int n,m;

void pushup(Node &u,Node &l,Node &r)//由子区间更新父区间
{
    u.sum=l.sum+r.sum;//区间总和

    //前缀和max(左子区间前缀和，左子区间总和+右子区间前缀和)
    u.lmax=max(l.lmax,l.sum+r.lmax);

    //后缀和 max(右子区间后缀和，右子区间总和+左子区间后缀和)
    u.rmax=max(r.rmax,r.sum+l.rmax);

    //区间最大值 max(左子区间前缀和，右子区间后缀和，(左子区间后缀和+右子区间前缀和))
    u.tmax=max(max(l.tmax,r.tmax),l.rmax+r.lmax);
}

void pushup(int u)//上面的为函数重载
{
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);//pushup:由子结点更新父节点
}

void build(int u,int l,int r)//建树
{
    tr[u].l=l,tr[u].r=r;
    if(l==r)
    {
        //初始化
        tr[u].lmax=w[l];
        tr[u].rmax=w[l];
        tr[u].sum=w[l];
        tr[u].tmax=w[l];
    }
    else
    {
        int mid=(l+r)>>1;//中间结点
        build(u<<1,l,mid);//递归建左树
        build(u<<1|1,mid+1,r);//递归建右树
        pushup(u);//更新信息
    }
}

void modify(int u,int x,int v)
{
    if(tr[u].l==x && tr[u].r==x)//叶结点:递归出口
    {
        //单一区间的情况
        tr[u].lmax=v;
        tr[u].rmax=v;
        tr[u].tmax=v;
        tr[u].sum=v;
    }
    else
    {
        int mid=(tr[u].r+tr[u].l)>>1;
        if(mid>=x) modify(u<<1,x,v);//x在左边：往左递归
        else modify(u<<1|1,x,v);//x在右边：往右递归
        pushup(u);//修改后更新信息
    }
}

//查询，由于存在跨左右子区间的情况，返回结构体类型，再用pushup计算结果
Node query(int u,int l,int r)
{
    //如果当前区间在查询区间内
    if(tr[u].l>=l && tr[u].r<=r) return tr[u];
    else
    {
        int mid=(tr[u].l+tr[u].r)>>1;
        if(mid>=r) return query(u<<1,l,r);
        else if(mid<l) return query(u<<1|1,l,r);
        else//有跨子区间的情况，处理左右子区间，再用pushup求结果
        {
            Node left=query(u<<1,l,r);
            Node right=query(u<<1|1,l,r);
            Node res;//res看作left和right的父区间
            pushup(res,left,right);
            return res;
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    build(1,1,n);
    
    while(m--)
    {
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(k==1)//查询x-y的最大连续子段和(保证了x<=y)
        {
            if(x>y) swap(x,y);
            printf("%d\n",query(1,x,y).tmax);
        }
        else modify(1,x,y);//将A[x]改成y
    }

    return 0;
}