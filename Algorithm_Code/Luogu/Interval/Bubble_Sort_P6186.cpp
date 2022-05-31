// https : // www.luogu.com.cn/blog/85514/solution-p6186
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int input[N];  //输入地原数组
int before[N]; //记录第i位数前面比它的数的个数
int record[N]; //答案
int n;
long long tree[N]; //树上差分

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int x, long long val)
{
    for (; x <= n; x += lowbit(x))
        tree[x] += val;
    return;
}

long long sum(int x)
{
    long long res = 0;
    for (; x > 0; x -= lowbit(x))
        res += tree[x];
    return res;
}

int main()
{
    int m;
    scanf("%d%d", &n, &m); //数组长度/操作次数

    long long tot = 0; //先记录初始状态下的逆序对数量

    for (int i = 0; i < n; i++) //输入数组元素
    {
        scanf("%d", input + i);        // input[i]
        before[i] = i - sum(input[i]); //记录比它大的数字数量=当前元素个数-这个元素前比它小的元素个数
        tot += before[i];              //最开始tot记录初始的答案:记录初始所有逆序对的数量
        record[before[i]]++;           //桶，record[i]=前面有i个数字比它大的数字的数量
        add(input[i], 1);              //树状数组作桶
    }
    // 4  1  3  5  2
    memset(tree, 0, sizeof(tree)); //清空
    add(1, tot);                   //实现差分，先把序列总逆序对数量放在最前面
    tot = 0;

    for (int i = 0; i < n; ++i)
    {
        tot += record[i]; //每次tot记录的是前面有小于等于i个数字比它大的数字的数量
        //则n-tot即为前面有大于i个数字比它大的数字的数量
        add(i + 2, -(n - tot)); //实现差分，在这一个位置会有n-tot个数字逆序对数减1
                                //由于下标问题，i必须+2，这样当i=0时就会储存在第2位，而第1位是放总逆序对数的
    }

    for (int i = 0, opt, x; i < m; i++)
    {
        scanf("%d%d", &opt, &x);
        x = min(x, n - 1); //对opt=2的情况进行优化
        if (opt == 1)      //交换x,x+1两个下标对应的值
        {
            x--; //下标对应
            if (input[x] < input[x + 1])
            {
                swap(input[x], input[x + 1]);
                swap(before[x], before[x + 1]);
                add(1, 1);                  //逆序对总数量增加1
                add(before[x + 1] + 2, -1); //由于before[x+1]增加了，所以在原before[x+1]轮时也可以使逆序对-1，所以记录-1
                before[x + 1]++;            // input[x]交换到x+1位上后，前面比它大的数量增加了1
            }
            else
            {
                swap(input[x], input[x + 1]);
                swap(before[x], before[x + 1]);
                add(1, -1);            //逆序对总数量减少1
                before[x]--;           // input[x+1]交换到x位上后，前面的比它大的数量减少了1
                add(before[x] + 2, 1); //由于before[x]减少了，所以在原before[x]轮时无法使逆序对减少，所以记录1
            }
        }
        else
            printf("%lld\n", sum(x + 1)); //直接输出答案
    }
    return 0;
}