#include <bits/stdc++.h>
using namespace std;

long long check(int num)
{
    int res = 0;
    while (num)
    {
        int j = num % 10;
        if (j == 2)
            res++;
        num /= 10;
    }
    return res;
}

int main()
{
    int L, R;
    cin >> L >> R;

    long long cnt = 0;
    for (int i = L; i <= R; i++)
    {
        cnt += check(i);
    }

    cout << cnt << '\n';

    return 0;
}