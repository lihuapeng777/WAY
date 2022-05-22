//树状数组
// Tree array
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int tr[N];
int n;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        add(i, a[i]);

    while (1)
    {
        printf("1~n的前缀和数组为：\n");
        for (int i = 1; i <= n; i++)
            cout << sum(i) << " ";

        cout << endl;
        printf("1~n的原数组为：\n");
        for (int i = 1; i <= n; i++)
            cout << sum(i) - sum(i - 1) << " ";
        break;
    }

    return 0;
}
