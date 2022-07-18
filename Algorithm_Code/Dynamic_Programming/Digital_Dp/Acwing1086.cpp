#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const ll P = 1e9 + 7;
int A[25];
ll pw[25];

struct node
{
    ll cnt, sum, sum2;
} f[20][7][7];

/*
f[I][sum][num]表示的状态为：
从第I位开始，最高位到第I位每位数字之和（%7）为sum，整个数字（%7）为num
如对于数123***，I=3时，sum=6，num=123

注：f存储的是在没有贴合上界的情况下
因为没有贴合上界，即剩下i位可以从00…00~99…99随便填，所以无论数a[]是多少都可以适用，不需要每次都重置f数组

在该状态下，结构体中的
cnt表示与7无关的数的个数
sum表示所有与7无关的数的和
sum2表示所有与7无关的数的平方和
*/

node dfs(int I, int sum, int num, bool lim)
{ //当前在第I位，最高位到第I位每位数字之和（%7）为sum，整个数字（%7）为num，lim表示是否贴合上界
    if (!I)
        return (node){sum && num, 0, 0}; //数字已填完，根据题目要求，若sum和num都不为0（不能被7整除），则算一种方案
    if (!lim && f[I][sum][num].cnt >= 0)
        return f[I][sum][num]; //记忆化，如果不贴合上界（!lim），直接放回记录过的答案

    int up = lim ? A[I] : 9; //第I位最大能填的数
    node ans = (node){0, 0, 0};
    for (int i = 0; i <= up; i++) //枚举第I位填的数
        if (i != 7)
        {
            node J = dfs(I - 1, (sum + i) % 7, (num * 10 + i) % 7, lim && i == up);
            ll B = i * pw[I - 1];    // B可以理解为当前层的基值，例如第I=5位填6，则B=60000
            (ans.cnt += J.cnt) %= P; //统计与7无关数出现次数
            (ans.sum += J.cnt * B + J.sum) %= P;

            /*
            统计所有与7无关数的和（用dfs（I-1）已经求出了所有无关数第I-1位到最后一位所组成的数之和，即J.sum，再加上第I位即可，即J.cnt*B）
            例如I=5，已知无关数有**61111，**62222，**63333（随便瞎写的几个数字）
            则B=60000，J.sum=1111+2222+3333，J.cnt=3，ans.sum=61111+62222+63333
            */

            (ans.sum2 += J.cnt * B % P * B % P + J.sum2 + 2 * J.sum % P * B % P) %= P;

            /*
            统计所有与7无关数第I位到最后一位所组成的数的平方和
            例如I=5，已知无关数有**61111，**62222，**63333（随便瞎写的几个数字）
            对于61111^2=(60000+1111)^2=(60000)^2+(1111)^2+2*60000*1111
            62222,63333同理
            则ans.sum2=61111^2+62222^2+63333^2
                      =3*(60000)^2 + (1111^2+2222^2+3333^2) + 2*60000*(1111+2222+3333)
                      =J.cnt*B*B   + J.sum2                 + 2*B*J.sum
            可以发现，我们用后I-1位的sum2即可推算出后I位的sum2
            */
        }
    if (!lim)
        f[I][sum][num] = ans; //记忆化：如果不贴合上界（!lim），则记录
    return ans;
}

ll solve(ll X)
{ //分解数位
    int len = 0;
    for (; X; X /= 10)
        A[++len] = X % 10;
    return dfs(len, 0, 0, 1).sum2;
}

int main()
{
    int T;
    cin >> T, pw[0] = 1, memset(f, -1, sizeof f);
    for (int i = 1; i < 21; i++)
        pw[i] = pw[i - 1] * 10 % P; //预处理10的幂

    for (ll L, R; T; T--)
        scanf("%lld%lld", &L, &R), printf("%lld\n", (solve(R) - solve(L - 1) + P) % P);
}