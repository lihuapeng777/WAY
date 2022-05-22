#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 2e4 + 10;

int n, m;
int p[N], d[N];
unordered_map<int, int> S;

int get(int x) //无序离散化
{
    if (S.count(x) == 0)
        S[x] = ++n;
    return S[x];
}

int find(int x)
{
    if (p[x] != x)
    {
        int root = find(p[x]);
        d[x] ^= d[p[x]];
        /*路径压缩时,对x到树根路径上的所有边权做(xor)运算
        即可得到x与树根的奇偶性关系
        */
        p[x] = root;
    }
    return p[x];
}

int main()
{
    cin >> n >> m; //序列长度,问题的次数
    n = 0;         //没用

    for (int i = 0; i < N; i++)
        p[i] = i; //并查集的初始化

    int res = m; //如果无矛盾, 输出问题数量, 初始的时候为m
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        string type;
        cin >> a >> b >> type;
        //用离散化把问题中的两个整数L-1和R 缩小到等价的1~2M以内的范围
        //因为m个问题,每个问题最多涉及到2个数,因此为2*M
        a = get(a - 1), b = get(b); // S[a-1], S[b]

        // t作为一个标记
        int t = 0; //表示区间S[a-1]和S[b]之间的1的个数为偶数个
        //那么就有 S[a-1] 与 S[b] 的 奇偶性相同

        if (type == "odd")
            t = 1; //奇数则反之

        int pa = find(a); //路径压缩
        int pb = find(b); //维护奇偶性看函数

        if (pa == pb) //有且仅有在同一个集合中才可以判断是否有冲突
        {
            // d数组的定义：
            //边权d[x]=0,表示x与p[x]的奇偶性相同
            //边权d[x]=1,表示x与p[x]的奇偶性不同
            //(1)t=0：区间偶数情况：即 a 与 b 奇偶性相同
            //那么则有 从a->root 的 奇偶性 d[a]
            //和 b->root的 奇偶性 d[b]
            //则必有 d[a]^d[b]==0(偶数即可：不过为了方便取了0)
            if ((d[a] ^ d[b]) != t)
            {
                res = i - 1;
                break;
            }
        }
        else // a b 不在同一个集合中,则合并树
        {
            p[pa] = pb;              //合并各自的root节点
            d[pa] = d[a] ^ d[b] ^ t; // a->b的root节点的距离为该表达式：题解第一的图
        }
    }
    cout << res << endl;
}