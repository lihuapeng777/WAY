#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
typedef long long ll;
int maxd; //约数个数
int number;
int n; //读入的这个数
       //上一个数的次数,上一个数,以及约数的个数
void dfs(int u, int last, int p, int s)
{
    //如果当前的约数个数是大于最大的约数个数了
    //或者 是等于最大约数个数 并且 p小于number的话
    if (s > maxd || s == maxd and p < number)
    {
        maxd = s; //更新
        number = p;
    }

    if (u == 9)
        return; //表示已经枚举了所有情况,直接return

    //枚举次数:
    //次数的话从1次开始枚举,一直枚举到第last次,不能比上次多
    for (int i = 1; i <= last; i++)
    {
        // p乘上一个当前的指数,是否已经大于n了
        if ((ll)p * primes[u] > n)
            break; //大于n的话就直接break
        p *= primes[u];
        dfs(u + 1, i, p, s * (i + 1));
    }
}

int main()
{
    cin >> n;
    //(1)枚举到第几个质数了,初始状态是0
    //(2)质数的指数次数,最大次数是30
    //(3)这个数本身乘积,初始状态是1
    //(4)约数个数
    dfs(0, 30, 1, 1);

    cout << number << endl;

    return 0;
}