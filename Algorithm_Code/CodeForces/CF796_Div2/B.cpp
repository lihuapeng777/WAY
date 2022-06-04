/*
题目大意：给定一个n,接下来有n个元素 a1 a2 a3 ....an
有两个操作：
合并：即取 两个元素 进行相加 变成一个新的元素
减少：取 一个元素 /2 ，此时 元素值变为 /2

让你求出 将序列 a，全部变为奇数的 最小操作数
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int temp(int n) //记录一直/2，能变为奇数的操作数
{
    int cnt = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        cnt++;
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        vector<int> v;

        int e = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0) //如果为偶数
            {
                e++;               //记录原序列的偶数个数
                v.push_back(a[i]); //偶数序列
            }
        }

        if (e == 0)
            cout << "0" << endl;
        else if (e < n) //若干偶数+若干奇数==1个偶数+若干奇数
            cout << e << endl;
        else //偶数个数等于 原序列个数：即原序列都是偶数
        {
            int l = v.size(); //获取偶数的个数
            int minv = INT_MAX;
            int s = 0;
            for (int i = 0; i < l; i++)
            {
                s += temp(v[i]);              //获取变为奇数的总次数
                minv = min(minv, temp(v[i])); //记录序列中 元素 变为奇数的最小次数
            }
            //将其化为：一个最小操作数的由（偶数->奇数）的数+（剩余的所有偶数）==1个奇数
            int z = e - 1 + minv; // z=原序列的偶数个数-1 + 变为奇数的最小次数
            cout << min(z, s) << endl;
        }
    }

    return 0;
}