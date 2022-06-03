#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return d;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int x, y;
    exgcd(a, b, x, y);

    cout << (x % b + b) % b << endl;

    return 0;
}