/*
a:青蛙a的起点
b:青蛙b的起点
m:青蛙a一次能跳多远
n:青蛙b一次能跳多远
L:一圈的距离
(b-a):a要追b多少米
(m-n):每跳一次，a能追b多少米

x是总共跳了多少次
y是a追b不一定会在一圈内追完，而是追了y圈
          (m - n)*x = b - a + y*L
    (m - n)*x - y*L = b - a
    ———————       —   —————
    已知         已知 已知

扩展欧几里得求的是
    ax+by=d
    a已知，b已知，d是a和b的最大公约数，求x，y
因此把上式的a替换乘(m-n),b替换成L。
式子变成(m-n)*x+(-y)*L=d
如果(b-a)%d不等于0，两只青蛙永远不会碰面
如果(b-a)%d等于零，把(m-n)*x+(-y)*L=d扩大(b-a)/d倍后，x就是结果。
*/

#include <iostream>
using namespace std;

typedef long long ll;

int exgcd(int a, int b, ll &x, ll &y)
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
    int a, b, m, n, l;
    cin >> a >> b >> m >> n >> l;

    ll x = 0, y = 0;
    int d = exgcd(m - n, l, x, y);

    if ((b - a) % d)
        puts("Impossible");
    else
    {
        x *= (b - a) / d; //按照比例放大
        /*
        通解的单位变元？不知道怎么叫比较合适。
您先搞清楚一点，exgcd解出来的那么一组x,y并不是我们所求的最小正整数解，它甚至可能是一个负的不知道哪里去的一个数。它们仅仅是一组解。而关于通解，假设我们解出一组解x0,y0，方程是ax+by=c，通解就是
x=x0+k b/gcd(a,b)，kk是任意的一个整数，t就是后面那一坨，就是b/gcd(a,b)。
所以我们要求出这个单位变量，从而得到我们所需要的最小正整数解。
        */
        ll t = abs(l / d);
        cout << (x % t + t) % t << endl;
    }

    return 0;
}