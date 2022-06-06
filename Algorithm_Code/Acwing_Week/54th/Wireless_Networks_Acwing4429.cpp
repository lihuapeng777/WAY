//参考资料 https://www.acwing.com/video/3931/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2010;
int n;
PII s1, s2;
PII q[N];

ll dist(PII a, PII b) //计算a->b的距离的平方
{
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool cmp(PII a, PII b) //距离重载比较函数
{
    return dist(s1, a) < dist(s1, b);
}

int main()
{
    cin >> n >> s1.x >> s1.y >> s2.x >> s2.y;
    for (int i = 0; i < n; i++)
        cin >> q[i].x >> q[i].y;

    sort(q, q + n, cmp); //对奶牛到 s1的距离进行升序排序

    ll res = 1e18, r2 = 0;

    for (int i = n - 1; i >= 0; i--) //距离从大 -> 小 枚举
    {
        res = min(res, dist(q[i], s1) + r2); //计算改该点奶牛到 s1的距离然后+ r2
        r2 = max(r2, dist(q[i], s2));        // r2取 逆向枚举过程中的最大值
    }
    //当基站2 覆盖了所有的点的特殊情况
    res = min(res, r2);
    printf("%lld\n", res);

    return 0;
}