#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000010;
int n;
int a[N], cnt[N], s[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++; // a[i]的个数
    }

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j += i)
            s[j] += cnt[i];

    for (int i = 0; i < n; i++)
        cout << s[a[i]] - 1 << endl;

    return 0;
}