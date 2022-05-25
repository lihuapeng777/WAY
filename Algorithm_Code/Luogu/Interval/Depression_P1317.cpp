#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int i = 1;
    int cnt = 0;
    while (i <= n)
    {
        while (a[i] <= a[i - 1] && i <= n)
            i++; //下降段
        while (a[i] >= a[i - 1] && i <= n)
            i++; //上升段
        cnt++;   //先下降后上升就证明之间存在一片洼地
    }

    cout << cnt - 2 << endl; //去除头尾

    return 0;
}