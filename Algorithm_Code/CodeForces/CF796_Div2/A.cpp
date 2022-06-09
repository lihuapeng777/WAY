/*
题目概述：给定一个数字x,让你求出一个最小的正整数y,使得x & y 和 x ^ y 的结果都大于 0
贪心：对于 x & y来说 只要找到 第一次出现1的位即可 ---->lowbit()
对于 x ^ y 来说：如果 x 是 2的次幂,那么需要特判,因为 如果y为2的次幂，那么y的位(在第一次出现1的位的右边均为0)
那么为了使得这个y值最小，我们需要添加一个 1 使得满足 x ^ y >0
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long lowbit(long long x) //第一次出现1的位
{
    return x & -x;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            cout << 3 << endl;
        }
        else
        {
            if ((n & (n - 1)) == 0) //判断是否为2的次幂O(logN)  O（N)
            {
                cout << lowbit(n) + 1 << endl;
            }
            else
                cout << lowbit(n) << endl;
        }
    }

    return 0;
}