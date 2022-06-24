#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
char str[N];
int cnt = 0;

void show(int n)
{
    int a = 0, b = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (str[i] == 'W')
            a++;
        if (str[i] == 'L')
            b++;

        if ((a >= n || b >= n) and abs(a - b) >= 2)
        {
            cout << a << ":" << b << '\n';
            a = b = 0;
        }
    }
    //新的一轮刚开始或者上一局没有打完
    cout << a << ":" << b << '\n';
}

int main()
{
    char ch;
    while (cin >> ch, ch != 'E')
    {
        if (ch == 'W' || ch == 'L')
        {
            str[cnt++] = ch;
        }
    }

    show(11);
    puts("");
    show(21);

    return 0;
}